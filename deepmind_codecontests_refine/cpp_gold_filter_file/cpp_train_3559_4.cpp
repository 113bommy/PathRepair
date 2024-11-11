#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n, p;
  cin >> n >> p;
  for (int i = (int)0; i < (int)32; i++) {
    int cur = n - p * i;
    if (cur < i) continue;
    if (__builtin_popcount(cur) <= i) {
      cout << i;
      return 0;
    }
  }
  cout << -1;
  return 0;
}
