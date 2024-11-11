#include <bits/stdc++.h>
using namespace std;
const int M = 4002;
int L[M][M], R[M][M], n, p, q;
inline void rd(int &a) {
  a = 0;
  char c;
  while (c = getchar(), !isdigit(c))
    ;
  do a = a * 10 + (c ^ 48);
  while (c = getchar(), isdigit(c));
}
struct node {
  int c, h, t;
  inline bool operator<(const node &tmp) const { return t < tmp.t; }
} th[M];
inline void Max(int &a, int b) {
  if (a < b) a = b;
}
int main() {
  cin >> n >> p;
  for (int i = 1, c, h, t; i <= n; ++i)
    rd(c), rd(h), rd(t), th[i] = (node){c, h, t - 1};
  sort(th + 1, th + n + 1);
  for (int i = 1, k, last = -1; i <= n; ++i) {
    k = th[i].t / p;
    if (k > last) {
      for (int j = th[i].c; j < M; ++j) L[i][j] = th[i].h;
    } else {
      for (int j = 1; j < M; ++j) {
        if (j - th[i].c >= 0) Max(L[i][j], L[i - 1][j - th[i].c] + th[i].h);
        Max(L[i][j], L[i - 1][j]);
      }
    }
    last = k;
  }
  for (int i = n, last = 1e6, k; i; --i) {
    k = th[i].t / p;
    if (k < last) {
      for (int j = th[i].c; j < M; ++j) R[i][j] = th[i].h;
    } else {
      for (int j = 1; j < M; ++j) {
        if (j - th[i].c >= 0) Max(R[i][j], R[i + 1][j - th[i].c] + th[i].h);
        Max(R[i][j], R[i + 1][j]);
      }
    }
    last = k;
  }
  for (cin >> q; q--;) {
    int a, b, st = n + 1, ed = -1, ans = 0;
    rd(a), rd(b);
    --a;
    for (int i = 1, f1 = 0; i <= n; ++i) {
      if (th[i].t > a - p && !f1) f1 = 1, st = i;
      if (th[i].t <= a)
        ed = i;
      else
        break;
    }
    if (ed < st) {
      puts("0");
      continue;
    }
    if (a < p) {
      printf("%d\n", L[ed][b]);
      continue;
    }
    if (th[st].t / p == th[ed].t / p) {
      if (th[st].t / p == a / p)
        printf("%d\n", L[ed][b]);
      else
        printf("%d\n", R[st][b]);
      continue;
    }
    for (int i = 0; i <= b; ++i) Max(ans, R[st][i] + L[ed][b - i]);
    printf("%d\n", ans);
  }
  return 0;
}
