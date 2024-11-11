#include <bits/stdc++.h>
using namespace std;
const int N = 1000000;
bool primes[N + 1];
void create_seive() {
  for (int i = 2; i <= N; i++) {
    primes[i] = true;
  }
  for (int i = 2; i * i <= N; i++) {
    if (primes[i]) {
      for (int j = i * i; j <= N; j += i) {
        primes[j] = false;
      }
    }
  }
}
long long int spf[N + 1];
void create_spf() {
  for (int i = 2; i <= N; i++) {
    spf[i] = i;
  }
  for (int i = 2; i * i <= N; i++) {
    if (spf[i] == i) {
      for (int j = i * i; j <= N; j += i) {
        if (spf[j] == j) {
          spf[j] = i;
        }
      }
    }
  }
}
long long int gcd(long long int a, long long int b) {
  if (b > a) return gcd(b, a);
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int power(long long int a, long long int p) {
  long long int res = 1;
  while (p) {
    if (p % 2 == 0) {
      a = a * 1ll * a % 1000000007;
      p /= 2;
    } else {
      res = res * 1ll * a % 1000000007;
      p--;
    }
  }
  return res;
}
void sieve(long long int n, vector<long long int> prime) {
  for (long long int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
}
long long int fact(long long int n) {
  long long int res = 1;
  for (long long int i = 1; i <= n; i++) {
    res = res * 1ll * i % 1000000007;
  }
  return res;
}
long long int comb(long long int n, long long int k) {
  return fact(n) * 1ll * power(fact(k), 1000000007 - 2) % 1000000007 * 1ll *
         power(fact(n - k), 1000000007 - 2) % 1000000007;
}
long long int to_integer(string &aa) {
  long long int res = 0;
  for (auto x : aa) res = (res * 10) + (x - '0');
  return res;
}
bool prime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
vector<long long int> a(100000, 1);
long long int modd = 1e9 + 7;
int solve() {
  long long int n;
  char c;
  string s;
  cin >> n >> c >> s;
  unordered_map<int, char> mapp;
  int same = 1;
  for (int i = 0; i < n; i++) {
    mapp[i + 1] = s[i];
    if (s[i] != c) {
      same = 0;
    }
  }
  if (same) {
    cout << "0" << endl;
  } else {
    for (int x = 1; x <= n; x++) {
      int m = x;
      int flag = 0;
      while (m <= n) {
        if (mapp[m] != c) {
          flag = 1;
          break;
        }
        m += x;
      }
      if (x <= n && flag == 0) {
        cout << "1" << endl;
        cout << x << endl;
        return 0;
      }
    }
    cout << "2" << endl;
    cout << n - 1 << " " << n << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
