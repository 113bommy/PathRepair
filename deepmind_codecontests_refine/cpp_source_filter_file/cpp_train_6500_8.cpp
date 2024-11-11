#include <bits/stdc++.h>
using namespace std;
int n;
long v[100010], x[100010];
long cs[100010], css[100010];
int m;
int t, l, r;
int main() {
  cin >> n;
  v[0] = 0;
  x[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    cs[i] = cs[i - 1] + v[i];
    x[i] = v[i];
  }
  sort(x + 1, x + n + 1);
  for (int i = 1; i <= n; i++) {
    css[i] = css[i - 1] + x[i];
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> t >> l >> r;
    if (t == 1) {
      if (l == 1)
        cout << cs[r] << "\n";
      else
        cout << cs[r] - cs[l - 1] << "\n";
    } else {
      if (l == 1)
        cout << css[r] << "\n";
      else
        cout << css[r] - css[l] + x[l] << "\n";
    }
  }
}
