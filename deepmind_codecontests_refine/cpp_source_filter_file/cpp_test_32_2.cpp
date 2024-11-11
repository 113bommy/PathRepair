#include <bits/stdc++.h>
using namespace std;
int T, n, a[100005], f[100005][400];
long long s[100005];
struct FastIO {
  static const int S = 1048576;
  char buf[S], *L, *R;
  int stk[20], Top;
  ~FastIO() { clear(); }
  inline char nc() {
    return L == R && (R = (L = buf) + fread(buf, 1, S, stdin), L == R) ? EOF
                                                                       : *L++;
  }
  inline void clear() {
    fwrite(buf, 1, Top, stdout);
    Top = 0;
  }
  inline void pc(char ch) {
    Top == S && (clear(), 0);
    buf[Top++] = ch;
  }
  inline void endl() { pc('\n'); }
  FastIO& operator>>(char& ch) {
    while (ch = nc(), ch == ' ' || ch == '\n' || ch == '\r')
      ;
    return *this;
  }
  template <typename T>
  FastIO& operator>>(T& ret) {
    ret = 0;
    int f = 1;
    char ch = nc();
    while (ch < '0' || ch > '9') {
      if (ch == '-') f = -f;
      ch = nc();
    }
    while (ch >= '0' && ch <= '9') {
      ret = ret * 10 + ch - '0';
      ch = nc();
    }
    ret *= f;
    return *this;
  }
  FastIO& operator>>(char* s) {
    int Len = 0;
    char ch = nc();
    while (ch != '\n') {
      *(s + Len) = ch;
      Len++;
      ch = nc();
    }
  }
  template <typename T>
  FastIO& operator<<(T x) {
    if (x < 0) {
      pc('-');
      x = -x;
    }
    do {
      stk[++stk[0]] = x % 10;
      x /= 10;
    } while (x);
    while (stk[0]) pc('0' + stk[stk[0]--]);
    return *this;
  }
  FastIO& operator<<(char ch) {
    pc(ch);
    return *this;
  }
  FastIO& operator<<(string str) {
    int Len = str.size() - 1;
    for (stk[0] = 0; Len >= 0; Len--) stk[++stk[0]] = str[Len];
    while (stk[0]) pc(stk[stk[0]--]);
    return *this;
  }
} fin, fout;
int main() {
  fin >> T;
  while (T--) {
    fin >> n;
    for (register int i = 1; i <= n; i++) fin >> a[i], s[i] = s[i - 1] + a[i];
    int m = sqrt(2 * n);
    for (register int i = 1; i <= m; i++) f[n + 1][i] = -1;
    f[n + 1][0] = 2147483647;
    for (register int i = n; i; i--) {
      for (register int j = 1; j <= m; j++)
        if (i + j - 1 <= n && s[i + j - 1] - s[i - 1] < f[i + j][j - 1])
          f[i][j] = max((int)(s[i + j - 1] - s[i - 1]), f[i + 1][j]);
        else
          f[i][j] = f[i + 1][j];
      f[i][0] = 2147483647;
    }
    int ans = 0;
    for (register int i = m; i; i--)
      if (f[1][i] != -1) {
        ans = i;
        break;
      }
    cout << ans << '\n';
  }
  return 0;
}
