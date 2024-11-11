#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int r, c;
  cin >> r >> c;
  if (r == 1) {
    if (c == 1) {
      cout << 0 << endl;
      return 0;
    }
    for (int i = 1; i <= c; i++) cout << i + 1 << " ";
  } else {
    for (int i = 1; i <= r; i++) {
      for (int j = 1; j <= c; j++) {
        cout << i * (j + r) << " ";
      }
      cout << endl;
    }
  }
}
