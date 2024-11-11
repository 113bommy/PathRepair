#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long N = 200005;
vector<long long> vis(N);
vector<vector<long long>> adj(N);
void dfs(long long v) {
  vis[v] = 1;
  for (auto i : adj[v]) {
    if (!vis[i]) {
      dfs(i);
    }
  }
  return;
}
bool isPrime(long long n) {
  if (n < 2) return false;
  for (long long i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
long long factorial(long long n) {
  return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
}
long long power(long long x, long long y) {
  long long res = 1;
  x = x;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res % mod;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b) * b); }
long long max(long long a, long long b) {
  long long ans = a > b ? a : b;
  return ans;
}
long long min(long long a, long long b) {
  long long ans = a < b ? a : b;
  return ans;
}
long long root(long long a[], long long i) {
  while (a[i] != i) {
    a[i] = a[a[i]];
    i = a[i];
  }
  return i;
}
void unionn(long long a[], long long i, long long j) {
  long long root_i = root(a, i);
  long long root_j = root(a, j);
  a[root_i] = root_j;
  return;
}
void fun() {}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  fun();
  long long tt = 1;
  while (tt--) {
    long long k;
    cin >> k;
    string a;
    cin >> a;
    long long n = a.size();
    if (n % k) {
      string s = "1";
      for (long long i = 1; i < k; i++) s += '0';
      long long m = n / k;
      string ans = s;
      for (long long i = 0; i < m; i++) ans += s;
      cout << ans << "\n";
    } else {
      string t = a.substr(0, k);
      string s = "";
      long long m = n / k;
      for (long long i = 0; i < m; i++) s += t;
      if (s > a)
        cout << s << "\n";
      else {
        long long j = -1;
        for (long long i = k - 1; i >= 0; i--) {
          if (a[i] != '9') {
            j = i;
            break;
          }
        }
        if (j == -1) {
          string s = "1";
          for (long long i = 1; i < k; i++) s += '0';
          long long m = n / k;
          string ans = s;
          for (long long i = 0; i < m; i++) ans += s;
          cout << ans << "\n";
        } else {
          string t = a.substr(0, k);
          t[j]++;
          for (long long i = j + 1; i < k; i++) t[i] = '0';
          long long m = n / k;
          string ans = t;
          for (long long i = 0; i < m - 1; i++) ans += t;
          cout << ans << "\n";
        }
      }
    }
  }
  return 0;
}
