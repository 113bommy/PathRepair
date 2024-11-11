#include <bits/stdc++.h>
using namespace std;
long long a[10000] = {0};
int main() {
  int n, m;
  while (cin >> n >> m) {
    for (int i = 1; i <= m; i++) cin >> a[i];
    sort(a + 1, a + m + 1);
    for (int i = 3; i <= m; i++)
      if (a[i] - a[i - 2] == 2) {
        cout << "NO" << endl;
        return 0;
      }
    if (a[1] == 1 && a[m] == n)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
