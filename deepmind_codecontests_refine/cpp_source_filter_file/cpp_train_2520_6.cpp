#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 10;
pair<int, int> pts[N];
double dist(int i, int j) {
  double x = pts[i].first - pts[j].first;
  double y = pts[i].second - pts[j].second;
  return sqrt(x * x + y * y);
}
void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> pts[i].first >> pts[i].second;
  double ans = 0;
  for (int i = 1; i < n; ++i) {
    int p = (i - 1) % n;
    int c = i % n;
    ans += dist(p, c);
  }
  cout << 10 * ans / 50 << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(20);
  cout << fixed;
  solve();
  cout.flush();
  return 0;
}
