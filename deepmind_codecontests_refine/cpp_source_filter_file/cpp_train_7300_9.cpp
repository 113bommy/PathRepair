#include <bits/stdc++.h>
using namespace std;
int a[401];
int n, w1, w2, ans, t1, t2;
int greedy(int l, int r, int &m) {
  int t = 0;
  for (int i = l; i <= r; i++) {
    t = t + m / a[i];
    m = m % a[i];
  }
  if (r != n) t++;
  m = a[l - 1] - 1 - m + a[r];
  return t;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  ans = 2 * a[1];
  for (int i = n - 2; i >= 1; i--) {
    for (int j = i + 1; j < n; j++) {
      w1 = a[i] - 1;
      t1 = greedy(i + 1, j, w1);
      w2 = w1;
      t2 = greedy(i, n, w1);
      if ((t1 < t2) and (w2 < ans)) {
        ans = w2;
      }
    }
  }
  if (ans == 2 * a[1]) ans = -1;
  cout << ans << endl;
}
