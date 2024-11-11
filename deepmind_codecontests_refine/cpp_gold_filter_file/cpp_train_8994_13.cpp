#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n, m, a;
  cin >> n >> m;
  vector<int> bad;
  for (int i = 0; i < m; i++) {
    cin >> a;
    bad.push_back(a);
  }
  sort(bad.begin(), bad.end());
  if (m > 0) {
    if (bad[0] == 1 || bad[m - 1] == n) {
      cout << "NO\n";
      return 0;
    } else if (m >= 3) {
      for (int i = 0; i < m - 2; i++) {
        if (bad[i] + 1 == bad[i + 1] && bad[i] + 2 == bad[i + 2]) {
          cout << "NO";
          return 0;
        }
      }
    }
  }
  cout << "YES";
  return 0;
}
