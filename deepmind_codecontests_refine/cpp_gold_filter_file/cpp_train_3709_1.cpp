#include <bits/stdc++.h>
using namespace std;
struct poi {
  int size, mx[11], mn[11];
} x;
set<poi> q;
set<poi>::iterator it;
int n, k;
bool operator<(poi a, poi b) {
  for (int i = 1; i <= k; ++i)
    if (b.mx[i] > a.mn[i]) return 0;
  return 1;
}
bool comp(poi a, poi b) {
  for (int i = 1; i <= k; ++i)
    if (a.mx[i] > b.mn[i]) return 1;
  return 0;
}
poi operator+(poi a, poi b) {
  for (int i = 1; i <= k; ++i) {
    a.mx[i] = max(a.mx[i], b.mx[i]);
    a.mn[i] = min(a.mn[i], b.mn[i]);
  }
  a.size += b.size;
  return a;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      scanf("%d", &x.mx[j]);
      x.mn[j] = x.mx[j];
    }
    x.size = 1;
    for (it = q.lower_bound(x); it != q.end() && comp(*it, x);) {
      x = x + *it;
      it = q.erase(it);
    }
    q.insert(x);
    printf("%d\n", q.begin()->size);
  }
  return 0;
}
