#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e6 + 3;
long long qp(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) (ret *= a) %= mod;
    (a *= a) %= mod;
    b >>= 1;
  }
  return ret;
}
string mp[500050];
bool cng[500050];
bool chk(int id, string s) {
  int l = s.length();
  for (int i = 0; i < l; ++i) cng[i] = 0;
  if (!id) {
    for (int i = 0; i < l; ++i)
      if (isdigit(s[i]) && !cng[i]) {
        int t = (s[i] - '1') / 2;
        if (!t) {
          if (!i) continue;
          int tp = isdigit(s[i - 1]) ? (s[i - 1] - '1') / 2 : -1;
          if (tp == t) return 0;
          cng[i - 1] = 1;
          s[i - 1] = '3';
        } else {
          if (i == l - 1) continue;
          int tp = isdigit(s[i + 1]) ? (s[i + 1] - '1') / 2 : -1;
          if (tp == t) return 0;
          s[i + 1] = '2';
          cng[i + 1] = 1;
        }
      }
  } else {
    for (int i = 0; i < l; ++i)
      if (isdigit(s[i]) && !cng[i]) {
        int t = (s[i] - '1');
        t = (t == 1 || t == 2);
        if (!t) {
          if (!i) continue;
          int tp = isdigit(s[i - 1]) ? (s[i - 1] - '1') : -1;
          tp = tp != -1 ? (tp == 1 || tp == 2) : tp;
          if (tp == t) return 0;
          s[i - 1] = '3';
          cng[i - 1] = 1;
        } else {
          if (i == l - 1) continue;
          int tp = isdigit(s[i + 1]) ? (s[i + 1] - '1') : -1;
          tp = tp != -1 ? (tp == 1 || tp == 2) : tp;
          if (tp == t) return 0;
          s[i + 1] = '1';
          cng[i + 1] = 1;
        }
      }
  }
  int r = 0;
  for (int i = 0; i < l; i = r) {
    r = i + 1;
    if (!isdigit(s[i])) continue;
    while (r < l && s[r] == '.') r++;
    if (r < l && (r - i) % 2 == 0) return 0;
  }
  return 1;
}
int main() {
  int n, m;
  int cnt = 0;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> mp[i];
  for (int i = 0; i < n; ++i) {
    bool can = 1;
    for (int j = 0; j < m; ++j)
      if (isdigit(mp[i][j])) {
        if (!chk(0, mp[i])) return 0 * puts("0");
        can = 0;
        break;
      }
    cnt += can;
  }
  for (int i = 0; i < m; ++i) {
    bool can = 1;
    for (int j = 0; j < n; ++j)
      if (isdigit(mp[j][i])) {
        string s = "";
        for (int k = 0; k < n; ++k) s += mp[k][i];
        if (!chk(1, s)) return 0 * puts("0");
        can = 0;
        break;
      }
    cnt += can;
  }
  cout << qp(2, cnt) << ('\n');
}
