#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> v(N);
  for (int &i : v) cin >> i;
  sort(v.begin(), v.end());
  for (int i = 0; i < N - 1; i++) {
    if (v[i + 1] < 2 * v[i] && v[i + 1] > v[i]) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}
