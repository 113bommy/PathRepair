#include <bits/stdc++.h>
using namespace std;
long long int m, n, i, j, y, x = 0, k = 0, q = 0;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int a[100005] = {0}, i, max = 0, n, c = 0, t = 0;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (i = 1; i <= n; i++) {
    if (a[i] >= t) {
      c++;
      t += a[i];
    }
  }
  cout << c;
  return 0;
}
