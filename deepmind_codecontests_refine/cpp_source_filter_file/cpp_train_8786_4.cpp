#include <bits/stdc++.h>
using namespace std;
int c[102];
int p[102];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int m, x, y;
  cin >> m;
  for (int i = 1; i <= m; i++) cin >> c[i];
  cin >> x >> y;
  for (int i = 1; i <= m; i++) p[i] = p[i - 1] + c[i];
  for (int i = 2; i <= m; i++) {
    int a = p[i - 1];
    int b = p[m] - p[i - 1];
    if (a > b) swap(a, b);
    if (x <= a and b <= b) {
      cout << i << '\n';
      return 0;
    }
  }
  cout << 0 << '\n';
  return 0;
}
