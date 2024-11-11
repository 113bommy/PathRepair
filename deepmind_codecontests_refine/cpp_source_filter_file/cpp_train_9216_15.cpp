#include <bits/stdc++.h>
using namespace std;
int n;
int G(int x) {
  if (x <= n && x >= 1) return 1;
  return 0;
}
int main() {
  int a, b, c, d;
  int cnt = 0;
  cin >> n >> a >> b >> c >> d;
  for (int i = 1; i <= n; i++)
    if (G(b + i - c) && G(a + i - d) && G(-d - c + a + b + i)) cnt++;
  cout << cnt * n;
  return 0;
}
