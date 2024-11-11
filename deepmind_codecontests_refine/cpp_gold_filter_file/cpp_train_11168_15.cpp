#include <bits/stdc++.h>
using namespace std;
vector<long long int> ar[1000001];
long long int vis[1000001], dis[1000001], level[1000001];
const int MAX_SIZE = 1000001;
const int N = 2000010;
const int mod = 1e9 + 7;
vector<int> isprime(MAX_SIZE, true);
vector<int> prime;
vector<int> SPF(MAX_SIZE);
long long int fact[N];
void manipulated_seive(int N) {
  isprime[0] = isprime[1] = false;
  for (int i = 2; i < N; ++i) {
    if (isprime[i]) {
      prime.push_back(i);
      SPF[i] = i;
    }
    for (int j = 0;
         j < (int)prime.size() && i * prime[j] < N && prime[j] <= SPF[i]; ++j) {
      isprime[i * prime[j]] = false;
      SPF[i * prime[j]] = prime[j];
    }
  }
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
unordered_map<long long int, long long int> myp;
void primeFactors(long long int n) {
  while (n % 2 == 0) {
    myp[2]++;
    n = n / 2;
  }
  for (long long int i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      myp[i]++;
      n = n / i;
    }
  }
  if (n > 2) myp[n]++;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int findlcm(long long int a, long long int b) {
  return a * b / gcd(a, b);
}
long long int power(long long int a, long long int b) {
  long long int res = 1;
  while (b) {
    if (b % 2) res *= a;
    a *= a;
    b /= 2;
  }
  return res;
}
long long int power_mod(long long int a, long long int b, long long int p) {
  long long int res = 1;
  while (b) {
    if (b % 2) {
      res *= a;
      res %= p;
    }
    a *= a;
    a %= p;
    b /= 2;
  }
  return res;
}
long long int mod_inverse(long long int x) {
  return power_mod(x, mod - 2, mod);
}
long long int nCr(long long int n, long long int r) {
  if (r == 0) return 1;
  long long int a = fact[n];
  long long int b = mod_inverse(fact[n - r]);
  long long int c = mod_inverse(fact[r]);
  return (((a * b) % mod) * c) % mod;
}
void fun() {}
int main() {
  long long int n;
  cin >> n;
  long long int p;
  long long int ans[n];
  for (long long int i = 2; i <= n; i++) {
    cout << "? " << 1 << " " << i << '\n';
    cin >> p;
    ans[i - 1] = p;
  }
  for (long long int i = n - 1; i > 1; i--) {
    ans[i] = ans[i] - ans[i - 1];
  }
  cout << "? " << 2 << " " << 3 << '\n';
  cin >> p;
  long long int temp = ans[1];
  ans[1] = p - ans[2];
  ans[0] = temp - ans[1];
  cout << "! ";
  for (long long int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << '\n';
  return 0;
}
