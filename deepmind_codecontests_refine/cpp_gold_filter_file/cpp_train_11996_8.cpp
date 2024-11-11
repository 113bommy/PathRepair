#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[n];
  for (int i = 0; i < n; i++) a[i] = i + 1;
  int cnt = (n / 2) * (n / 2);
  if (n % 2 == 0) cnt -= n / 2;
  if (cnt < m) {
    cout << -1;
    return 0;
  }
  int idx = n - 1;
  while (m < cnt) {
    if (cnt - (idx / 2) <= m) {
      a[idx] += 2 * (cnt - m);
      break;
    } else {
      cnt -= idx / 2;
      if (idx + 1 == n)
        a[idx] = 1000 * 1000 * 1000;
      else
        a[idx] = a[idx + 1] - 2 * n;
    }
    idx--;
  }
  for (int i = 0; i < n; i++) cout << a[i] << ' ';
}
