#include <bits/stdc++.h>
using namespace std;
const long long MOD = pow(10, 9) + 7;
float line(int x1, int y1, int x2, int y2, float a, float b) {
  return (b - y1) - float(y2 - y1) * (a - x1) / (x2 - x1);
}
void solve() {
  int n, d;
  cin >> n >> d;
  int a1 = d, a2 = 0, b1 = 0, b2 = d, c1 = n - d, c2 = n, d1 = n, d2 = n - d;
  int m;
  cin >> m;
  for (int i = 0; i < m; i += 1) {
    float x, y;
    cin >> x >> y;
    float p = line(a1, a2, b1, b2, x, y) * line(a1, a2, d1, d2, x, y) *
              line(c1, c2, b1, b2, x, y) * line(c1, c2, d1, d2, x, y);
    if (p >= 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t > 0) {
    solve();
    t--;
  }
}
