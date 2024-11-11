#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
const int INF = 0x3f3f3f3f;
template <class T>
void Read(T &x) {
  x = 0;
  char c = getchar();
  bool flag = 0;
  while (c < '0' || '9' < c) {
    if (c == '-') flag = 1;
    c = getchar();
  }
  while ('0' <= c && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  if (flag) x = -x;
}
long double C[MAXN + 10][MAXN + 10];
long double dp[MAXN + 10][MAXN + 10];
int n, m;
int num[MAXN + 10], nd[MAXN + 10];
int bg[MAXN + 10];
bool able[MAXN + 10];
int c[MAXN + 10], t[MAXN + 10], cnt;
int main() {
  Read(n), Read(m);
  for (int i = 1; i <= m; ++i) {
    Read(num[i]);
    bg[i] = bg[i - 1] + num[i - 1];
    for (int j = 1; j <= num[i]; ++j) Read(c[bg[i] + j]);
    cnt += num[i];
  }
  for (int i = 1; i <= cnt; ++i) t[i] = c[i];
  sort(t + 1, t + cnt + 1);
  int sp = t[cnt - n + 1];
  int cntsp = (upper_bound(t + 1, t + n + 1, sp) - t) - (cnt - n + 1);
  int totsp =
      upper_bound(t + 1, t + n + 1, sp) - lower_bound(t + 1, t + n + 1, sp);
  for (int i = 1; i <= m; ++i) {
    nd[i] = 0, able[i] = false;
    for (int j = 1; j <= num[i]; ++j) {
      if (c[bg[i] + j] > sp)
        ++nd[i];
      else if (c[bg[i] + j] == sp)
        able[i] = true;
    }
  }
  if (cntsp == totsp) {
    for (int i = 1; i <= m; ++i) nd[i] += able[i], able[i] = false;
    cntsp = totsp = 0;
  }
  C[0][0] = 1;
  for (int i = 1; i <= MAXN; ++i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++j) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
  }
  dp[0][0] = 1;
  for (int i = 1; i <= m; ++i) {
    for (int j = 0; j <= cntsp; ++j) {
      if (j > 0 && able[i])
        dp[i][j] += dp[i - 1][j - 1] * 1.0 / C[num[i]][nd[i] + 1];
      dp[i][j] += dp[i - 1][j] * 1.0 / C[num[i]][nd[i]];
    }
  }
  printf("%.9f\n", (double)(dp[m][cntsp] / C[totsp][cntsp]));
}
