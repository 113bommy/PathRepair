#include <bits/stdc++.h>
using namespace std;
int n, k, m;
long long l[100100], g, r, p, ti, f[100100], L[100100], TI;
int it[100100 * 4], c[100100];
struct pp {
  long long x;
  int c;
} t[100100];
bool ss(pp a, pp b) { return a.x < b.x; }
void update(int pos, int val) {
  int l = 1, h = n + 1, node = 1;
  while (l <= h) {
    it[node] = min(it[node], val);
    if (l == h) break;
    int mid = (l + h) / 2;
    if (pos <= mid)
      h = mid, node *= 2;
    else
      l = mid + 1, node = node * 2 + 1;
  }
}
int get(int node, int l, int h, int u, int v) {
  if (u <= l && h <= v) return it[node];
  if (h < u || v < l) return n + 2;
  int mid = (l + h) / 2;
  return min(get(node * 2, l, mid, u, v), get(node * 2 + 1, mid + 1, h, u, v));
}
int find1(long long val) {
  if (t[n + 1].x < val) return n + 2;
  int l = 2, h = n + 1;
  while (l + 1 < h) {
    int mid = (l + h) / 2;
    if (t[mid].x >= val)
      h = mid;
    else
      l = mid + 1;
  }
  if (t[l].x >= val)
    return l;
  else
    return h;
}
int find2(long long val) {
  if (t[2].x >= val) return 1;
  int l = 2, h = n + 1;
  while (l + 1 < h) {
    int mid = (l + h) / 2;
    if (t[mid].x < val)
      l = mid;
    else
      h = mid - 1;
  }
  if (t[h].x < val)
    return h;
  else
    return l;
}
int cal(long long cd, long long ct) {
  return get(1, 1, n + 1, find1(cd), find2(ct));
}
int main() {
  cin >> n >> g >> r;
  p = g + r;
  for (int i = 1; i <= n + 1; i++)
    scanf("%I64d", &L[i + 1]), L[i + 1] = L[i] + L[i + 1];
  for (int i = 1; i <= n + 1; i++) l[i] = L[i] % p, t[i].x = l[i], t[i].c = i;
  sort(t + 1, t + n + 2, ss);
  for (int i = 1; i <= n + 1; i++) c[t[i].c] = i;
  for (int i = 1; i <= n * 4 + 100; i++) it[i] = n + 2;
  f[n + 2] = 0;
  f[n + 1] = L[n + 2] - L[n + 1];
  update(c[n + 1], n + 1);
  for (int i = n; i >= 2; i--) {
    int pos;
    pos = min(cal(g + l[i], g + r + l[i]), cal(l[i] - r, l[i]));
    if (pos < n + 2)
      f[i] = f[pos] + p - (L[pos] - L[i]) % p + L[pos] - L[i];
    else
      f[i] = L[n + 2] - L[i];
    update(c[i], i);
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    scanf("%I64d", &TI);
    ti = TI % p;
    int pos = min(cal(g - ti, g + r - ti), cal(g + p - ti, p * 2 - ti));
    if (pos != n + 2)
      printf("%I64d\n", f[pos] + p - (l[pos] + ti) % p + L[pos] + TI);
    else
      printf("%I64d\n", L[n + 2] + TI);
  }
  return 0;
}
