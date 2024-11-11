#include <bits/stdc++.h>
using namespace std;
int p[120000];
pair<pair<int, int>, int> queries[120000];
vector<int> S1, S2;
int mm[1 << 18], occ[1 << 18];
long long int sum[1 << 18];
int lazy[1 << 18], lazy2[1 << 18];
int build(int s, int e, int i) {
  if (s == e) {
    mm[i] = 1, occ[i] = 1;
    return 0;
  }
  int mid = (s + e) / 2;
  build(s, mid, 2 * i + 1), build(mid + 1, e, 2 * i + 2);
  mm[i] = 1, occ[i] = e - s + 1;
  return 0;
}
int prop(int s, int e, int i) {
  mm[i] += lazy[i], sum[i] += (long long int)occ[i] * lazy2[i];
  if (s != e) {
    lazy[2 * i + 1] += lazy[i], lazy[2 * i + 2] += lazy[i];
    if (mm[2 * i + 1] + lazy[2 * i + 1] == mm[i]) lazy2[2 * i + 1] += lazy2[i];
    if (mm[2 * i + 2] + lazy[2 * i + 2] == mm[i]) lazy2[2 * i + 2] += lazy2[i];
  }
  lazy[i] = lazy2[i] = 0;
  return 0;
}
int update(int s, int e, int as, int ae, int i, int num) {
  prop(s, e, i);
  if ((s > ae) || (e < as))
    return 0;
  else if ((s >= as) && (e <= ae)) {
    lazy[i] += num;
    prop(s, e, i);
    return 0;
  }
  int mid = (s + e) / 2;
  update(s, mid, as, ae, 2 * i + 1, num),
      update(mid + 1, e, as, ae, 2 * i + 2, num);
  mm[i] = min(mm[2 * i + 1], mm[2 * i + 2]), occ[i] = 0;
  if (mm[i] == mm[2 * i + 1]) occ[i] += occ[2 * i + 1];
  if (mm[i] == mm[2 * i + 2]) occ[i] += occ[2 * i + 2];
  sum[i] = sum[2 * i + 1] + sum[2 * i + 2];
  return 0;
}
long long int query(int s, int e, int qs, int qe, int i) {
  prop(s, e, i);
  if ((s > qe) || (e < qs))
    return 0;
  else if ((s >= qs) && (e <= qe))
    return sum[i];
  int mid = (s + e) / 2;
  return query(s, mid, qs, qe, 2 * i + 1) +
         query(mid + 1, e, qs, qe, 2 * i + 2);
}
long long int ans[120000];
int main() {
  int i;
  int n, q, l, r;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &p[i]), p[i]--;
  scanf("%d", &q);
  for (i = 0; i < q; i++)
    scanf("%d %d", &l, &r), queries[i] = make_pair(make_pair(r - 1, l - 1), i);
  sort(queries, queries + q);
  int j;
  build(0, n - 1, 0);
  for (i = 0; i < n; i++) {
    while (!S1.empty() && (p[S1.back()] < p[i])) {
      update(0, n - 1, (S1.size() == 1) ? 0 : S1[S1.size() - 2] + 1, S1.back(),
             0, p[i] - p[S1.back()]);
      S1.pop_back();
    }
    while (!S2.empty() && (p[S2.back()] > p[i])) {
      update(0, n - 1, (S2.size() == 1) ? 0 : S2[S2.size() - 2] + 1, S2.back(),
             0, p[S2.back()] - p[i]);
      S2.pop_back();
    }
    S1.push_back(i), S2.push_back(i);
    update(0, n - 1, 0, i, 0, -1);
    if (mm[0] + lazy[0] == 0) lazy2[0]++, prop(0, n - 1, 0);
    while ((j < q) && (queries[j].first.first == i)) {
      ans[queries[j].second] = query(0, n - 1, queries[j].first.second, i, 0);
      j++;
    }
  }
  for (i = 0; i < q; i++) printf("%I64d\n", ans[i]);
  return 0;
}
