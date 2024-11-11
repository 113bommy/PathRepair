#include <bits/stdc++.h>
using namespace std;
int m[200];
int n;
int S, E;
bool is_ok(int lim) {
  int s = 0, e = 0;
  for (int i = 0; i < lim; ++i) s += m[i];
  for (int j = lim; j <= n; ++j) e += m[j];
  return s <= E && e <= E && s >= S && e >= S;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> m[i];
  cin >> S >> E;
  for (int i = 1; i <= n; ++i)
    if (is_ok(i)) {
      cout << m[i] << endl;
      break;
    } else if (i == n)
      cout << 0 << endl;
  return 0;
}
