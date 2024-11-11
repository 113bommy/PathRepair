#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, c = 0;
  cin >> n >> m >> k;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (int i = 0, j = k - 1; j < n; j++) {
    if (a[j] + 1 - a[i] <= m) {
      c++;
      a[j] = 1;
      if (i == j) i++;
    } else {
      i++;
      while (a[i] == -1) i++;
    }
  }
  cout << c << endl;
  return 0;
}
