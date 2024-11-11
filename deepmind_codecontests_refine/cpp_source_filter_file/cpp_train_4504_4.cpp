#include <bits/stdc++.h>
using namespace std;
using namespace std;
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
  cerr << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args) {
  const char *comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
long long gcd(long long a, long long b) {
  if (a < b)
    return gcd(b, a);
  else if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long isPrime(long long n) {
  long long p = (long long)sqrt(n);
  for (long long i = 2; 2 < p + 1 ? i < p + 1 : i > p + 1;
       2 < p + 1 ? i += 1 : i -= 1)
    if (n % i == 0) return 0;
  return 1;
}
long long pow(long long b, long long e) {
  if (e == 0)
    return 1;
  else if (e % 2 == 0) {
    long long a = pow(b, e / 2);
    return a * a;
  } else {
    long long a = pow(b, e / 2);
    return b * a * a;
  }
}
long long pow_m(long long x, long long y, long long m = 1000000007) {
  x = x % m;
  long long res = 1;
  while (y) {
    if (y & 1) res = res * x;
    res %= m;
    y = y >> 1;
    x = x * x;
    x %= m;
  }
  return res;
}
long long modInverse(long long a, long long m) { return pow_m(a, m - 2, m); }
long long max(long long a, long long b) {
  if (a >= b)
    return a;
  else
    return b;
}
long long min(long long a, long long b) {
  if (a <= b)
    return a;
  else
    return b;
}
long long sum(vector<long long> v) {
  long long sm = 0;
  for (long long i = 0; 0 < v.size() ? i < v.size() : i > v.size();
       0 < v.size() ? i += 1 : i -= 1)
    sm += v[i];
  return sm;
}
long long bin_coff(long long n, long long k, long long m) {
  vector<vector<long long> > ans(n + 1, vector<long long>(k, 0));
  for (long long i = 0; 0 < n + 1 ? i < n + 1 : i > n + 1;
       0 < n + 1 ? i += 1 : i -= 1) {
    for (long long j = 0;
         0 < min(i, k) + 1 ? j < min(i, k) + 1 : j > min(i, k) + 1;
         0 < min(i, k) + 1 ? j += 1 : j -= 1) {
      if (j == 0 || j == i)
        ans[i][j] = 1;
      else
        ans[i][j] = ans[i - 1][j - 1] % m + ans[i - 1][j] % m;
    }
  }
  return ans[n][k] % m;
}
long long inverse(long long i) {
  if (i == 1) return 1;
  return (1000000007 -
          ((1000000007 / i) * inverse(1000000007 % i)) % 1000000007 +
          1000000007) %
         1000000007;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  long long ans = 0;
  long long arr[n][m];
  for (long long i = 0; 0 < n ? i < n : i > n; 0 < n ? i += 1 : i -= 1) {
    for (long long j = 0; 0 < m ? j < m : j > m; 0 < m ? j += 1 : j -= 1) {
      cin >> arr[i][j];
      if ((i == 0 && j == 0) || (i == 0 && j == m - 1) ||
          (i == n - 1 && j == 0) || (i == n - 1 && j == m - 1)) {
        if (arr[i][j] > 2) ans = 1;
      } else if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
        if (arr[i][j] > 3) ans = 1;
      } else {
        if (arr[i][j] > 4) ans = 1;
      }
    }
  }
  if (ans == 1) {
    cout << "0" << endl;
    return;
  }
  cout << "YES" << endl;
  for (long long i = 0; 0 < n ? i < n : i > n; 0 < n ? i += 1 : i -= 1) {
    for (long long j = 0; 0 < m ? j < m : j > m; 0 < m ? j += 1 : j -= 1) {
      if ((i == 0 && j == 0) || (i == 0 && j == m - 1) ||
          (i == n - 1 && j == 0) || (i == n - 1 && j == m - 1)) {
        cout << "2"
             << " ";
      } else if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
        cout << "3"
             << " ";
      } else
        cout << "4"
             << " ";
    }
    cout << endl;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long T;
  cin >> T;
  while (T--) solve();
  return 0;
}
