#include <bits/stdc++.h>
using namespace std;
int a[100100][3];
int main(void) {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i][1];
    }
    for (int i = 1; i <= n; i++) {
      cin >> a[i][2];
    }
    a[0][1] = 0;
    a[n + 1][1] = 0;
    a[n + 1][2] = 0;
    a[0][2] = 0;
    for (int i = n; i >= 0; i--) {
      a[i][1] += a[i + 1][1];
    }
    for (int i = 1; i <= n + 1; i++) {
      a[i][2] += a[i - 1][2];
    }
    int maxn = 1e9;
    for (int i = 1; i <= n; i++) {
      maxn = min(maxn, max(a[i + 1][1], a[i - 1][2]));
    }
    cout << maxn << endl;
  }
}
