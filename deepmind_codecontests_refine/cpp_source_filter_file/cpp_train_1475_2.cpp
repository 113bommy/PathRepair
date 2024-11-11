#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, tmp, ans = 1;
  vector<int> sorted;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> tmp;
    sorted.push_back(tmp);
  }
  sort(sorted.begin(), sorted.end());
  for (int i = 0; i < sorted.size(); i++) {
    if (sorted[i] >= ans) {
      ans++;
    }
  }
  cout << ans;
  return 0;
}
