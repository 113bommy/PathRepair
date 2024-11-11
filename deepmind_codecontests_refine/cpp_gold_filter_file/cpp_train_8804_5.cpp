#include <bits/stdc++.h>
using namespace std;
const int N = 300500;
int n;
int sz = 0;
int p[N];
long long f[N];
long long fw[N];
int a[N], b[N], h[N];
pair<int, int> c[N];
bool cmp(int x, int y) {
  if (b[x] != b[y]) {
    return b[x] > b[y];
  }
  return a[x] > a[y];
}
long long get_max(int r) {
  long long ret = 0LL;
  while (r > 0) {
    ret = max(ret, fw[r]);
    r = (r & (r + 1)) - 1;
  }
  return ret;
}
void update(int pos, long long value) {
  while (pos <= sz) {
    fw[pos] = max(fw[pos], value);
    pos |= (pos + 1);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &a[i], &b[i], &h[i]);
    c[++sz] = make_pair(a[i], i);
    c[++sz] = make_pair(b[i], -i);
  }
  sort(c + 1, c + sz + 1);
  for (int i = 1; i <= n; i++) {
    p[i] = i;
  }
  sort(p + 1, p + 1 + n, cmp);
  int id = 1;
  for (int i = 1; i <= sz; i++) {
    if (i > 1 && c[i - 1].first != c[i].first) {
      ++id;
    }
    int o = c[i].second;
    if (o > 0) {
      a[o] = id;
    } else {
      b[abs(o)] = id;
    }
  }
  for (int w = 1; w <= n; w++) {
    int i = p[w];
    f[w] = get_max(b[i] - 1) + 1LL * h[i];
    update(a[i], f[w]);
  }
  cout << get_max(sz) << endl;
  return 0;
}
