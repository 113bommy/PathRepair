#include <bits/stdc++.h>
using namespace std;
bool comparator(pair<int, int> &ai, pair<int, int> &bi) {
  return ai.second < bi.second;
}
int main() {
  int n, b;
  cin >> n >> b;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int result = b;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      result = max(result, b + (b / a[i]) * (a[j] - a[i]));
    }
  }
  cout << result << endl;
  return 0;
}
