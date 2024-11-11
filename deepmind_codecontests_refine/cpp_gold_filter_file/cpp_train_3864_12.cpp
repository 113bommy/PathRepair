#include <bits/stdc++.h>
using namespace std;
bool isprime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
vector<long long int> prime;
void sieve(long long int n) {
  bool bakh[n + 1];
  memset(bakh, true, sizeof(bakh));
  for (long long int p = 2; p * p <= n; p++) {
    if (bakh[p] == true) {
      for (long long int i = p * p; i <= n; i += p) bakh[i] = false;
    }
  }
  for (long long int p = 2; p <= n; p++)
    if (bakh[p]) prime.push_back(p);
}
long long int eulertotient(long long int z) {
  long long int fac = z;
  for (long long int i = 0; prime[i] * prime[i] <= z; i++) {
    if (z % prime[i] == 0) {
      fac -= (fac / prime[i]);
      while (z % prime[i] == 0) z /= prime[i];
    }
  }
  if (z > 1) fac -= (fac / z);
  return fac;
}
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long int lcm(long long int a, long long int b) {
  long long int g = gcd(a, b);
  long long int ans = (a * b) / g;
  return ans;
}
long long int modInverse(long long int a, long long int m) {
  long long int hvf = gcd(a, m);
  if (hvf == 1) return power(a, m - 2, m);
  return -1;
}
void multiply(long long int F[2][2], long long int M[2][2]) {
  long long int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
  long long int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
  long long int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
  long long int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];
  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}
void powermat(long long int F[2][2], long long int n) {
  if (n == 0 || n == 1) return;
  long long int M[2][2] = {{1, 1}, {1, 0}};
  powermat(F, n / 2);
  multiply(F, F);
  if (n % 2 != 0) multiply(F, M);
}
long long int fib(long long int n) {
  long long int F[2][2] = {{1, 1}, {1, 0}};
  if (n == 0) return 0;
  powermat(F, n - 1);
  return F[0][0];
}
vector<long long int> merge(vector<long long int> v1,
                            vector<long long int> v2) {
  vector<long long int> temp;
  long long int i = 0, j = 0;
  while (i < v1.size() && j < v2.size()) {
    if (v1[i] < v2[j])
      temp.push_back(v1[i]), i++;
    else
      temp.push_back(v2[j]), j++;
  }
  while (i < v1.size()) temp.push_back(v1[i]), i++;
  while (j < v2.size()) temp.push_back(v2[j]), j++;
  return temp;
}
long long int dp[1005][2005][4];
long long int n, k;
long long int fun(long long int id, long long int move, long long int diff) {
  if (move > k) return 0;
  if (id == n) return move == k;
  if (dp[id][move][diff] != -1) return dp[id][move][diff];
  long long int a;
  if (diff == 0) {
    a = (fun(id + 1, move, 0)) +
        (fun(id + 1, move + 1, 1) + fun(id + 1, move + 1, 2) +
         fun(id + 1, move + 1, 3)) %
            998244353;
  } else if (diff == 1) {
    a = (fun(id + 1, move, 0) % 998244353 + fun(id + 1, move, 1) % 998244353 +
         fun(id + 1, move + 2, 2) % 998244353 +
         fun(id + 1, move, 3) % 998244353) %
        998244353;
  } else if (diff == 2) {
    a = (fun(id + 1, move, 0) % 998244353 +
         fun(id + 1, move + 2, 1) % 998244353 +
         fun(id + 1, move, 2) % 998244353 + fun(id + 1, move, 3) % 998244353) %
        998244353;
  } else {
    a = (fun(id + 1, move + 1, 0) % 998244353 +
         fun(id + 1, move + 1, 1) % 998244353 +
         fun(id + 1, move + 1, 2) % 998244353 +
         fun(id + 1, move, 3) % 998244353) %
        998244353;
  }
  return dp[id][move][diff] = a % 998244353;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cin >> n >> k;
  long long int ans = 0;
  if (n == 1) {
    if (k == 1)
      return cout << 2 << endl, 0;
    else if (k == 2)
      return cout << 2 << endl, 0;
    else
      return cout << 0 << endl, 0;
  }
  memset(dp, -1, sizeof(dp));
  ans = (fun(1, 1, 0) % 998244353 + fun(1, 2, 1) % 998244353 +
         fun(1, 2, 2) % 998244353 + fun(1, 1, 3) % 998244353) %
        998244353;
  cout << ans << endl;
}
