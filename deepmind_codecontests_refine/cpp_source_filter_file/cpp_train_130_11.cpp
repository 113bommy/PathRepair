#include <bits/stdc++.h>
using namespace std;
const int N = 5e5;
int n, ans, x, a[N], was[N];
array<int, 2> c[N];
int main() {
  cin >> n;
  for (int i = 1; i < n + 1; ++i) {
    cin >> a[i];
    c[a[i]][0]--;
    c[i][1] = i;
  }
  sort(c + 1, c + n + 1);
  random_shuffle(c + min(n, 150), c + n + 1);
  for (int i = 2; i < min(n, 200); ++i) {
    memset(was, -1, sizeof(was));
    was[n] = 0, x = n;
    for (int r = 1; r < n + 1; ++r) {
      x += (a[r] == c[1][1]) - (a[r] == c[i][1]);
      if (was[x] != -1) {
        ans = max(ans, r - was[x]);
      } else {
        was[x] = r;
      }
    }
  }
  cout << ans << '\n';
}
