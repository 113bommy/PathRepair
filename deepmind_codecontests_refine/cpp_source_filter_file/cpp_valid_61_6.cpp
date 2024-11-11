#include <bits/stdc++.h>
using namespace std;
const long double pai = 3.1415926536;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const unsigned long long bas = 2333;
const int MAXN = 6e5 + 10;
const long long mod = 998244353;
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
template <typename T>
void rd(T &x) {
  char ch = getchar();
  x = 0;
  int f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
template <typename T>
inline void wt(T a) {
  if (a < 0) putchar('-'), a = -a;
  if (a >= 10) wt(a / 10);
  putchar(a % 10 + 48);
}
char s[110];
int main() {
  ios::sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--) {
    int n, p = 0;
    cin >> n >> s + 1;
    for (int i = 1; i <= n; ++i) {
      if (s[i] == '?') {
        p = i;
        break;
      }
    }
    if (!p) {
      for (int i = 1; i <= n; ++i) {
        if (i & 1)
          s[i] = 'R';
        else
          s[i] = 'B';
      }
    } else {
      if (p & 1) {
        if (s[p] == 'B')
          s[0] = 'R';
        else
          s[0] = 'B';
      } else
        s[0] = s[p];
      for (int i = 1; i <= n; ++i) {
        if (s[i] == '?') {
          if (s[i - 1] == 'R')
            s[i] = 'B';
          else
            s[i] = 'R';
        }
      }
    }
    cout << s + 1 << '\n';
  }
}
