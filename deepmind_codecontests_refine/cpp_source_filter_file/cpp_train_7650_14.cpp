#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<bool> q(n + 1, 0);
  for (int i = 2; i * i <= n; i++) {
    if (q[i] == 0) {
      for (int j = i + i; j <= n; j += i) {
        q[j] = 1;
      }
    }
  }
  int ans1 = 0;
  for (int i = 2; i <= n; i++) {
    int w = i;
    if (q[i] == 0) {
      while (i < n) {
        ans1++;
        w *= i;
        if (w > n) {
          break;
        }
      }
    }
  }
  cout << ans1 << endl;
  for (int i = 2; i <= n; i++) {
    int w = i;
    if (q[i] == 0) {
      while (i < n) {
        cout << w << " ";
        w *= i;
        if (w > n) {
          break;
        }
      }
    }
  }
  return 0;
}
