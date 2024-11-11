#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300000;
long long f[MAXN], ans[MAXN];
int w[MAXN], a[MAXN], b[MAXN], c[MAXN], id[MAXN];
int n, m;
inline bool cmp(int x, int y) {
  if (b[x] != b[y]) return b[x] < b[y];
  if (c[x] != c[y]) return c[x] < c[y];
  return a[x] < a[y];
}
void readin() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", w + i);
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", a + i, b + i);
    --a[i];
    c[i] = a[i] % b[i];
    id[i] = i;
  }
  sort(id, id + m, cmp);
}
void add(int x, long long t) {
  while (x >= 0) {
    f[x] += t;
    x = (x & (x + 1)) - 1;
  }
}
void add(int x, int y, long long t) {
  add(x - 1, -t);
  add(y, t);
}
long long find(int x) {
  long long ret = 0;
  while (x < m) {
    ret += f[x];
    x = x | (x + 1);
  }
  return ret;
}
void solve() {
  for (int i = 0; i < m;) {
    int j = i + 1, step = b[id[i]];
    long long sum = 0;
    while (j < n && step == b[id[j]] && a[id[j]] == a[id[i]]) ++j;
    for (int k = a[id[i]]; k < n; k += step) {
      while (j < n && step == b[id[j]] && k == a[id[j]]) {
        add(i, j - 1, sum);
        ++j;
        sum = 0;
      }
      sum += w[k];
    }
    add(i, j - 1, sum);
    i = j;
  }
  for (int i = 0; i < m; ++i) {
    ans[id[i]] = find(i);
  }
  for (int i = 0; i < m; ++i) printf("%I64d\n", ans[i]);
}
int main() {
  readin();
  solve();
  return 0;
}
