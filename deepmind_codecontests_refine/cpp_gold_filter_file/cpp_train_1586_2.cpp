#include <bits/stdc++.h>
using namespace std;
bool isAllowed(int p[], int m, int x) {
  int i;
  for (i = 0; i < m; i++) {
    if (p[i] == x) return true;
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long t, n, m, i, j, f, temp;
  cin >> t;
  while (t--) {
    f = 0;
    cin >> n >> m;
    int ar[n];
    int p[m];
    for (i = 0; i < n; i++) cin >> ar[i];
    for (i = 0; i < m; i++) cin >> p[i];
    for (i = 0; i < n - 1; i++) {
      for (j = 0; j < n - 1 - i; j++) {
        if (ar[j] > ar[j + 1]) {
          if (!isAllowed(p, m, j + 1)) {
            f = 1;
          }
          temp = ar[j];
          ar[j] = ar[j + 1];
          ar[j + 1] = temp;
        }
      }
    }
    if (f)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
