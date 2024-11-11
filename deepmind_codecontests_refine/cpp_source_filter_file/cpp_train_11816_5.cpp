#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > v;
long long ng;
vector<long long> dp(2000 + 2, -1);
vector<long long> fact(100005);
long long power(long long x, long long n) {
  if (n == 0) return 1;
  if (n % 2 == 0) return power((x * x) % 1000000007, n / 2);
  return (x * power((x * x) % 1000000007, n / 2)) % 1000000007;
}
long long inv(long long x) { return power(x, 1000000007 - 2); }
long long ncr(long long n, long long r) {
  long long temp;
  temp = (fact[r] * fact[n - r]) % 1000000007;
  temp = inv(temp);
  temp = (fact[n] * temp) % 1000000007;
  return temp;
}
long long calc(long long n) {
  if (dp[n] != -1) return dp[n];
  long long x = v[n].first, y = v[n].second, curr, temp, i;
  curr = ncr(x + y - 2, x - 1);
  for (i = 1; i <= ng; ++i) {
    if (v[i].first > x || v[i].second > y || i == n) continue;
    temp = (calc(i) * ncr(x + y - v[i].first - v[i].second, x - v[i].first)) %
           1000000007;
    curr -= temp;
    curr = (curr + 1000000007) % 1000000007;
  }
  return dp[n] = curr;
}
int main() {
  long long t, t1, t2, m, i, j, k, temp, curr, l, sum, ans, q, x, y, z,
      flag = 0, w, h;
  fact[0] = 1;
  for (i = 1; i <= 100001; ++i) fact[i] = (i * fact[i - 1]) % 1000000007;
  cin >> h >> w >> ng;
  v.resize(ng + 1);
  for (i = 1; i <= ng; ++i) {
    cin >> x >> y;
    v[i] = {x, y};
  }
  v.push_back(make_pair(h, w));
  ng++;
  cout << calc(ng);
  return 0;
}
