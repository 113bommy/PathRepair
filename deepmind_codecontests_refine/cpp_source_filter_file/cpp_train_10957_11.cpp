#include <bits/stdc++.h>
using namespace std;
const double pi = 3.141592653689793238460;
const long long inf = 0x3f3f3f3f3f3f;
const int N = 2e5 + 5;
const int pr = 31;
using ld = long double;
int mod = 1e9 + 7;
long long gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(int a, int b) { return (a / gcd(a, b)) * b; }
int fact(int n) {
  int res = 1;
  for (int i = 2; i <= n; i++) res = res * i % mod;
  return res % mod;
}
int ncr(int n, int r) { return fact(n) / (fact(r) * fact(n - r)); }
long long power(long long x, unsigned int y, int p) {
  int res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long nCr(long long n, long long k) {
  long long C[105][1005];
  long long i, j;
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= min(i, k); j++) {
      if (j == 0 || j == i)
        C[i][j] = 1;
      else
        C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]);
    }
  }
  return C[n][k];
}
unsigned int setbit(long long n) {
  unsigned long long count = 0;
  while (n) {
    n &= (n - 1);
    count++;
  }
  return count;
}
int sub(string s1, string s2) {
  int M = s1.length();
  int N = s2.length();
  for (int i = 0; i <= N - M; i++) {
    int j;
    for (j = 0; j < M; j++)
      if (s2[i + j] != s1[j]) break;
    if (j == M) return i;
  }
  return -1;
}
unsigned P2(unsigned x) {
  x |= x >> 1;
  x |= x >> 2;
  x |= x >> 4;
  x |= x >> 8;
  x |= x >> 16;
  return x ^ (x >> 1);
}
long long phi(long long n) {
  long long result = n;
  for (long long i = 2; (long long)i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      result -= result / i;
    }
  }
  if (n > 1) {
    result -= result / n;
  }
  return result;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<int> ans;
    for (int i = 0; i < (int)n - 1; i++) {
      if (b[i] != b[i + 1]) {
        ans.push_back(i + 1);
      }
    }
    string s;
    if (b[0] == '0') {
      if (ans.size() % 2 == 0) {
        for (int i = 0; i < (int)n; i++) s.push_back('0');
      } else {
        for (int i = 0; i < (int)n; i++) s.push_back('1');
      }
    } else {
      if (ans.size() % 2 == 0) {
        for (int i = 0; i < (int)n; i++) s.push_back('1');
      } else {
        for (int i = 0; i < (int)n; i++) s.push_back('0');
      }
    }
    char c = s[n - 1];
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] != c) {
        ans.push_back(i + 1);
        c = '0' + 1 - (c - '0');
      }
    }
    cout << ans.size() << " ";
    for (int i = 0; i < (int)ans.size(); i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }
}
