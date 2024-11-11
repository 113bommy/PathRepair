#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);
template <typename T>
inline T sqr(T n) {
  return (n * n);
}
int main() {
  ios_base ::sync_with_stdio(false);
  string s;
  getline(cin, s);
  int n = s.size();
  bool flag = true;
  int pos = -1;
  for (int i = 1; i < n && flag; i++)
    if (s[i] != s[0]) flag = false;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'M') {
      pos = i;
      break;
    }
  }
  if (flag) {
    cout << 0;
    return 0;
  }
  int ans = -1;
  if (s[0] == 'F') ans = 0;
  int cnt = pos;
  for (int i = pos + 1; i < n; i++) {
    if (s[i] == 'F') {
      ans = max(ans + 1, i - cnt);
      cnt++;
    }
  }
  cout << ans;
  return 0;
}
