#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
long long a[N];
long long b[N];
long long l[N];
long long r[N];
long long x[N];
vector<pair<long long, long long> > rg;
const long long INF = 3000000000000000000ll;
int main() {
  int n;
  long long t;
  scanf("%d%lld", &n, &t);
  const long long M = INF - t;
  for (long long i = 1; i <= n; i++) {
    l[i] = 0;
    r[i] = M;
  }
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", a + i);
  }
  a[0] = 0;
  a[n + 1] = M;
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", x + i);
  }
  for (long long i = 1; i <= n; i++) {
    if (x[i] < i) {
      puts("No");
      exit(0);
    }
    l[x[i]] = a[i];
    r[x[i]] = a[x[i] + 1] - 1;
    if (i + 1 <= x[i]) {
      if (rg.empty() || i + 1 > rg.back().second + 1) {
        rg.push_back({i + 1, x[i]});
      } else {
        rg.back().second = max(rg.back().second, x[i]);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    l[i] = max(l[i], a[i]);
  }
  for (auto x : rg) {
    for (int i = x.first; i <= x.second; i++) {
      l[i - 1] = min(l[i - 1], a[i]);
    }
  }
  for (int i = n; i >= 1; i--) {
    if (l[i] <= r[i]) {
      b[i] = r[i];
      r[i - 1] = min(r[i - 1], r[i] - 1);
    } else {
      puts("No");
      exit(0);
    }
  }
  puts("Yes");
  for (int i = 1; i <= n; i++) {
    printf("%lld ", b[i] + t);
  }
  puts("");
  return 0;
}
