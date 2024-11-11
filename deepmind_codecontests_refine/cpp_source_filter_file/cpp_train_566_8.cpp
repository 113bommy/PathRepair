#include <bits/stdc++.h>
using namespace std;
pair<long double, bool> d[(int)2e6 + 1];
void prep(int x, int y) {
  long double dx = 1.0 / x;
  long double dy = 1.0 / y;
  long double nx = dx;
  long double ny = dy;
  int k = 0;
  for (int i = 0; i < 2e6 + 1; i++) {
    if (nx < ny) {
      d[k++] = make_pair(nx, true);
      nx += dx;
    } else {
      d[k++] = make_pair(ny, false);
      ny += dy;
    }
  }
}
void solve(int a) {
  auto p = d[a - 1];
  auto np = d[a];
  if (a > 1 && abs(p.first - d[a - 2].first) < 0.000000001F) {
    cout << "Both\n";
  } else if (abs(p.first - np.first) < 0.000000001F) {
    cout << "Both\n";
  } else if (p.second) {
    cout << "Vanya\n";
  } else {
    cout << "Vova\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  int x, y;
  cin >> x >> y;
  prep(x, y);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    a %= x + y;
    if (!a) {
      cout << "Both\n";
      continue;
    }
    solve(a);
  }
  return 0;
}
