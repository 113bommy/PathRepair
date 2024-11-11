#include <bits/stdc++.h>
using namespace std;
int n, m, e, o, e1, o1, x;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> x, o += (x % 2);
  e = n - o;
  for (int i = 0; i < m; ++i) cin >> x, o1 += (x % 2);
  e1 = m - o1;
  cout << min(e, o1) + min(e1, o);
}
