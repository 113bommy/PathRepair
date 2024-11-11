#include <bits/stdc++.h>
using namespace std;
int f[200005];
int Find(int first) {
  if (f[first] == first) return first;
  return f[first] = Find(f[first]);
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  long long a[200005];
  long long Min = 1e12, Mini = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    if (a[i] < Min) {
      Min = a[i];
      Mini = i;
    }
  }
  pair<long long, pair<int, int> > p[200005];
  for (int i = 0; i < m; i++) {
    int first, second;
    long long w;
    scanf("%d %d %lld", &first, &second, &w);
    p[i] = make_pair((w), (make_pair((first), (second))));
  }
  for (int i = 1; i <= n; i++) {
    f[i] = i;
  }
  sort(p, p + m);
  long long ans = 0;
  for (int i = 0; i < m; i++) {
    int fx = Find(p[i].second.first);
    int fy = Find(p[i].second.second);
    if (fx != fy) {
      long long Max = max(a[fx], a[fy]);
      if (Max + Min > p[i].first) {
        ans += p[i].first;
        if (a[fx] > a[fy])
          f[fx] = fy;
        else
          f[fy] = fx;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i != Mini && Find(i) == i) {
      ans += Min + a[i];
    }
  }
  printf("%lld\n", ans);
  return 0;
}
