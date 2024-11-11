#include <bits/stdc++.h>
const double EPS = 0.0000000001;
const long long mod1 = 998244353;
const long long mod2 = 1000000007;
const long long mod3 = 1000000009;
const long long mod4 = 998244353;
const long long inf = 10000000000000000;
using namespace std;
signed main() {
  cin.tie(0);
  cout.tie(0);
  std::ios_base::sync_with_stdio(0);
  long long n, a;
  cin >> n >> a;
  long long matrix[a][n];
  for (long long i = 0; i < a; i++) {
    for (long long z = 0; z < n; z++) {
      char c;
      cin >> c;
      matrix[i][z] = (c - '0');
    }
  }
  bool used[a];
  for (long long i = 0; i < a; i++) {
    bool p = 0;
    for (long long z = 0; z < n; z++) {
      if (!matrix[i][z]) p = 1;
    }
    used[i] = p;
  }
  long long c = 0;
  long long x = 1;
  long long maxi = -1;
  for (long long i = 0; i < a; i++) {
    if (used[i]) {
      c++;
      continue;
    }
    maxi = max(maxi, c);
    c = 0;
  }
  maxi = max(maxi, c);
  cout << maxi;
}
