#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w,
    x, y, z;
long long ans = 0, sum = 0, mn = 1e18, mx = 0, cnt = 0;
const long long M = 1000000007;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
int main() {
  cin >> n >> m >> k;
  vector<long long> vec(n);
  vector<long long> zeros(n + 1);
  vector<int> freq(m + 2);
  vector<pair<pair<int, int>, int>> ops;
  for (int i = 0; i < n; i++) cin >> vec[i];
  for (int i = 0; i < m; i++) {
    cin >> l >> r >> d;
    ops.push_back({{l, r}, d});
  }
  for (int i = 0; i < k; i++) {
    cin >> x >> y;
    freq[x] += 1;
    freq[y + 1] -= 1;
  }
  for (int i = 1; i <= m; i++) freq[i] += freq[i - 1];
  for (int i = 1; i <= m; i++) {
    zeros[ops[i - 1].first.first - 1] += (ops[i - 1].second * freq[i]);
    zeros[ops[i - 1].first.second] -= (ops[i - 1].second * freq[i]);
  }
  for (int i = 1; i < n; i++) zeros[i] += zeros[i - 1];
  for (int i = 0; i < n; i++) vec[i] += zeros[i];
  for (auto i : (vec)) cout << i << " ";
  cout << endl;
  return 0;
}
