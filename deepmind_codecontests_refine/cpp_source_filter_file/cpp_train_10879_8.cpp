#include <bits/stdc++.h>
using namespace std;
template <class T>
bool uax(T& a, const T& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool uin(T& a, const T& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
long long mulmod(long long a, long long b, long long m) {
  if (!a || !b) return 0;
  if (a & 1) return (b + mulmod(a - 1, b, m)) % m;
  return (mulmod(a / 2, b, m) * 2) % m;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, k, l;
  cin >> n >> l >> k;
  long long MOD = 1e9 + 7;
  vector<int> a(n);
  vector<int> p(n);
  for (int i = 0; i < (int)(n); ++i) {
    cin >> a[i];
    p[i] = i;
  }
  sort((p).begin(), (p).end(),
       [&](const int& lhs, const int& rhs) { return a[lhs] < a[rhs]; });
  vector<vector<long long> > dp(n, vector<long long>(k + 1, 0));
  for (int i = 0; i < (int)(n); ++i) {
    dp[i][1] = 1;
  }
  for (int j = (int)(2); j <= (int)(k); ++j) {
    long long sum = 0;
    int ptr = 0;
    for (int i = 0; i < (int)(n); ++i) {
      while (ptr < n && a[p[ptr]] <= a[i]) {
        sum = (sum + dp[p[ptr]][j - 1]) % MOD;
        ptr++;
      }
      dp[i][j] = sum;
    }
  }
  long long c = (long long)ceil((long double)l / n);
  long long x = (long long)(l - 1) % (long long)n;
  cerr << "c: " << c << endl;
  cerr << "x: " << x << endl;
  long long ans1 = 0;
  for (int j = (int)(1); j <= (int)(min(c, k)); ++j) {
    long long sum = 0;
    for (int i = (int)(0); i <= (int)(x); ++i) {
      sum = (sum + dp[i][j]) % MOD;
    }
    ans1 = (ans1 + mulmod(sum, c - (long long)j + 1, MOD)) % MOD;
  }
  cerr << "ans1: " << ans1 << endl;
  long long ans2 = 0;
  for (int j = (int)(1); j <= (int)(min(c - 1, k)); ++j) {
    long long sum = 0;
    for (int i = (int)(x + 1); i <= (int)(n - 1); ++i) {
      sum = (sum + dp[i][j]) % MOD;
    }
    ans2 = (ans2 + mulmod(sum, c - (long long)j, MOD)) % MOD;
  }
  cerr << "ans2: " << ans2 << endl;
  cout << (ans1 + ans2) % MOD;
  return 0;
}
