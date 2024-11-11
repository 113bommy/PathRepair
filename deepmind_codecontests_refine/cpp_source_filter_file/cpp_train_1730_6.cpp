#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
void init_ios() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}
const long long N = (long long)1e6 + 10;
long long n, x, y, a[N], wys[N], sum[N];
bool zloz[N];
vector<long long> pr;
signed main() {
  init_ios();
  for (long long i = 2; i < N - 5; ++i)
    if (!zloz[i]) {
      pr.push_back(i);
      for (long long j = 2 * i; j < N - 5; j += i) zloz[j] = true;
    }
  cin >> n >> x >> y;
  long long t = x / y;
  for (long long i = 1; i <= n; ++i) {
    cin >> a[i];
    wys[a[i]]++;
  }
  for (long long i = 1; i < N - 5; ++i) {
    sum[i] = sum[i - 1] + i * wys[i];
    wys[i] += wys[i - 1];
  }
  long long cnt = 0, cena = 0, res = 1e18;
  for (long long p : pr) {
    long long hm = 0, cen = 0;
    for (long long j = p; j < N - 5; j += p) {
      long long l = max(j - p + 1, j - t);
      long long ile = wys[j] - wys[l - 1];
      hm += ile;
      cen += y * (ile * j - (sum[j] - sum[l - 1]));
    }
    cen += (n - hm) * x;
    res = min(res, cen);
  }
  cout << res << "\n";
}
