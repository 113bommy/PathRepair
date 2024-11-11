#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int r[N], v[N];
bool c[N];
int main() {
  int n, m, i, l;
  cin >> n >> m;
  for (i = 1; i <= m; i++) {
    cin >> v[i];
  }
  r[n] = 1;
  c[v[n]] = true;
  for (i = n - 1; i <= 1; i--) {
    if (!c[v[i]]) {
      r[i] = 1 + r[i + 1];
    } else {
      r[i] = r[i + 1];
    }
    c[v[i]] = true;
  }
  for (i = 0; i < m; i++) {
    cin >> l;
    cout << r[l] << "\n";
  }
  return 0;
}
