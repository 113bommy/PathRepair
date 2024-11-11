#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 * 1000 + 10;
int a[MAXN];
int b[MAXN];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  sort(a, a + n);
  sort(b, b + m);
  if (n > m)
    cout << "YES" << endl;
  else {
    for (int i = 0; i < n; i++) {
      if (a[n - i - 1] > b[m - i - 1]) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
