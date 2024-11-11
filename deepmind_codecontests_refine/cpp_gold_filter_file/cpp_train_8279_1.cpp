#include <bits/stdc++.h>
using namespace std;
int p;
map<pair<long long, long long>, long long> a;
void r(long long u, long long w) {
  while (u != w) {
    if (w > u) {
      a[make_pair(w, w / 2)] += p;
      w /= 2;
    } else {
      a[make_pair(u, u / 2)] += p;
      u /= 2;
    }
  }
}
long long s(long long u, long long w) {
  long long t = 0;
  while (u != w) {
    if (w > u) {
      t += a[make_pair(w, w / 2)];
      w /= 2;
    } else {
      t += a[make_pair(u, u / 2)];
      u /= 2;
    }
  }
  return t;
}
int main() {
  int n, k;
  long long u, w;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &k);
    if (k == 1) {
      scanf("%I64d %I64d %d", &u, &w, &p);
      r(u, w);
    } else {
      scanf("%I64d %I64d", &u, &w);
      printf("%I64d\n", s(u, w));
    }
  }
}
