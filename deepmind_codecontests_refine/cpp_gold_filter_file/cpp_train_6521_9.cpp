#include <bits/stdc++.h>
using namespace std;
int ar[1300005];
int divi[1300005];
int n, m;
long long sum[1300005];
set<int> idx;
void update(int node, int be, int en, int pos) {
  if (be > pos || en < pos) return;
  if (be == en) {
    sum[node] = ar[pos];
    return;
  }
  int mid = (be + en) / 2;
  update(node * 2, be, mid, pos);
  update(node * 2 + 1, mid + 1, en, pos);
  sum[node] = sum[node * 2] + sum[node * 2 + 1];
}
long long query(int node, int be, int en, int i, int j) {
  if (en < i || be > j) return 0;
  if (be >= i && en <= j) {
    return sum[node];
  }
  int mid = (be + en) / 2;
  return query(node * 2, be, mid, i, j) +
         query(node * 2 + 1, mid + 1, en, i, j);
}
void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &ar[i]);
    if (ar[i] > 2) idx.insert(i);
    update(1, 1, n, i);
  }
  while (m--) {
    int ti, l, r;
    scanf("%d%d%d", &ti, &l, &r);
    if (ti == 1) {
      auto be = idx.lower_bound(l);
      auto en = idx.upper_bound(r);
      for (auto it = be; it != en; it++) {
        int pos = *it;
        ar[pos] = divi[ar[pos]];
        update(1, 1, n, pos);
      }
      for (auto it = be; it != en;) {
        auto tem = it;
        it++;
        int pos = *tem;
        if (ar[pos] <= 2) idx.erase(tem);
      }
    } else {
      printf("%lld\n", query(1, 1, n, l, r));
    }
  }
}
int main() {
  for (int i = 1; i <= 1000000; i++) {
    for (int j = i; j <= 1000000; j += i) divi[j]++;
  }
  int t = 1;
  while (t--) solve();
  return 0;
}
