#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 998244353;
double eps = 1e-12;
long long myceil(long long a, long long b) {
  if (a % b == 0)
    return a / b;
  else
    return a / b + 1;
}
bool isPerSquare(long double a) {
  if (a < 0) return false;
  long long sr = sqrt(a);
  return (sr * sr == a);
}
long long arr1[200002];
long long arr2[200002];
long long arr2D[1001][1001];
vector<long long> vec;
void changestr(string &s, long long k) {
  for (long long i = 0; i < k + 1; i++) {
    if (s[i] == '0')
      s[i] = '1';
    else
      s[i] = '0';
  }
  reverse(&s[0], &s[k]);
}
void solve() {
  long long n, m, a, b, c, d;
  string s1, s2;
  cin >> n;
  cin >> s1 >> s2;
  vector<long long> vec;
  for (long long i = n - 1; i >= 0; i--) {
    if (s1[i] == s2[i]) continue;
    if (s1[0] != s2[i]) {
      vec.push_back(i);
      changestr(s1, i);
      continue;
    }
    vec.push_back(0);
    vec.push_back(i);
    changestr(s1, 0);
    changestr(s1, i);
  }
  cout << vec.size() << " ";
  for (auto itr = vec.begin(); itr != vec.end(); ++itr) cout << *itr + 1 << " ";
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  for (int it = 1; it <= t; it++) {
    solve();
  }
  return 0;
}
