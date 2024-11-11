#include <bits/stdc++.h>
using namespace std;
int t;
int n;
const int N = 3e4 + 10;
int a[N];
int l, r;
int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  while (cin >> t) {
    while (t--) {
      cin >> n;
      for (int i = (1); i < (n + 1); i++) cin >> a[i];
      l = a[1];
      r = 0;
      bool flag = 1;
      for (int i = (2); i < (n + 1); i++) {
        while (l + r > a[i]) {
          if (a[i] >= r)
            l -= (l + r) - a[i];
          else {
            flag = 0;
            break;
          }
        }
        while (l + r < a[i]) {
          r += a[i] - (l + r);
        }
      }
      if (flag)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}
