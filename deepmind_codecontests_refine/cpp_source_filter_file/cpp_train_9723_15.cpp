#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int f = 1, x = 0;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') f = -1;
  } while (ch < '0' || ch > '9');
  do {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = getchar();
  } while (ch >= '0' && ch <= '9');
  return f * x;
}
const int MAXN = 100000 + 10;
int n;
struct Query {
  int opt;
  int l, r;
} Q[MAXN];
int top, cnt;
int f[MAXN];
int L[MAXN], R[MAXN];
int sta[MAXN << 1];
inline int find(int x) {
  if (x == f[x])
    return x;
  else
    return f[x] = find(f[x]);
}
vector<int> ve[MAXN << 2];
inline void merge(int x, int y) {
  int fx = find(x);
  f[fx] = y;
  return;
}
inline void update(int o, int l, int r, int x, int c) {
  if (ve[o].size()) {
    for (int i = 0; i < ve[o].size(); i++) {
      int v = ve[o][i];
      merge(v, c);
      L[c] = min(L[c], L[v]);
      R[c] = max(R[c], R[v]);
    }
    ve[o].clear();
    ve[o].push_back(c);
  }
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (x <= mid)
    update(o << 1, l, mid, x, c);
  else
    update(o << 1 | 1, mid + 1, r, x, c);
}
inline void update1(int o, int l, int r, int L, int R, int c) {
  if (l == L && R == r) {
    ve[o].push_back(c);
    return;
  }
  int mid = (l + r) >> 1;
  if (R <= mid)
    update1(o << 1, l, mid, L, R, c);
  else if (L > mid)
    update1(o << 1 | 1, mid + 1, r, L, R, c);
  else {
    update1(o << 1, l, mid, L, mid, c);
    update1(o << 1 | 1, mid + 1, r, mid + 1, R, c);
  }
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    Q[i].opt = read(), Q[i].l = read(), Q[i].r = read();
    if (Q[i].opt == 1) {
      sta[++top] = Q[i].l;
      sta[++top] = Q[i].r;
    }
  }
  sort(sta + 1, sta + top + 1);
  top = unique(sta + 1, sta + top + 1) - sta - 1;
  for (int i = 1; i <= n; i++) {
    if (Q[i].opt == 1) {
      int l = lower_bound(sta + 1, sta + top + 1, Q[i].l) - sta;
      int r = lower_bound(sta + 1, sta + top + 1, Q[i].r) - sta;
      cnt++;
      f[cnt] = cnt;
      L[cnt] = Q[i].l;
      R[cnt] = Q[i].r;
      update(1, 1, top, l, cnt);
      update(1, 1, top, r, cnt);
      if (l + 1 <= r - 1) {
        update1(1, 1, top, l + 1, r - 1, cnt);
      }
    } else {
      int u = find(Q[i].l), v = find(Q[i].r);
      bool tag = 0;
      if (u == v)
        tag = 1;
      else if ((L[u] > L[v] && L[u] < R[v]) || (R[u] > L[v] && R[u] < R[v]))
        tag = 1;
      if (tag)
        printf("YES\n");
      else
        printf("NO\n");
    }
  }
}
