#include <bits/stdc++.h>
using namespace std;
long long expo(long long a, long long b, long long m) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % m;
    a = (a * a) % m;
    b = b >> 1;
  }
  return res;
}
long long mminvprime(long long a, long long b) { return expo(a, b - 2, b); }
long long mod_add(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long mod_mul(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long mod_sub(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
long long mod_div(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (mod_mul(a, mminvprime(b, m), m) + m) % m;
}
vector<int> factors(int x) {
  vector<int> result;
  int i = 1;
  while (i * i <= x) {
    if (x % i == 0) {
      result.push_back(i);
      if (x / i != i) {
        result.push_back(x / i);
      }
    }
    i++;
  }
  return result;
}
bool compare(const pair<int, int>& i, const pair<int, int>& j) {
  return i.second < j.second;
}
long long pow(long long a, long long b, long long m) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return ans;
}
vector<long long> pr;
void sieve(long long n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (long long p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (long long p = 2; p <= n; p++)
    if (prime[p]) pr.push_back(p);
}
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
void leftRotate(int arr[], int d, int n) {
  d = d % n;
  int g_c_d = gcd(d, n);
  for (int i = 0; i < g_c_d; i++) {
    int temp = arr[i];
    int j = i;
    while (1) {
      int k = j + d;
      if (k >= n) k = k - n;
      if (k == i) break;
      arr[j] = arr[k];
      j = k;
    }
    arr[j] = temp;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int x, y;
    cin >> x >> y;
    for (int i = 1; i <= n; i++) {
      if (i % 2 != 0) {
        for (int j = 1; j <= m; j++) {
          int tmp1 = (i + x - 2) % n + 1;
          int tmp2 = (j + y - 2) % m + 1;
          cout << tmp1 << " " << tmp2 << endl;
        }
      } else {
        for (int j = m; j >= 1; j--) {
          int tmp1 = (i + x - 2) % n + 1;
          int tmp2 = (j + y - 2) % m + 1;
          cout << tmp1 << " " << tmp2 << endl;
        }
      }
    }
  }
  return 0;
}
