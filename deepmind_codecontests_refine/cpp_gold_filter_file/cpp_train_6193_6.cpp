#include <bits/stdc++.h>
using namespace std;
const int N = (int)2e5 + 10;
const double eps = 1e-18;
double x[N], y[N];
int n, m, id[N], r[N], s[N], a[N];
inline int Sign(const double &x) { return x < -eps ? -1 : x > eps; }
inline int cmp(const int &i, const int &j) {
  if (r[i] != r[j]) return r[i] < r[j];
  return s[i] < s[j];
}
vector<int> ans;
map<pair<int, int>, int> zz;
int Q[N], t;
int main() {
  scanf("%d", &n);
  for (int i(0); (i) < (int)(n); i++) {
    scanf("%d%d", &r[i], &s[i]);
    id[i] = i;
  }
  sort(id, id + n, cmp);
  m = 0;
  int ms = (int)-1e9;
  int mr = (int)-1e9;
  for (int i = n - 1; i >= 0; i--)
    if (!m || r[id[i]] != r[a[m]] || s[id[i]] != s[a[m]]) {
      if (m && (r[id[i]] <= mr && s[id[i]] <= ms)) continue;
      ms = max(ms, s[id[i]]);
      mr = max(mr, r[id[i]]);
      a[++m] = id[i];
    }
  sort(a + 1, a + 1 + m, cmp);
  reverse(a + 1, a + 1 + m);
  t = 0;
  Q[++t] = a[1];
  if (m >= 2) Q[++t] = a[2];
  for (int i = 3; i <= m; i++) {
    while (t >= 2 && Sign((1.0 / r[a[i]] - 1.0 / r[Q[t - 1]]) *
                              (1.0 / s[Q[t]] - 1.0 / s[Q[t - 1]]) -
                          (1.0 / r[Q[t]] - 1.0 / r[Q[t - 1]]) *
                              (1.0 / s[a[i]] - 1.0 / s[Q[t - 1]])) > 0)
      t--;
    Q[++t] = a[i];
  }
  for (int i = 1; i <= t; i++) {
    zz[make_pair(r[Q[i]], s[Q[i]])] = 1;
  }
  int first = true;
  for (int i(0); (i) < (int)(n); i++)
    if (zz.count(make_pair(r[i], s[i]))) {
      if (!first) putchar(' ');
      printf("%d", i + 1);
      first = false;
    }
  puts("");
  return 0;
}
