#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, p;
  cin >> n >> p;
  const int inf = 1e9;
  int ans = inf;
  for (int i = 1; i <= 1e5; i++) {
    int num = n - p * i;
    if (num >= i) {
      int pi = __builtin_popcount(num);
      if (pi <= i) {
        ans = i;
        break;
      }
    }
  }
  cout << ((ans == inf) ? -1 : ans) << endl;
  return 0;
}
