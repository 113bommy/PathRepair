#include <bits/stdc++.h>
using namespace std;
long long n, s;
long long k[1000];
vector<pair<long long, long long> > v[1000];
long long ans;
void Solve(int a, int b) {
  vector<pair<long long, long long> > v1, v2;
  long long t;
  long long s1, s2;
  long long p1, p2;
  long long x1, x2;
  int c1, c2;
  int f;
  v1 = v[a];
  v2 = v[b];
  c1 = 0;
  c2 = 0;
  s1 = v1[c1].first;
  s2 = v2[c2].first;
  x1 = 0;
  x2 = 0;
  f = 0;
  while (1) {
    t = min(v1[c1].second, v2[c2].second);
    p1 = x1;
    p2 = x2;
    x1 += s1 * t;
    x2 += s2 * t;
    if (f) {
      if (p1 <= p2 && x1 > x2) {
        ans++;
      } else if (p1 >= p2 && x1 < x2) {
        ans++;
      }
    }
    f = 1;
    if (x1 >= s || x2 >= s) break;
    v1[c1].second -= t;
    if (v1[c1].second == 0) {
      c1++;
      s1 = v1[c1].first;
    }
    v2[c2].second -= t;
    if (v2[c2].second == 0) {
      c2++;
      s2 = v2[c2].first;
    }
  }
}
int main() {
  long long a, b;
  int i, j;
  scanf("%lld %lld", &n, &s);
  for (i = 1; i <= n; i++) {
    scanf("%lld", &k[i]);
    for (j = 1; j <= k[i]; j++) {
      scanf("%lld %lld", &a, &b);
      v[i].push_back(make_pair(a, b));
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = i + 1; j <= n; j++) {
      Solve(i, j);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
