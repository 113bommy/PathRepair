#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
int n, s, t[100000];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cout.precision(30);
  cerr.precision(7);
  ;
  cin >> n;
  for (int i = 1; (i * (i + 1)) / 2 <= n; i++) s++, t[i] = (i * (i + 1)) / 2;
  int r = s;
  for (int i = 1; i <= s; i++) {
    if (i < r) break;
    if (t[i] + t[r] > n)
      i--, r--;
    else if (t[i] + t[r] == n) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}
