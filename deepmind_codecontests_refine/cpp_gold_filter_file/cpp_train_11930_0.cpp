#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t, k, d;
  cin >> n >> t >> k >> d;
  int time = 0, ans = 0;
  while (1) {
    ans += k;
    time += t;
    if (ans >= n) break;
    if (time >= d) {
      if (d % t == 0) {
        if (n - ans > k) {
          cout << "YES";
          return 0;
        } else {
          cout << "NO";
          return 0;
        }
      } else
        cout << "YES";
      return 0;
    }
  }
  cout << "NO";
}
