#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int n, m, c, c0;
struct node {
  int t, S, v;
} q[N];
set<pair<int, int> > S;
bool cmp(node x, node y) { return x.t < y.t; }
void solve() {
  scanf("%d%d%d%d", &n, &m, &c, &c0);
  for (int i = (int)(1); i <= (int)(n); i++)
    scanf("%d%d%d", &q[i].t, &q[i].S, &q[i].v);
  q[++n] = (node){m, 0, 0};
  q[++n] = (node){0, c0, 0};
  sort(q + 1, q + n + 1, cmp);
  int sum = 0;
  long long ans = 0;
  S.clear();
  for (int i = (int)(1); i <= (int)(n - 1); i++) {
    set<pair<int, int> >::iterator it;
    it = S.lower_bound(pair<int, int>(q[i].v, 0));
    if (it == S.end() || it->first != q[i].v)
      S.insert(pair<int, int>(q[i].v, q[i].S));
    else {
      int v = it->second;
      S.erase(it);
      S.insert(pair<int, int>(q[i].v, v + q[i].S));
    }
    sum += q[i].S;
    for (; sum > c;) {
      pair<int, int> tmp = *(--S.end());
      S.erase(tmp);
      int v = min(c - sum, tmp.second);
      sum -= v;
      tmp.second -= v;
      if (tmp.second) S.insert(tmp);
    }
    int dif = q[i + 1].t - q[i].t;
    if (dif > sum) {
      puts("-1");
      return;
    }
    for (; dif;) {
      pair<int, int> tmp = *S.begin();
      S.erase(tmp);
      int v = min(dif, tmp.second);
      sum -= v;
      dif -= v;
      tmp.second -= v;
      ans += 1ll * tmp.first * v;
      if (tmp.second) S.insert(tmp);
    }
  }
  printf("%lld\n", ans);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
}
