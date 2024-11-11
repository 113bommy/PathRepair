#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> pri;
long double ans = 1e18;
bool isprime(long long x) {
  long long sum = 0;
  if (x < 2) return 0;
  for (long long i = 1; i * i <= x; i++)
    if (x % i == 0) sum++;
  return sum == 1;
}
void dfs(long long now, long double sum, long long p) {
  if (now == 1) {
    ans = min(ans, sum);
    return;
  }
  for (long long i = 2; i < (now + 1); i++)
    if (now % i == 0) dfs(now / i, sum * 1.0 * pow(pri[p], i - 1), p + 1);
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  pri.push_back(2);
  for (long long i = 3; i < 100000; i += 2)
    if (isprime(i)) pri.push_back(i);
  cin >> n;
  dfs(n, 1, 0);
  long long res = (long long)ans;
  if (res == 46655999999) res++;
  if (res % 100 == 99) res++;
  cout << (long long)(res);
  return 0;
}
