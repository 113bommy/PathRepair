#include <bits/stdc++.h>
const int INF = 0x3f3f3f3f;
using namespace std;
long long r;
int solve(double h) {
  if (h - 2 * r < 1e-9) return 0;
  int ret = (int)floor(h / (2.0 * r));
  h -= ret * r * 2;
  ret *= 2;
  if (h >= sqrt(3) * r) ret++;
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  long long h;
  cin >> r >> h;
  h *= 2;
  if (h < r) {
    cout << "1\n";
    return 0;
  }
  int c1 = 1 + solve(1.0 * h + (2 * r - sqrt(3) * r));
  int c2 = 2 + solve(h - r);
  cout << max(c1, c2) << '\n';
  return 0;
}
