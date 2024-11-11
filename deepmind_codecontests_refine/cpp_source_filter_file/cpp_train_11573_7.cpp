#include <bits/stdc++.h>
#pragma comment(linker, "/stack:64000000")
using namespace std;
template <typename first>
inline first abs(const first& a) {
  return a < 0 ? -a : a;
}
template <typename first>
inline first sqr(const first& a) {
  return a * a;
}
const long double PI = 3.1415926535897932384626433832795;
const long double EPS = 1e-9;
const int INF = 1000 * 1000 * 1000;
const int N = 500 * 1000 + 13;
int n, m;
vector<string> f;
char buf[N];
inline int verPar(char c) { return c == '1' || c == '4'; }
inline int horPar(char c) { return c == '1' || c == '3'; }
inline bool checkHor(char c1, char c2, int par) {
  return horPar(c1) ^ horPar(c2) == par;
}
inline bool checkVer(char c1, char c2, int par) {
  return verPar(c1) ^ verPar(c2) == par;
}
inline bool bad() {
  for (int i = 0; i < int(n); i++) {
    int idx = -1;
    for (int j = 0; j < int(m); j++)
      if (f[i][j] != '.')
        if (idx == -1)
          idx = j;
        else if (!checkHor(f[i][idx], f[i][j], (j - idx) % 2))
          return true;
  }
  for (int j = 0; j < int(m); j++) {
    int idx = -1;
    for (int i = 0; i < int(n); i++)
      if (f[i][j] != '.')
        if (idx == -1)
          idx = i;
        else if (!checkVer(f[idx][j], f[i][j], (i - idx) % 2))
          return true;
  }
  return false;
}
int main() {
  cin >> n >> m;
  gets(buf);
  for (int i = 0; i < int(n); i++) f.push_back(string(gets(buf)));
  if (bad()) {
    puts("0");
    return 0;
  }
  int cnt = 0;
  for (int i = 0; i < int(n); i++) {
    bool ok = true;
    for (int j = 0; j < int(m); j++)
      if (f[i][j] != '.') ok = false;
    cnt += ok;
  }
  for (int j = 0; j < int(m); j++) {
    bool ok = true;
    for (int i = 0; i < int(n); i++)
      if (f[i][j] != '.') ok = false;
    cnt += ok;
  }
  const int mod = 1000 * 1000 + 3;
  int ans = 1;
  for (int i = 0; i < int(cnt); i++) ans = (ans * 2) % mod;
  cout << ans << endl;
  return 0;
}
