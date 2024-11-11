#include <bits/stdc++.h>
using namespace std;
int n, i, j, k, a[101], m;
int main() {
  cin >> n;
  cin >> m;
  for (i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  if (m < a[n])
    cout << 1;
  else {
    for (i = n; i >= 1; i--) {
      if (k < m) {
        k += a[i];
        j++;
      }
    }
    cout << j;
  }
}
