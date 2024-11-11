#include <bits/stdc++.h>
using namespace std;
template <class T>
T max(T a, T b, T c) {
  return max(a, max(b, c));
}
template <class T>
T min(T a, T b, T c) {
  return min(a, min(b, c));
}
void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
bool prime[100005];
void SieveOfEratosthenes(long long int n) {
  memset(prime, true, sizeof(prime));
  for (long long int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
}
bool isPrime(long long int n) {
  if (n < 2) return false;
  for (long long int i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
std::vector<long long int> factors(long long int n) {
  std::vector<long long int> f;
  for (long long int i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      f.push_back(i);
      n = n / i;
    }
  }
  if (n > 1) f.push_back(n);
  return f;
}
long long int gcd(long long int a, long long int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long int modpow(long long int x, long long int n, long long int m) {
  if (n == 0) return 1 % m;
  long long int u = modpow(x, n / 2, m);
  u = (u % m * u % m) % m;
  if (n % 2 == 1) u = (u % m * x % m) % m;
  return u % m;
}
long long int eulerstotientfunction(long long int n) {
  long long int ans = n;
  for (long long int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) n = n / i;
      ans -= ans / i;
    }
  }
  if (n > 1) ans -= ans / n;
  return ans;
}
long long int modinverse(long long int x, long long int m) {
  long long int temp = eulerstotientfunction(m);
  return modpow(x, temp - 1, m);
}
long long int ncr(long long int n, long long int k) {
  long long int res = 1;
  k = min(k, n - k);
  for (long long int i = 0; i < k; i++) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}
int main() {
  fastio();
  long long int n;
  cin >> n;
  std::vector<long long int> arr(n + 1);
  for (long long int i = 1; i <= n; i++) cin >> arr[i];
  long long int q;
  cin >> q;
  std::vector<pair<long long int, pair<long long int, long long int> > > qu(q);
  for (long long int i = 0; i < q; i++) {
    cin >> qu[i].first;
    if (qu[i].first == 1)
      cin >> qu[i].second.first >> qu[i].second.second;
    else
      cin >> qu[i].second.first;
  }
  bool is[n + 1];
  memset(is, false, sizeof(is));
  long long int maxnow = -1;
  for (long long int i = q - 1; i >= 0; i--) {
    if (qu[i].first == 1 && !is[qu[i].second.first]) {
      arr[qu[i].second.first] = max(maxnow, qu[i].second.second);
      is[qu[i].second.first] = true;
    } else if (qu[i].first == 2) {
      maxnow = max(maxnow, qu[i].second.first);
    }
  }
  for (long long int i = 1; i <= n; i++) {
    if (!is[i]) arr[i] = max(arr[i], maxnow);
    cout << arr[i] << " ";
  }
  cout << '\n';
}
