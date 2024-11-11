#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 15;
set<int> st[N];
int l, r, x, p, n, m, t, A[N];
struct fen {
  unordered_map<int, long long> mp[N];
  fen() {
    for (int i = 1; i <= N - 1; i++) mp[i].max_load_factor(0.15);
  }
  void add(int l, int R, int d) {
    for (l++; l < N; l += l & (-l))
      for (int r = R + 1; r < N; r += r & (-r)) {
        mp[l][r] += d;
        if (!mp[l][r]) mp[l].erase(r);
      }
  }
  long long get(int l, int R) {
    long long sm = 0;
    for (l++; l > 0; l -= l & (-l))
      for (int r = R + 1; r > 0; r -= r & (-r))
        sm += mp[l].count(r) ? mp[l][r] : 0;
    return (sm);
  }
  long long g(int l, int r) { return (get(N - 5, r) - get(l - 1, r)); }
};
fen f;
void add(int a, int b) {
  auto r = st[b].upper_bound(a);
  auto l = r;
  if (r != st[b].end()) f.add(a, *r, *r - a);
  if (r != st[b].begin()) l--, f.add(*l, a, a - *l);
  if (r != st[b].end() && r != st[b].begin()) f.add(*l, *r, *l - *r);
  st[b].insert(a);
  A[a] = b;
}
void del(int a, int b) {
  st[b].erase(a);
  auto r = st[b].upper_bound(a);
  auto l = r;
  if (r != st[b].end()) f.add(a, *r, a - *r);
  if (r != st[b].begin()) l--, f.add(*l, a, *l - a);
  if (r != st[b].end() && r != st[b].begin()) f.add(*l, *r, *r - *l);
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", A + i), st[A[i]].insert(i);
  for (int i = 1; i <= n; i++)
    if ((int)st[i].size() > 1) {
      auto it = st[i].begin();
      auto it2 = it;
      it2++;
      for (int j = 1; j < (int)st[i].size(); j++) {
        f.add(*it, *it2, *it2 - *it);
        it++, it2++;
      }
    }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &t);
    if (t & 1) {
      scanf("%d %d", &p, &x);
      del(p, A[p]);
      add(p, x);
      continue;
    }
    scanf("%d %d", &l, &r);
    printf("%I64d\n", f.g(l, r));
  }
}
