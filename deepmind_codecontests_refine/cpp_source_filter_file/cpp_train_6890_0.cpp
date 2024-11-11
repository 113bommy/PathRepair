#include <bits/stdc++.h>
using namespace std;
int a[200001], BIT[200001];
pair<int, int> p[200001];
pair<int, pair<int, int> > q[200001];
void update(int i, int n, int val) {
  while (i <= n) {
    BIT[i] += val;
    i += i & -i;
  }
}
int get(int i) {
  int ret = 0;
  while (i) {
    ret += BIT[i];
    i -= i & -i;
  }
  return ret;
}
bool comp(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b) {
  return a.second.first < b.second.first;
}
int main() {
  int n, m, i, cnt = 0, l, r, mid, k;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", a + i);
    p[i].first = -a[i];
    p[i].second = i;
  }
  scanf("%d", &m);
  for (i = 0; i < m; i++) {
    scanf("%d %d", &q[i].second.first, &q[i].second.second);
    p[i].first = i;
  }
  sort(p + 1, p + n + 1);
  sort(q, q + m, comp);
  for (i = 0; i < m; i++) {
    while (cnt < q[i].second.first) {
      update(p[++cnt].second, n, 1);
    }
    l = 1;
    r = n;
    while (l <= r) {
      mid = (l + r) >> 1;
      if (get(mid) >= q[i].second.second) {
        k = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    q[i].second.second = a[k];
  }
  sort(q, q + m);
  for (i = 0; i < m; i++) {
    if (i) printf("\n");
    printf("%d", q[i].second.second);
  }
  return 0;
}
