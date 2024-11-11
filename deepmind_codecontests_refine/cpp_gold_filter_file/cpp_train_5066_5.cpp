#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, c;
  cin >> n >> m;
  long long a[n], b[m];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  int i = 0, j = 0;
  long long sum = 0, d;
  while (j < n && i < m) {
    sum += a[j];
    while (sum >= b[i]) {
      c = j;
      d = b[i] - (sum - a[j]);
      cout << c + 1 << " " << d << endl;
      i++;
      if (i == m) {
        break;
      }
    }
    j++;
  }
  return 0;
}
