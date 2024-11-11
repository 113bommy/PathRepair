#include <bits/stdc++.h>
using namespace std;
int a[300000 + 5], d[1000000 + 5];
long long t[4 * 300000 + 5], m[4 * 300000 + 5];
bool vis[300000 + 5];
int p[300000 + 5], l = 0;
void sieve() {
  for (int i = 3; i * i < 30000 + 5; i += 2) {
    if (!vis[i]) {
      for (int j = i * i; j < 30000 + 5; j += i + i) {
        vis[j] = true;
      }
    }
  }
  p[l++] = 2;
  for (int i = 3; i < 30000 + 5; i += 2)
    if (!vis[i]) p[l++] = i;
  for (int j = 1; j <= 1000000; j++) {
    int n = j;
    d[j] = 1;
    for (int i = 0; i < l && p[i] * p[i] <= n; i++) {
      if (n % p[i] == 0) {
        int c = 1;
        while (n % p[i] == 0) {
          c++;
          n /= p[i];
        }
        d[j] *= c;
      }
    }
    if (n != 1) d[j] *= 2;
  }
}
void build(int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = (long long)a[tl];
    m[v] = (long long)a[tl];
    return;
  }
  int tm = (tl + tr) >> 1;
  build(2 * v, tl, tm);
  build(2 * v + 1, tm + 1, tr);
  t[v] = t[2 * v] + t[2 * v + 1];
  m[v] = max(m[2 * v], m[2 * v + 1]);
}
void update(int v, int tl, int tr, int l, int r) {
  if (l > r) return;
  if (m[v] <= 2) return;
  if (tl == tr) {
    t[v] = (long long)d[t[v]];
    m[v] = (long long)d[t[v]];
    return;
  }
  int tm = (tl + tr) >> 1;
  update(2 * v, tl, tm, l, min(tm, r));
  update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
  t[v] = t[2 * v] + t[2 * v + 1];
  m[v] = max(m[2 * v], m[2 * v + 1]);
}
long long query(int v, int tl, int tr, int l, int r) {
  if (l > r) return 0;
  if (l == tl && r == tr) return t[v];
  int tm = (tl + tr) >> 1;
  return query(2 * v, tl, tm, l, min(tm, r)) +
         query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
}
int main(int argc, const char* argv[]) {
  sieve();
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  build(1, 0, n - 1);
  while (q--) {
    int t, l, r;
    scanf("%d %d %d", &t, &l, &r);
    if (t == 1)
      update(1, 0, n - 1, l - 1, r - 1);
    else
      printf("%lld\n", query(1, 0, n - 1, l - 1, r - 1));
  }
  return 0;
}
