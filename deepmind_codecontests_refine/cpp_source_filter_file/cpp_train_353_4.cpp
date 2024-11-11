#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int n, m, ans, a[N], b[N], c[N], id[N], V[N], A[N], B[N], C[N];
multiset<int> res;
set<pair<int, int> > H;
bool cmp(const int i, const int j) { return A[i] > A[j]; }
void ins(pair<int, int> z) {
  set<pair<int, int> >::iterator l, i, r = H.lower_bound(z);
  if (r->second >= z.second) return;
  i = H.insert(z).first, l = i, --l, res.erase(res.find(l->first + r->second)),
  res.insert(i->first + r->second);
  while (l->second < i->second)
    r = l--, res.erase(res.find(l->first + r->second)), H.erase(r);
  res.insert(l->first + i->second);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", a + i), V[m++] = a[i];
  for (int i = 0; i < n; ++i) scanf("%d", b + i), V[m++] = b[i];
  for (int i = 0; i < n; ++i) scanf("%d", c + i), V[m++] = c[i];
  sort(V, V + m), m = unique(V, V + m) - V;
  for (int i = 0; i < n; ++i) a[i] = lower_bound(V, V + m, a[i]) - V;
  for (int i = 0; i < n; ++i) b[i] = lower_bound(V, V + m, b[i]) - V;
  for (int i = 0; i < n; ++i) c[i] = lower_bound(V, V + m, c[i]) - V;
  for (int i = 0; i < m; ++i) A[i] = B[i] = C[i] = 2 * n;
  for (int i = 0; i < n; ++i)
    if (A[a[i]] > n) A[a[i]] = i + 1;
  for (int i = 0; i < n; ++i)
    if (B[b[i]] > n) B[b[i]] = i + 1;
  for (int i = 0; i < n; ++i)
    if (C[c[i]] > n) C[c[i]] = i + 1;
  for (int i = 0; i < m + 1; ++i) id[i] = i;
  A[m] = 0, sort(id, id + m, cmp);
  H.insert(make_pair(0, 3 * n)), H.insert(make_pair(3 * n, 0)), res.insert(0),
      ans = A[*id];
  for (int i = 0; i < m; ++i)
    ins(make_pair(B[id[i]], C[id[i]])),
        ans = min(ans, A[id[i + 1]] + *res.begin());
  printf("%d\n", ans);
  return 0;
}
