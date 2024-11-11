#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("abm,fma,mmx,avx,popcnt,avx2,sse,sse2,sse3")
using namespace std;
void Seeyouagain() {
  int_fast64_t n;
  cin >> n;
  if (n % 2)
    cout << n / 2 << " " << (n + 1) / 2;
  else {
    cout << -(n - 1) << " " << n;
  }
}
signed main() {
  ios_base::sync_with_stdio(!cin.tie(nullptr));
  int_fast64_t testc = 1;
  cin >> testc;
  while (testc--) {
    Seeyouagain();
    cout << "\n";
  }
  return 0;
}
