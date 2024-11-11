#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
using namespace std;
const double PI = 3.1415926536;
int main() {
  int n;
  cin >> n;
  int r[n];
  for (int i = 0; i < (int)(n); ++i) cin >> r[i];
  sort(r, r + n);
  double ans;
  int c = 0;
  for (int i = 0; i < (int)(n); ++i) {
    c += pow(-1, i) * r[i] * r[i];
  }
  ans = PI * c;
  cout << ans << "\n";
  return 0;
}
