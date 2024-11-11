#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
long long int n, l, r;
int32_t main() {
  long long int s1 = 0, s2 = 0;
  cin >> n;
  cin >> l;
  cin >> r;
  s1 = n - l + 1;
  long long int x = 2, y = 0;
  while (y < l - 1) {
    s1 = s1 + x;
    y++;
    x = x * x;
  }
  x = 1;
  y = 0;
  while (y < r - 1) {
    s2 = s2 + x;
    y++;
    x = x * 2;
  }
  for (long long int i = 0; i < n - r + 1; i++) s2 = s2 + x;
  cout << s1 << ' ' << s2 << endl;
}
