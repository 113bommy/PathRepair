#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
inline long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
inline long long power(long long a, long long n, long long m) {
  if (n == 0) return 1;
  long long p = power(a, n / 2, m);
  p = (p * p) % m;
  if (n % 2)
    return (p * a) % m;
  else
    return p;
}
const int INF = 0x3f3f3f3f;
const long long LL_INF = 0x3f3f3f3f3f3f3f3f;
const long long MOD = 11;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n, m;
  cin >> n >> m;
  string s[n];
  for (int i = 0; i < n; i++) cin >> s[i];
  vector<int> c[m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '1')
        c[j].push_back(1 + ((j >= 1) ? c[j - 1][i] : 0));
      else
        c[j].push_back(0);
    }
  }
  int ans = 0;
  for (int i = 0; i < m; i++) {
    sort(c[i].begin(), c[i].end());
    for (int j = 0; j < n; j++) {
      ans = max(ans, c[i][j] * (n - j));
    }
  }
  cout << ans << endl;
  return 0;
}
