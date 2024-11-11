#include <bits/stdc++.h>
using namespace std;
int dr[8] = {-1, 0, +1, 0, -1, -1, +1, +1};
int dc[8] = {0, +1, 0, -1, -1, +1, -1, +1};
int kx[8] = {-1, +1, +1, -1, +2, +2, -2, -2};
int ky[8] = {+2, +2, -2, -2, -1, +1, +1, -1};
const int N = 100005;
int main() {
  int n, m;
  cin >> n >> m;
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    int x = 5 - (i % 5);
    int y = (m - x);
    if (y < 0) continue;
    y = y / 5 + 1;
    ans += y;
  }
  cout << ans << endl;
}
