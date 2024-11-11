#include <bits/stdc++.h>
using namespace std;
int a[100010], b[100100], n, k = 1;
const int INF = 10e9;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  int h = n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  if (n == 1) {
    cout << a[1];
    return 0;
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i < n; i++) {
    if (a[i] > a[n]) {
      cout << "Impossible";
      return 0;
    }
    b[k++] = a[i];
    b[k++] = a[n];
    n--;
  }
  for (int i = 1; i <= h; i++) {
    if (b[i] != 0) cout << b[i] << " ";
  }
  if (n > (h / 2)) cout << a[(h + 1) / 2];
}
