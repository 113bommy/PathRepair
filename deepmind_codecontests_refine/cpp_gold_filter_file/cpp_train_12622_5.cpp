#include <bits/stdc++.h>
using namespace std;
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
const int M = 1e9 + 7;
const int N = 1e6;
const char dc[4] = {'D', 'R', 'U', 'L'};
void solve() {
  long long x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  cout << (x2 - x1) * (y2 - y1) + 1 << endl;
}
int main() {
  fast();
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
