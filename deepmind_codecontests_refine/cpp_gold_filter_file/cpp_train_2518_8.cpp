#include <bits/stdc++.h>
template <class T>
void read(T &);
template <class T>
void write(const T &);
const int iinf = 2147483647;
const long long llinf = 9223372036854775807ll;
constexpr int N = 4005;
void reva(int x);
void revb(int x);
char a[N], b[N];
int cnta[4][N], cntb[4][N];
std::vector<int> ans;
int n;
int main() {
  int t;
  read(t);
  while (t--) {
    ans.clear();
    scanf("%s", a + 1);
    scanf("%s", b + 1);
    n = strlen(a + 1);
    int m = n >> 1;
    for (int i = 1; i <= m; ++i) {
      for (int j = 0; j < 4; ++j) {
        cnta[j][i] = cnta[j][i - 1];
      }
      int now = ((a[(i << 1) - 1] - '0') << 1) + a[i << 1] - '0';
      ++cnta[now][i];
    }
    for (int i = 1; i <= m; ++i) {
      for (int j = 0; j < 4; ++j) {
        cntb[j][i] = cntb[j][i - 1];
      }
      int now = ((b[(i << 1) - 1] - '0') << 1) + b[i << 1] - '0';
      ++cntb[now][i];
    }
    if (cnta[0][m] != cntb[0][m] || cnta[3][m] != cntb[3][m]) {
      puts("-1");
      continue;
    }
    int v = -1;
    if (cnta[1][m] != cntb[1][m]) {
      bool flag = false;
      for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= m; ++j) {
          if (cnta[1][m] - cnta[1][i] + cnta[2][i] ==
              cntb[1][m] - cntb[1][j] + cntb[2][j]) {
            if (i > 0) {
              reva(i);
            }
            if (j > 0) {
              revb(v = j);
            }
            flag = true;
            break;
          }
        }
        if (flag) {
          break;
        }
      }
    }
    for (int i = 1; i <= m; ++i) {
      int now = 0;
      for (int j = i; j <= m; ++j) {
        if (a[(j << 1) - 1] == b[(i << 1) - 1] && a[j << 1] == b[i << 1]) {
          now = j;
          break;
        }
      }
      if (now > 1) {
        reva(now - 1);
      }
      if (i != m) {
        reva(now);
      }
    }
    if (v != -1) {
      reva(v), revb(v);
    }
    write(ans.size()), putchar('\n');
    for (int i : ans) {
      write(i), putchar(' ');
    }
    putchar('\n');
  }
  return 0;
}
void reva(int x) {
  std::reverse(a + 1, a + (x << 1) + 1);
  ans.push_back(x << 1);
}
void revb(int x) { std::reverse(b + 1, b + (x << 1) + 1); }
template <class T>
inline void read(T &Re) {
  T k = 0;
  char ch = getchar();
  int flag = 1;
  while (!(ch >= '0' && ch <= '9')) {
    if (ch == '-') {
      flag = -1;
    }
    ch = getchar();
  }
  while ((ch >= '0' && ch <= '9')) {
    k = (k << 1) + (k << 3) + ch - '0';
    ch = getchar();
  }
  Re = flag * k;
}
template <class T>
inline void write(const T &Wr) {
  if (Wr < 0) {
    putchar('-');
    write(-Wr);
  } else {
    if (Wr < 10) {
      putchar(Wr + '0');
    } else {
      write(Wr / 10);
      putchar((Wr % 10) + '0');
    }
  }
}
