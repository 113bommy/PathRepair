#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, s1 = 0, s2 = 0;
  cin >> n >> m;
  int a[m];
  for (int i = 0; i < m; i++) cin >> a[i];
  int min = 0, max = 0;
  sort(a, a + m);
  s1 = a[0];
  for (int i = 0; i < n; ++i) {
    min += s1;
    s1 = s1 - 1;
    if (s1 == 0) s1 = a[++s2];
  }
  sort(a, a + m, greater<int>());
  while (n--) {
    max += a[0];
    a[0] = a[0] - 1;
    for (int i = 1; i < m; i++) {
      if (a[i] <= a[i - 1]) break;
      swap(a[i], a[i - 1]);
    }
  }
  cout << max << " " << min;
}
