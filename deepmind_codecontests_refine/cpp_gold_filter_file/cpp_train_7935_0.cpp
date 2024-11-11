#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000007;
const long long INFL = 1e15;
void printv(vector<int> a) {
  for (int i = 0; i < (int)a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}
long long fact_pow(long long n, long long k) {
  long long res = 0;
  while (n) {
    n /= k;
    res += n;
  }
  return res;
}
vector<int> allprime(long long n) {
  vector<char> prime(n + 1, true);
  prime[0] = prime[1] = false;
  for (int i = 2; i <= n; ++i)
    if (prime[i])
      if (i * 1ll * i <= n)
        for (int j = i * i; j <= n; j += i) prime[j] = false;
  vector<int> ans;
  for (int i = 2; i < n + 1; i++) {
    if (prime[i]) ans.push_back(i);
  }
  return ans;
}
long long binpow(long long a, long long n, long long m = 1e18 + 9) {
  if (n == 0) return 1;
  if (n % 2 == 1)
    return (binpow(a, n - 1) * a);
  else {
    long long b = binpow(a, n / 2);
    return (b * b);
  }
}
long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
long long max(long long a, long long b) {
  if (a > b)
    return a;
  else
    return b;
}
long long min(long long a, long long b) {
  if (a > b)
    return b;
  else
    return a;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<int> b = allprime(32);
  long long t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), g(11, 0);
    vector<int> c(n, 0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      for (int j = 0; j < 11; j++) {
        if (a[i] % b[j] == 0) {
          if (g[j] != 0) {
            c[i] = g[j];
          } else {
            ans++;
            c[i] = ans;
            g[j] = ans;
          }
          break;
        }
      }
    }
    cout << ans << endl;
    printv(c);
  }
  return 0;
}
