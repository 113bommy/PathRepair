#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int t, n, a, b, c = 0, d = 0, i, j, p, e = 0;
  cin >> n;
  long long int ara[n];
  for (i = 0; i < n; i++) {
    cin >> ara[i];
    c += ara[i];
  }
  d = (c + 1) / 2;
  for (i = 0; i < n; i++) {
    e += ara[i];
    if (e >= d) break;
  }
  cout << i + 1;
  return 0;
}
