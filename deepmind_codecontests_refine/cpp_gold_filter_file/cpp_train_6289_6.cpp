#include <bits/stdc++.h>
using namespace std;
const long long N = 15e4 + 5, mod = 998244353;
long long n, y, o, e, m, bit, a, b[N], p[N];
vector<pair<long long, long long>> ans;
string s, t;
bool mk[N];
long long bin_chk(long long x, long long aa, long long sum = 0) {
  for (long long i = 0; i < x; i++) {
    if (b[n - x + i] < p[i]) {
      aa -= p[i] - b[n - x + i];
    }
    sum += p[i];
  }
  if (aa < 0) return 0;
  y = 0;
  y = sum < a;
  return sum - (sum < a ? sum : a) + 1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> a;
  for (long long i = 0; i < n; i++) cin >> b[i];
  for (long long i = 0; i < m; i++) cin >> p[i];
  sort(b, b + n);
  sort(p, p + m);
  long long l = 0, r = min(m, n) + 1;
  while (r != l + 1) {
    long long mid = (l + r) / 2;
    if (bin_chk(mid, a))
      l = mid;
    else
      r = mid;
  }
  if (bin_chk(l, a) - y == -2) return cout << 1 << " " << 0, 0;
  cout << l << ' ' << bin_chk(l, a) - 1;
}
