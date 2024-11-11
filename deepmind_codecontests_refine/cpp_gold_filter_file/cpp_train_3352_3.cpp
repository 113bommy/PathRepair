#include <bits/stdc++.h>
using namespace std;
struct even {
  int type, id;
  long long t;
  even(long long x = 0, int y = 0, int z = 0) {
    t = x;
    type = y;
    id = z;
  }
} mid;
bool operator<(even a, even b) {
  if (a.t == b.t) return a.type < b.type || a.type == b.type && a.id < b.id;
  return a.t < b.t;
}
set<even> s;
set<int> iq, wai;
int n, p, l, m1;
long long cur, qt, ans[1000000];
void print() {
  for (auto i : s) {
    printf("(%d %d %d)\n", i.t, i.type, i.id);
  }
  printf("\niq:");
  for (auto i : iq) printf("%d ", i);
  printf("\nwai:");
  for (auto i : wai) printf("%d ", i);
  printf("\nans:");
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  printf("\n------------\n");
}
int main() {
  scanf("%d%d", &n, &p);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &m1);
    s.insert(even(m1, 0, i));
  }
  while (!s.empty()) {
    mid = *s.begin();
    s.erase(mid);
    cur = mid.t;
    if (mid.type == 0) {
      if (iq.empty() || *iq.begin() > mid.id) {
        iq.insert(mid.id);
        qt = max(qt + p, mid.t + p);
        s.insert(even(qt, 1, mid.id));
      } else
        wai.insert(mid.id);
    } else {
      ans[mid.id] = mid.t;
      iq.erase(mid.id);
      if (!wai.empty() && iq.empty()) {
        m1 = *wai.begin();
        wai.erase(m1);
        qt = max(qt, cur) + p;
        iq.insert(m1);
        s.insert(even(qt, 1, m1));
      }
    }
  }
  for (int i = 1; i <= n; i++) printf("%I64d ", ans[i]);
}
