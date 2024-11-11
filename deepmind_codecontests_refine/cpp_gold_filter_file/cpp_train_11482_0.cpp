#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
const long long MOD1 = 1e9 + 7;
const long long MOD2 = 998244353;
const long long INF = 0x3f3f3f3f3f3f3f3fll;
const double PI = 3.1415926535897932384626;
const long long MAX_SIZE = 2e6 + 6;
const long long MAX = INT_MAX;
const long long MIN = INT_MIN;
bool prime[MAX_SIZE];
void Sieve_Of_Eratosthenes() {
  memset(prime, true, sizeof(prime));
  for (long long i = 2; i * i <= MAX_SIZE; i++) {
    if (prime[i] == true) {
      for (long long j = i * i; j <= MAX_SIZE; j += i) prime[j] = false;
    }
  }
}
long long powerM(long long x, long long y, long long M = MOD1) {
  long long v = 1;
  x = x % M;
  while (y > 0) {
    if (y & 1) v = (v * x) % M;
    y = y >> 1;
    x = (x * x) % M;
  }
  return v;
}
long long power(long long x, long long y) {
  long long v = 1;
  while (y > 0) {
    if (y & 1) v = v * x;
    y = y >> 1;
    x = x * x;
  }
  return v;
}
bool Is_Power_Of_Two(long long x) { return x && (!(x & (x - 1))); }
string Print_LCS(string x, string y) {
  long long n = x.length(), m = y.length(), dp[n + 1][m + 1], i, j;
  memset(dp, 0, sizeof(dp));
  for (i = 1; i < n + 1; i++) {
    for (j = 1; j < m + 1; j++) {
      if (x[i - 1] == y[j - 1])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  string str = "";
  i = n, j = m;
  while (i > 0 && j > 0) {
    if (x[i - 1] == y[j - 1])
      str += x[i - 1], i--, j--;
    else
      dp[i - 1][j] > dp[i][j - 1] ? i-- : j--;
  }
  reverse(str.begin(), str.end());
  return str;
}
bool Compare(pair<long long, long long> A, pair<long long, long long> B) {
  if (A.first == B.first) return A.second < B.second;
  return A.first < B.first;
}
void Solve() {
  long long t, n, i;
  cin >> t;
  while (t--) {
    cin >> n;
    long long a[n];
    map<long long, long long> make_pair;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      make_pair[a[i]]++;
    }
    if (make_pair.size() == 1)
      cout << "NO\n";
    else {
      cout << "YES\n";
      vector<long long> v;
      long long ind = -1;
      for (i = 1; i < n; i++) {
        if (a[0] != a[i]) {
          cout << 1 << " " << i + 1 << "\n";
          if (ind == -1) ind = i + 1;
        } else
          v.push_back(i);
      }
      for (auto &x : v) {
        cout << x + 1 << " " << ind << "\n";
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  Solve();
}
