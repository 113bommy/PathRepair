#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ddx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int ddy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
bool debug = false;
int main() {
  int n, L, a;
  cin >> n >> L >> a;
  int ans = 0, now = 0;
  for (int i = 0; i < n; i++) {
    int t, l;
    cin >> t >> l;
    ans = (t - now) / a;
    now = t + l;
  }
  ans = (L - now) / a;
  cout << ans << endl;
  return 0;
}
