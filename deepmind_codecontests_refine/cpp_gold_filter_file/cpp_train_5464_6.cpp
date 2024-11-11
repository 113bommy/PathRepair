#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int maxn = 400005;
map<long long, long long> m;
int a[maxn], b[maxn];
vector<pair<long long, long long> > pp;
long long tot = 0;
long long c[maxn];
void add(int x, int v, int n) {
  while (x <= n) c[x] += v, x += x & -x;
}
long long sum(int x) {
  long long res = 0;
  while (x) res += c[x], x -= x & -x;
  return res;
}
int main() {
  int n;
  scanf("%d", &n);
  int u, v;
  while (n--) {
    scanf("%d%d", &u, &v);
    if (m[u] == 0) m[u] = u;
    if (m[v] == 0) m[v] = v;
    swap(m[u], m[v]);
  }
  map<long long, long long>::iterator it = m.begin();
  int cnt = 0;
  while (it != m.end()) {
    pp.push_back(*it);
    a[cnt] = it->second;
    b[cnt] = a[cnt];
    cnt++;
    it++;
  }
  sort(b, b + cnt);
  for (int i = cnt - 1; i >= 0; i--) {
    int id = lower_bound(b, b + cnt, a[i]) - b + 1;
    tot += sum(id - 1);
    add(id, 1, cnt);
  }
  for (int i = 0; i < cnt; i++) {
    if (pp[i].second > pp[i].first)
      tot += pp[i].second - pp[i].first -
             (lower_bound(pp.begin(), pp.end(),
                          pair<long long, long long>(pp[i].second, -1)) -
              lower_bound(pp.begin(), pp.end(),
                          pair<long long, long long>(pp[i].first, -1)));
    if (pp[i].second < pp[i].first)
      tot += pp[i].first - pp[i].second -
             (lower_bound(pp.begin(), pp.end(),
                          pair<long long, long long>(pp[i].first, -1)) -
              lower_bound(pp.begin(), pp.end(),
                          pair<long long, long long>(pp[i].second, -1)));
  }
  printf("%I64d\n", tot);
  return 0;
}
