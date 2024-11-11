#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  if (n == 4 || k < n + 1) {
    cout << -1 << '\n';
    return 0;
  }
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int taken[n + 1];
  for (int i = 0; i <= n; i++) taken[i] = 0;
  taken[a] = taken[b] = taken[c] = taken[d] = 1;
  cout << a << " " << c << " ";
  for (int i = 1; i <= n; i++)
    if (!taken[i]) cout << i << " ";
  cout << d << " " << b << '\n';
  cout << c << " " << a << " ";
  for (int i = 1; i <= n; i++)
    if (!taken[i]) cout << i << " ";
  cout << b << " " << d << '\n';
}
