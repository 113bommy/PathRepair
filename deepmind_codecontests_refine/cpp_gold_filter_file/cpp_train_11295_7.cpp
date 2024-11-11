#include <bits/stdc++.h>
using namespace std;
int A[100001], B[100001], C[100001], D[100001], a[100001], b[100001], c[100001],
    e[100001], f[100001], h[5005], i, j, m, n, q;
bool d[100001];
inline bool cmp(int u, int v) { return a[v] < a[u]; }
inline void add(int u) {
  while (u <= n) h[u]++, u += u & -u;
}
inline void del(int u) {
  while (u <= n) h[u]--, u += u & -u;
}
inline int sum(int u) {
  int v = 0;
  while (u) v += h[u], u ^= u & -u;
  return v;
}
void dfs(int l, int r) {
  if (l == r) return;
  int o = l + r >> 1;
  for (dfs(l, o), dfs(o + 1, r), i = l, j = o + 1; j <= r;)
    if (i <= o && a[e[j]] <= a[e[i]])
      d[e[i]] ? add(b[e[i]]), del(c[e[i]]), 0 : 0, i++;
    else
      !d[e[j]] ? D[c[e[j]]] += sum(b[e[j]]) : 0, j++;
  while (l < i) d[e[--i]] ? del(b[e[i]]), add(c[e[i]]), 0 : 0;
  merge(e + l, e + o + 1, e + o + 1, e + r + 1, f, cmp),
      memcpy(e + l, f, r - l + 1 << 2);
}
int main() {
  scanf("%d%d", &n, &q);
  for (i = 1; i <= q; i++)
    scanf("%d", A + i),
        A[i] == 2 ? A[i] = 0,
                    scanf("%d%d", B + i, C + i)
                  : scanf("%d%d%d%d", A + i, B + i, C + i, D + i);
  for (i = 1; i <= q; i++)
    if (!A[i])
      a[++m] = B[i] + C[i], b[m] = C[c[m] = i], d[e[m] = m] = false;
    else if (A[i] == 1)
      a[++m] = D[i] + B[i] + C[i], b[m] = C[i], c[m] = C[i] + D[i] + 1,
      d[e[m] = m] = true;
  for (dfs(1, m), i = 1, m = 0; i <= q; i++)
    if (!A[i])
      a[++m] = B[i] - C[i], b[m] = C[c[m] = i], d[e[m] = m] = false;
    else if (A[i] == 2)
      a[++m] = D[i] + B[i] - C[i], b[m] = C[i] - D[i], c[m] = C[i] + 1,
      d[e[m] = m] = true;
  for (dfs(1, m), i = 1, m = 0; i <= q; i++)
    if (!A[i])
      a[++m] = C[i] - B[i], b[m] = C[c[m] = i], d[e[m] = m] = false;
    else if (A[i] == 3)
      a[++m] = D[i] + C[i] - B[i], b[m] = C[i], c[m] = C[i] + D[i] + 1,
      d[e[m] = m] = true;
  for (dfs(1, m), i = 1, m = 0; i <= q; i++)
    if (!A[i])
      a[++m] = -B[i] - C[i], b[m] = C[c[m] = i], d[e[m] = m] = false;
    else if (A[i] == 4)
      a[++m] = D[i] - B[i] - C[i], b[m] = C[i] - D[i], c[m] = C[i] + 1,
      d[e[m] = m] = true;
  for (dfs(1, m), i = 1, m = 0; i <= q; i++)
    if (!A[i])
      a[++m] = B[i], b[m] = C[c[m] = i], d[e[m] = m] = false;
    else if (A[i] == 1)
      a[++m] = B[i] - 1, b[m] = C[i] + D[i] + 1, c[m] = C[i],
      d[e[m] = m] = true;
    else if (A[i] == 2)
      a[++m] = B[i] - 1, b[m] = C[i] + 1, c[m] = C[i] - D[i],
      d[e[m] = m] = true;
  for (dfs(1, m), i = 1, m = 0; i <= q; i++)
    if (!A[i])
      a[++m] = n - B[i] + 1, b[m] = C[c[m] = i], d[e[m] = m] = false;
    else if (A[i] == 3)
      a[++m] = n - B[i], b[m] = C[i] + D[i] + 1, c[m] = C[i],
      d[e[m] = m] = true;
    else if (A[i] == 4)
      a[++m] = n - B[i], b[m] = C[i] + 1, c[m] = C[i] - D[i],
      d[e[m] = m] = true;
  for (dfs(1, m), i = 1; i <= q; i++)
    if (!A[i]) printf("%d\n", D[i]);
  return 0;
}
