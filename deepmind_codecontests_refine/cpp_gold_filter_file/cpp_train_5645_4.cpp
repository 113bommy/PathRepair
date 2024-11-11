#include <bits/stdc++.h>
using namespace std;
vector<long long int> p[300005], q[300005], f(1000005, 0), a(300005, 0),
    h(300005, 0);
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int bpow(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % 998244353;
    a = (a * a) % 998244353;
    b >>= 1;
  }
  return res % 998244353;
}
void fact(long long int i) {
  f[0] = 1;
  for (long long int k = 1; k <= i; k++) {
    (f[k] = f[k - 1] * k) %= 998244353;
  }
}
long long int isprime(long long int n) {
  if (n == 1) return 0;
  for (long long int i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return 0;
  return 1;
}
long long int find(long long int x) {
  if (f[x] == x)
    return x;
  else
    return f[x] = find(f[x]);
}
bool cmp(long long int x, long long int y) { return x < y; }
void check() {
  cout << "HI"
       << "\n";
}
long long int comb(long long int i, long long int j) {
  if (j > i) return 0;
  long long int k = f[i];
  long long int g = (f[j] * (f[i - j]));
  k /= g;
  return k;
}
pair<long double, long double> az(long double a, long double b, long double c,
                                  long double d, long double u) {
  long double x1 = (a - c) * cos(u) - (b - d) * sin(u) + c;
  long double y1 = (a - c) * sin(u) + (b - d) * cos(u) + d;
  return {x1, y1};
}
void merge(long long int i, long long int j) {
  i = find(i);
  j = find(j);
  f[i] = j;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  t = 1;
  while (t--) {
    string s;
    cin >> s;
    long long int k = s.size();
    vector<vector<long long int>> dp(k + 1, vector<long long int>(26, 0));
    for (long long int i = 1; i <= s.size(); i++) {
      for (long long int j = 0; j < 26; j++) {
        dp[i][j] = dp[i - 1][j];
      }
      dp[i][s[i - 1] - 'a']++;
    }
    long long int q;
    cin >> q;
    while (q--) {
      long long int l, r;
      cin >> l >> r;
      vector<long long int> v;
      for (long long int i = 0; i < 26; i++) {
        long long int d = dp[r][i] - dp[l - 1][i];
        if (d > 0) {
          v.push_back(d);
        }
      }
      if (v.size() == 1) {
        if (v[0] == 1) {
          cout << "YES"
               << "\n";
        } else {
          cout << "NO"
               << "\n";
        }
      } else if (v.size() == 2) {
        if (s[l - 1] == s[r - 1]) {
          cout << "NO"
               << "\n";
        } else {
          cout << "YES"
               << "\n";
        }
      } else {
        cout << "YES"
             << "\n";
      }
    }
  }
}
