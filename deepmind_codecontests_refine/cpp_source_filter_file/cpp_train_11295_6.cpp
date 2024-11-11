#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
struct node {
  int fx, fy, t, q;
} w[N], e[N], op[N];
int n, q, k, len, fl[N], sum[N];
long long ans[N];
inline int read() {
  int num = 0;
  char g = getchar();
  while (g < 48 || 57 < g) g = getchar();
  while (47 < g && g < 58)
    num = (num << 1) + (num << 3) + g - 48, g = getchar();
  return num;
}
inline int lowbit(int u) { return (u & (-u)); }
inline void add(int u, int c) {
  while (u <= (k << 1)) sum[u] += c, u += lowbit(u);
}
inline int search(int u) {
  int c = 0;
  while (u > 0) c += sum[u], u -= lowbit(u);
  return c;
}
inline void solve(int l, int r) {
  if (l == r || l > r) return;
  int d = (l + r) >> 1, lf = l, rf = d + 1, cl = l;
  solve(l, d), solve(d + 1, r);
  while (lf <= d && rf <= r) {
    if (w[lf].fx <= w[rf].fx)
      add(w[lf].fy, w[lf].q), op[cl++] = w[lf++];
    else {
      ans[w[rf].t] += search(w[rf].fy), op[cl++] = w[rf++];
    }
  }
  while (rf <= r) {
    ans[w[rf].t] += search(w[rf].fy), op[cl++] = w[rf++];
  }
  for (int i = l; i < lf; i++) add(w[i].fy, -w[i].q);
  for (int i = lf; i <= d; i++) op[cl++] = w[i];
  for (int i = l; i <= r; i++) w[i] = op[i];
}
inline bool cmp(node a, node b) { return a.t < b.t; }
inline void delit(int c) {
  for (int i = 1; i <= c; i++) w[i].fx += k, w[i].fy += k;
  sort(w + 1, w + c + 1, cmp), solve(1, c);
}
int main() {
  k = 2e5, n = read(), q = read();
  for (int i = 1; i <= q; i++) {
    fl[i] = read();
    if (fl[i] == 1)
      e[i].q = read(), e[i].fx = read(), e[i].fy = read(), e[i].t = read();
    else
      e[i].fx = read(), e[i].fy = read();
  }
  for (int i = 1; i <= n; i++) {
    if (e[i].q == 1) {
      len++, w[len].fx = e[i].fx, w[len].fy = e[i].fy, w[len].t = i,
             w[len].q = 1;
      len++, w[len].fx = e[i].fx + e[i].t + 1, w[len].fy = e[i].fy,
             w[len].t = i, w[len].q = -1;
    } else if (fl[i] == 2) {
      len++, w[len].fx = e[i].fx, w[len].fy = e[i].fy, w[len].t = i,
             w[len].q = 0;
    }
  }
  delit(len), len = 0;
  for (int i = 1; i <= n; i++) {
    if (e[i].q == 1) {
      len++, w[len].fx = e[i].fx, w[len].fy = e[i].fx + e[i].fy + e[i].t + 1,
             w[len].t = i, w[len].q = -1;
      len++, w[len].fx = e[i].fx + e[i].t + 1,
             w[len].fy = e[i].fx + e[i].fy + e[i].t + 1, w[len].t = i,
             w[len].q = 1;
    } else if (fl[i] == 2) {
      len++, w[len].fx = e[i].fx, w[len].fy = e[i].fx + e[i].fy, w[len].t = i,
             w[len].q = 0;
    }
  }
  delit(len), len = 0;
  for (int i = 1; i <= n; i++) {
    if (e[i].q == 2) {
      len++, w[len].fx = e[i].fx, w[len].fy = e[i].fy + 1, w[len].t = i,
             w[len].q = -1;
      len++, w[len].fx = e[i].fx + e[i].t + 1, w[len].fy = e[i].fy + 1,
             w[len].t = i, w[len].q = 1;
    } else if (fl[i] == 2) {
      len++, w[len].fx = e[i].fx, w[len].fy = e[i].fy, w[len].t = i,
             w[len].q = 0;
    }
  }
  delit(len), len = 0;
  for (int i = 1; i <= n; i++) {
    if (e[i].q == 2) {
      len++, w[len].fx = e[i].fx, w[len].fy = e[i].fy - e[i].fx - e[i].t,
             w[len].t = i, w[len].q = 1;
      len++, w[len].fx = e[i].fx + e[i].t + 1,
             w[len].fy = e[i].fy - e[i].fx - e[i].t, w[len].t = i,
             w[len].q = -1;
    } else if (fl[i] == 2) {
      len++, w[len].fx = e[i].fx, w[len].fy = e[i].fy - e[i].fx, w[len].t = i,
             w[len].q = 0;
    }
  }
  delit(len), len = 0;
  for (int i = 1; i <= n; i++) {
    if (e[i].q == 3) {
      len++, w[len].fx = e[i].fx - e[i].t, w[len].fy = e[i].fy, w[len].t = i,
             w[len].q = 1;
      len++, w[len].fx = e[i].fx + 1, w[len].fy = e[i].fy, w[len].t = i,
             w[len].q = -1;
    } else if (fl[i] == 2) {
      len++, w[len].fx = e[i].fx, w[len].fy = e[i].fy, w[len].t = i,
             w[len].q = 0;
    }
  }
  delit(len), len = 0;
  for (int i = 1; i <= n; i++) {
    if (e[i].q == 3) {
      len++, w[len].fx = e[i].fx - e[i].t,
             w[len].fy = e[i].fy - e[i].fx + e[i].t + 1, w[len].t = i,
             w[len].q = -1;
      len++, w[len].fx = e[i].fx + 1,
             w[len].fy = e[i].fy - e[i].fx + e[i].t + 1, w[len].t = i,
             w[len].q = 1;
    } else if (fl[i] == 2) {
      len++, w[len].fx = e[i].fx, w[len].fy = e[i].fy - e[i].fx, w[len].t = i,
             w[len].q = 0;
    }
  }
  delit(len), len = 0;
  for (int i = 1; i <= n; i++) {
    if (e[i].q == 4) {
      len++, w[len].fx = e[i].fx - e[i].t, w[len].fy = e[i].fy + 1,
             w[len].t = i, w[len].q = -1;
      len++, w[len].fx = e[i].fx + 1, w[len].fy = e[i].fy + 1, w[len].t = i,
             w[len].q = 1;
    } else if (fl[i] == 2) {
      len++, w[len].fx = e[i].fx, w[len].fy = e[i].fy, w[len].t = i,
             w[len].q = 0;
    }
  }
  delit(len), len = 0;
  for (int i = 1; i <= n; i++) {
    if (e[i].q == 4) {
      len++, w[len].fx = e[i].fx - e[i].t,
             w[len].fy = e[i].fx + e[i].fy - e[i].t, w[len].t = i, w[len].q = 1;
      len++, w[len].fx = e[i].fx + 1, w[len].fy = e[i].fx + e[i].fy - e[i].t,
             w[len].t = i, w[len].q = -1;
    } else if (fl[i] == 2) {
      len++, w[len].fx = e[i].fx, w[len].fy = e[i].fy + e[i].fx, w[len].t = i,
             w[len].q = 0;
    }
  }
  delit(len), len = 0;
  for (int i = 1; i <= n; i++)
    if (fl[i] == 2) printf("%d\n", ans[i]);
  return 0;
}
