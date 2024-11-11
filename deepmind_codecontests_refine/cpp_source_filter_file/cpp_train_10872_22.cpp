#include <bits/stdc++.h>
using namespace std;
const long long maxn = 101;
long long t[maxn][maxn];
vector<long long> get(long long n) {
  if (n == 1) return {1};
  if (n == 2) return {3, 4};
  vector<long long> v;
  if (n % 2 == 0) {
    v.push_back((n - 2) / 2);
    for (long long i = 0; i < n - 1; ++i) v.push_back(1);
  } else {
    long long t = -1;
    for (long long x = 1;; ++x) {
      if ((n - 2 + x * x) % 2 || (n - 2 + x * x) % 4 == 0) {
        t = x;
        break;
      }
    }
    v.push_back(t);
    t += n - 2;
    for (long long d = 1;; ++d) {
      if (t % d) continue;
      long long a = d, b = t / d;
      if (a > b) swap(a, b);
      if ((b - a) % 2) continue;
      long long y = (b - a) / 2;
      v.push_back(y);
      break;
    }
    for (long long i = 0; i < n - 2; ++i) v.push_back(1);
  }
  return v;
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  long long n, m;
  cin >> n >> m;
  auto a = get(n), b = get(m);
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < m; ++j) {
      cout << a[i] * b[j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
