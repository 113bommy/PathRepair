#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lli = long long int;
using ld = long double;
const int N = 2e5 + 5, inf = 2e9;
string s;
int solve(char fi, char se) {
  int n = s.size() - 1;
  string tem = s;
  int ret = 0;
  for (int i = n; i >= 0; i--) {
    if (tem[i] == se) {
      for (int j = i; j <= n; j++) swap(tem[j], tem[j + 1]);
      break;
    }
    ret++;
  }
  if (ret == n + 1) return inf;
  int ret2 = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (tem[i] == fi) {
      for (int j = i; j < n; j++) swap(tem[j], tem[j + 1]);
      break;
    }
    ret++;
  }
  if (ret2 == n) return inf;
  int ret3 = 0;
  if (tem[0] == '0') {
    for (int i = 1; i < n - 1; i++) {
      if (tem[i] != '0') {
        ret3 = i;
        break;
      }
    }
    if (ret3 == 0) return 1e9;
  }
  return ret + ret2 + ret3;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  int ch1 = solve('0', '0');
  int ch2 = solve('2', '5');
  int ch3 = solve('5', '0');
  int ch4 = solve('7', '5');
  int ans = min({ch1, ch2, ch3, ch4});
  ans == inf ? cout << -1 << "\n" : cout << ans << "\n";
  return 0;
}
