#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int ans[1000010];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> a >> b;
  int ca = -1;
  int cb = -1;
  for (int i = a; i <= n; i += a) {
    if ((n - i) % b == 0) {
      ca = i / a;
      cb = (n - i) / b;
      break;
    }
  }
  if (ca == -1) {
    cout << -1 << endl;
  } else {
    int s = 0;
    while (ca > 0) {
      int t = 0;
      while (t < a - 1) {
        ans[s + t] = s + t + 2;
        t++;
      }
      ans[s + t] = s + 1;
      s += a;
      ca--;
    }
    while (cb > 0) {
      int t = 0;
      while (t < b - 1) {
        ans[s + t] = s + t + 2;
        t++;
      }
      ans[s + t] = s + 1;
      s += b;
      cb--;
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }
}
