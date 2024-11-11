#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, a, b, ans;
int main() {
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cin >> a >> b;
      if (a + b > 0) ans++;
    }
  }
  cout << ans;
}
