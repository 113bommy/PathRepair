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
int binPow(int a, int n) {
  int res = 1;
  while (n) {
    if (n & 1) res = (1LL * res * a) % 1000000007;
    a = (1LL * a * a) % 1000000007;
    n >>= 1;
  }
  return res;
}
int ncr(int n, int k, const vector<long long> &fact,
        const vector<long long> &inv) {
  if (k > n) return 0;
  int multiply = (1LL * fact[n] * inv[k]) % 1000000007;
  multiply = (1LL * multiply * inv[n - k]) % 1000000007;
  return multiply;
}
int digit(long long n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n = n / 10;
  }
  return sum;
}
vector<int> result;
void factors(int x) {
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
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  result.clear();
  int a[n], b[m];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  int a1 = 0, ak = 0, b1 = 0, bk = 0, ah = 0, bh = 0;
  factors(k);
  int ans = 0;
  unordered_map<int, int> ma, mb;
  for (int k = 0; k < result.size(); k++) {
    int i = 0, j = 0, sz = 0;
    ak = 0, bk = 0;
    int x = result[k];
    while (i < n && j < n) {
      while (i < n && a[i] != 1) {
        i++;
        j++;
      }
      while (j < n && a[j] == 1 && sz < x) {
        j++;
        sz++;
      }
      if (sz == x) {
        ak++;
        i++;
        sz--;
      } else {
        i = j;
        sz = 0;
      }
    }
    ma[x] = ak;
    i = 0;
    j = 0;
    sz = 0;
    while (i < m && j < m) {
      while (i < m && b[i] != 1) {
        i++;
        j++;
      }
      while (j < m && b[j] == 1 && sz < x) {
        j++;
        sz++;
      }
      if (sz == x) {
        bk++;
        i++;
        sz--;
      } else {
        i = j;
        sz = 0;
      }
    }
    mb[x] = bk;
  }
  for (auto i : ma) {
    int f = i.first, s = i.second;
    int y = k / f;
    ans += s * mb[y];
  }
  cout << ans;
  return 0;
}
