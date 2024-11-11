#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, s = 0;
  cin >> n >> m;
  int a[n];
  for (int k = 0; k < n; k++) cin >> a[k];
  sort(a, a + n);
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++) {
      if (a[j] - a[i] <= m)
        s++;
      else
        break;
    }
  cout << 2 * s;
  return 0;
}
