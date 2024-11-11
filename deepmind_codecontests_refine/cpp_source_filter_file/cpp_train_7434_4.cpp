#include <bits/stdc++.h>
using namespace std;
int n, i, j, a[105], d, m, s;
int main() {
  cin >> n >> d;
  for (i = 1; i <= n; i++) cin >> a[i];
  cin >> m;
  sort(a + 1, a + n + 1);
  if (m <= n) {
    for (i = 1; i <= m; i++) s += a[i];
  }
  if (m > n) {
    for (i = 1; i <= n; i++) s += a[i];
    s -= (n - m) * d;
  }
  cout << s << endl;
}
