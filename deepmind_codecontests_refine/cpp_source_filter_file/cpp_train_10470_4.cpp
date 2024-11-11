#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
const long long inf = 1e9 + 10;
const long long inf2 = 1e18 + 99LL;
const long double inf3 = 1e14;
const long long mod = 1e9 + 7, mod2 = 998244353;
const long double eps = 1e-9;
const bool local = false;
const int logn = 18, maxn = 200005, maxm = 10001, maxn2 = 3;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  ;
  int n;
  cin >> n;
  vector<int> s(n);
  for (int i = 0; i < n; i++) {
    s[i] = i;
  }
  for (int i = 0; i < n; i++) {
    int j;
    cin >> j;
    j--;
    for (int ti = 0; ti < n; ti++) {
      if (s[ti] == s[i]) {
        s[ti] = j;
      }
    }
  }
  set<int> ts;
  for (int x : s) ts.insert(x);
  cout << (int)((ts).size()) << nl;
}
