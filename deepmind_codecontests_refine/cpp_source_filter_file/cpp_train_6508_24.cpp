#include <bits/stdc++.h>
using namespace std;
set<long long int> values;
void states(long long int k) {
  if (values.count(k)) return;
  values.insert(k);
  if (k == 1) return;
  if (k % 2 == 0)
    states(k / 2);
  else {
    states(k / 2);
    states((k / 2) + 1);
  }
}
map<long long int, long long int> M, R, pwr10;
long long int digits[10];
long long int n, b, k, x, a;
bool vis[10001][101];
long long int dp[10001][101];
long long int power(long long int base, long long int exp, long long int md) {
  if (exp == 0) return 1LL;
  long long int root = power(base, exp / 2, md);
  if (exp & 1LL) return (((root * root) % md) * base) % md;
  return (root * root) % md;
}
long long int solve(long long int b, long long int k) {
  if (b == 1 && k <= 9) {
    long long int sum = 0;
    for (long long int i = 0; i <= 9; i++) {
      if (i % x == k) sum += digits[i];
    }
    return sum;
  } else if (b == 1) {
    return 0;
  }
  long long int part1 = (b / 2);
  long long int part2 = (b / 2) + (b % 2 == 1);
  long long int req;
  long long int code = M[b];
  if (vis[code][k]) return dp[code][k];
  long long int& ans = dp[code][k];
  vis[code][k] = true;
  for (long long int i = 0; i < x; i++) {
    long long int first_mod = (i * pwr10[part2]) % x;
    if (first_mod < k) {
      req = k - first_mod;
    } else {
      req = x - (first_mod - k);
    };
    ;
    ans = ans + ((solve(part1, i) * solve(part2, req)) % 1000000007LL);
    if (ans >= 1000000007LL) ans -= 1000000007LL;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  ;
  cin >> n >> b >> k >> x;
  states(b);
  long long int count = 0;
  for (set<long long int>::iterator it = values.begin(); it != values.end();
       it++) {
    pwr10[*it] = power(10, *it, x);
    M[*it] = count;
    R[count] = *it;
    count++;
  }
  for (long long int i = 0; i < n; i++) {
    cin >> a;
    digits[a]++;
  }
  cout << solve(b, k);
  return 0;
}
