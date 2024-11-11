#include <bits/stdc++.h>
using namespace std;
long long n, M;
long long a[4000];
void calc(long long l, long long r, vector<long long> &res) {
  if (r < l) {
    res.push_back(0);
    return;
  }
  long long m = l;
  for (long long i = l + 1; i < r; ++i)
    if (a[i] < a[m]) m = i;
  vector<long long> res1, res2;
  calc(l, m - 1, res1);
  calc(m + 1, r, res2);
  res.resize(r - l + 2, -1e18);
  for (long long i = 0; i < (long long)res1.size(); ++i)
    for (long long j = 0; j < (long long)res2.size(); ++j) {
      res[i + j] = max(res[i + j], res1[i] + res2[j] - 2 * i * j * a[m]);
      res[i + j + 1] =
          max(res[i + j + 1], res1[i] + res2[j] - 2 * i * j * a[m] +
                                  (M - 1) * a[m] - 2 * (i + j) * a[m]);
    }
}
int32_t main() {
  cin >> n >> M;
  for (long long i = 0; i < n; ++i) cin >> a[i];
  vector<long long> res;
  calc(0, n - 1, res);
  cout << res[M];
}
