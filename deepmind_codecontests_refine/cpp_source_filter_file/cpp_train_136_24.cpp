#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
const int INF = int(1e9), mod = 10056, N = int(1e6) + 5;
int a, b, c;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> a >> b >> c;
  a *= c;
  int l = 1;
  int r = a;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (mid * b + c * b >= a) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << r;
}
