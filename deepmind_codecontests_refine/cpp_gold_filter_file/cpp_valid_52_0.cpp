#include <bits/stdc++.h>
using namespace std;
int INF = 0x3f3f3f3f;
long long LINF = 0x3f3f3f3f3f3f3f3f;
int dy[]{0, -1, 0, 1};
int dx[]{-1, 0, 1, 0};
int dy8[]{0, -1, -1, -1, 0, 1, 1, 1};
int dx8[]{-1, -1, 0, 1, 1, 1, 0, -1};
const int NM = 100000;
int n;
int a[NM];
void input(istream& cin) {
  cin >> n;
  for (int i = (0); i < (n); ++i) cin >> a[i];
}
void solve() {
  int idx = max_element(begin(a), begin(a) + n) - begin(a);
  double ans = 0;
  for (int i = (0); i < (n); ++i) {
    if (i != idx) ans += a[i];
  }
  ans /= n - 1;
  ans += a[idx];
  cout << ans << '\n';
}
int main() {
  int T = 1;
  cin >> T;
  cout << fixed << setprecision(6);
  for (int C = (0); C < (T); ++C) {
    input(cin);
    solve();
  }
  return 0;
}
