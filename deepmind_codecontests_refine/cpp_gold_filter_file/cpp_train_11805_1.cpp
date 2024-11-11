#include <bits/stdc++.h>
using namespace std;
int a[100005], b[100005], i, m, ans, k, l, j, q, x, n, ma, mi;
string s;
int main() {
  cin >> n >> m >> k;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < m; i++) cin >> b[i];
  if (n > m) {
    cout << "YES";
    return 0;
  }
  sort(a, a + n);
  reverse(a, a + n);
  sort(b, b + m);
  reverse(b, b + m);
  for (i = 0; i < n; i++)
    if (a[i] > b[i]) {
      cout << "YES";
      return 0;
    }
  cout << "NO";
}
