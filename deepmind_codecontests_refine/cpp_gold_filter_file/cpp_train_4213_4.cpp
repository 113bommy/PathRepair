#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - '0', c = getchar();
  return x * f;
}
inline long long readll() {
  char c = getchar();
  long long x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - '0', c = getchar();
  return x * f;
}
const double PI = acos((double)-1.0);
const double EPS = 1e-6;
const int INFINT = 0x3f3f3f3f;
const long long INFLL = 0x3f3f3f3f3f3f3f3f;
const long long MOD1 = (long long)(1e9 + 7), MOD2 = 998244353;
const int maxn = 100100;
int d[maxn];
string str, s[maxn];
int n;
long long w[20], num[20];
int main() {
  std::ios::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> str >> n;
  for (register int i = 1; i <= n; ++i) {
    cin >> s[i];
    d[i] = s[i][0] - '0';
  }
  for (register int i = 0; i < 10; ++i) num[i] = i, w[i] = 10;
  long long tw, tnum;
  register int ch;
  for (register int i = n; i > 0; --i) {
    register int len = s[i].size();
    tw = 1;
    tnum = 0;
    for (register int j = 3; j < len; ++j) {
      ch = s[i][j] - '0';
      tnum = (tnum * w[ch] + num[ch]) % MOD1;
      tw = (tw * w[ch]) % MOD1;
    }
    num[d[i]] = tnum;
    w[d[i]] = tw;
  }
  int len = str.size();
  long long ans = 0;
  for (register int i = 0; i < len; ++i) {
    ch = str[i] - '0';
    ans = (ans * w[ch] + num[ch]) % MOD1;
  }
  cout << ans << '\n';
  return 0;
}
