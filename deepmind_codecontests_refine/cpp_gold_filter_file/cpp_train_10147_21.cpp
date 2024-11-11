#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long long n;
  cin >> n;
  if (n % 2) {
    cout << "black" << '\n';
  } else {
    cout << "white" << '\n';
    if (n == 2) {
      cout << 1 << " " << 2 << '\n';
    } else {
      cout << 1 << " " << 2 << '\n';
    }
  }
  return 0;
}
