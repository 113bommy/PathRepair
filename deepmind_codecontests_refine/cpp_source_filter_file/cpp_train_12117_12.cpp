#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int x1, x2, y1, y2, x, y, n, i, j, k, w, l = 0, c1 = 0, c2 = 0,
                                                     c3 = 0;
  map<long long int, long long int> m;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) {
    cin >> x >> y;
    m[x] = y;
    a[i] = x;
  }
  for (i = 0; i < n; i++) {
    int y = m[a[i]];
    y = y + a[i];
    if (m[y] == a[i]) {
      cout << "YES"
           << "\n";
      l = 1;
      break;
    }
  }
  if (l == 0) {
    cout << "NO"
         << "\n";
  }
  return 0;
}
