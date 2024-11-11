#include <bits/stdc++.h>
using namespace std;
long long x[100002], v[100002], w[100002];
int main() {
  int n, m, a, b, c;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    w[i] = v[i];
    w[i] += w[i - 1];
  }
  sort(v + 1, v + n + 1);
  for (int i = 1; i <= n; i++) {
    x[i] = v[i];
    x[i] += x[i - 1];
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    if (a == 1) {
      cout << w[c] - w[b - 1] << endl;
    } else {
      cout << x[c] - x[b - 1] << endl;
    }
  }
}
