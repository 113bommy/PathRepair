#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int N = 1e5, M = 105, T = 1e7 + 5;
long long maxi[N], l[N], r[N];
pair<long long, long long> f[N];
pair<long long, int> bsd(pair<long long, int> a, pair<long long, int> b) {
  if (a.first > b.first || a.first == b.first && a.second < b.second)
    return a;
  else
    return b;
}
int get(long long n, long long target, long long j) {
  while (j <= n && target > r[j]) ++j;
  return j;
}
int main() {
  long long j = 1, g = 1, n, i, p, t, L;
  cin >> L >> n >> p >> t;
  for (i = 1; i <= n; ++i) cin >> l[i] >> r[i];
  long long target, x;
  for (i = 1; i <= n; i++) {
    maxi[i] = max(maxi[i], maxi[i - 1]);
    f[i] = bsd(f[i], make_pair(maxi[i] + (r[i] - l[i]) / p,
                               l[i] + ((r[i] - l[i]) / p) * p));
    target = f[i].second + t;
    j = get(n, target, j);
    if (j > n) continue;
    if (l[j] >= target) {
      maxi[j] = max(maxi[j], f[i].first);
      continue;
    }
    f[j] = bsd(f[j], make_pair(f[i].first + (r[j] - target) / p,
                               target + ((r[j] - target) / p) * p));
    maxi[j + 1] = max(maxi[j + 1], f[i].first);
  }
  long long ret = 0;
  for (i = 1; i <= n; ++i) ret = max(ret, f[i].first);
  cout << ret << endl;
}
