#include <bits/stdc++.h>
const long long INFLL = (1LL << 62);
const int INFINT = 2000000000;
using namespace std;
struct HASH {
  size_t operator()(const pair<int, int> &x) const {
    return ((long long)x.first) ^ (((long long)x.second) << 32);
  }
};
void die() {
  cout << "NO";
  exit(0);
}
const int NMAX = 2 * 1e3 + 5;
const int MOD = 1e9 + 7;
const double PI = atan(1) * 4;
const double EPS = 1e-12;
long long n, m, k;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> k;
  long long l = 1, r = n * m;
  if (n > m) swap(n, m);
  while (l < r) {
    long long mid = (l + r) / 2, sum = 0;
    for (int i = 1; i <= n; i++) sum += min(m, mid / i);
    if (sum >= k)
      r = mid;
    else
      l = mid + 1;
  }
  cout << l;
  return 0;
}
