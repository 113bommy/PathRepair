#include <bits/stdc++.h>
using namespace std;
bool prime[10000002];
bool isPrime(long long n) {
  if (n <= 1) return false;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
long long gcd(long long x, long long y) {
  if (x == 0)
    return y;
  else
    return gcd(y % x, x);
}
long long lcm(long long x, long long y) { return x * y / gcd(x, y); }
void sieve(vector<long long> &v) {
  memset(prime, true, 10000002);
  prime[0] = prime[1] = false;
  for (long long i = 2; i * i < 10000002; i++) {
    if (prime[i] == true) {
      for (long long j = i + i; j < 10000002; j += i) {
        prime[j] = false;
      }
    }
  }
  for (long long i = 0; i < 10000002; i++) {
    if (prime[i] == true) {
      v.push_back(i);
    }
  }
}
long long countDivisor(vector<long long> &v, long long n) {
  for (long long i = 1; i * i <= n; i++) {
    if (i * i == n) {
      v.push_back(i);
    } else if (n % i == 0) {
      v.push_back(i);
      v.push_back(n / i);
    }
  }
}
long long primeFactorization(vector<long long> &v, long long n) {
  while (n % 2 == 0) {
    v.push_back(2);
    n /= 2;
  }
  for (long long i = 3; i * i <= n; i = i + 2) {
    while (n % i == 0) {
      v.push_back(i);
      n = n / i;
    }
  }
  if (n > 2) {
    v.push_back(n);
  }
}
bool isPalindrome(string s) {
  int l = 0;
  int h = s.size() - 1;
  while (l < h) {
    if (s[l++] != s[h--]) {
      return false;
    }
  }
  return true;
}
int main() {
  int n, m;
  cin >> n >> m;
  int a[n], b[m];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  int l = 0, r = 0, c = 0;
  int s1 = a[l], s2 = b[r];
  while (l < n and r < m) {
    if (s1 == s2) {
      c++;
      s1 = 0, s2 = 0;
      l++;
      r++;
      if (l < n and r < m) {
        s1 = a[l];
        s2 = b[r];
      }
    } else {
      if (s1 < s2) {
        l++;
        s1 += a[l];
      } else {
        r++;
        s2 += b[r];
      }
    }
  }
  cout << c + 1 << endl;
}
