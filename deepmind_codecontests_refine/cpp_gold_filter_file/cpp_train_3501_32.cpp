#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
char c, d;
char a[100100];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> x >> y >> c >> d;
    for (int j = x; j <= y; j++) {
      if (a[j] == c) {
        a[j] = d;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i];
  }
}
