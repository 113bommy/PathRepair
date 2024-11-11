#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a[101], x, t = 0, i = 0, s = 0;
  cin >> n >> m;
  for (i = 1; i < 101; i++) a[i] = 0;
  for (i = 0; i < m; i++) {
    cin >> x;
    a[x]++;
  }
  for (i = 1; i < m + 1; i++) {
    s = 0;
    for (int j = 1; j < 100; j++) {
      if (a[j] / i) {
        s += a[j] / i;
      }
      if (s >= n) t = i;
    }
  }
  cout << t;
  return 0;
}
