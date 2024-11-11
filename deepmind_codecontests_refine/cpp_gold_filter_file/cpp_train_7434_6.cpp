#include <bits/stdc++.h>
using namespace std;
int n, d, m, s = 0;
int a[101];
int main() {
  cin >> n >> d;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> m;
  sort(a, a + n);
  if (m <= n) {
    for (int i = 0; i < m; i++) {
      s += a[i];
    }
  } else if (n < m) {
    for (int i = 0; i < n; i++) {
      s += a[i];
    }
    {
      for (int i = n + 1; i <= m; i++) {
        s -= d;
      }
    }
  }
  cout << s;
  return 0;
}
