#include <bits/stdc++.h>
using namespace std;
const long long oo = 1e8;
const double pi = 3.1415926535897;
const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }
struct edge {
  int from, to, w;
  edge() {}
  edge(int x, int y, int we) : from(x), to(y), w(we) {}
  bool operator<(const edge &rhs) const { return w > rhs.w; }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int A[n + 5];
    int frq[n + 5][26 + 5];
    memset(frq, 0, sizeof(frq));
    for (int i = 1; i <= n; i++) {
      cin >> A[i];
      frq[i][A[i]]++;
      for (int j = 1; j <= 26; j++) {
        frq[i][j] += frq[i - 1][j];
      }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int x = frq[i][A[i]];
      for (int j = i + 1; j <= n; j++) {
        if (frq[n][A[i]] - frq[j - 1][A[i]] == x) ans = max(ans, 2 * x);
        int y = frq[j][A[j]] - frq[i][A[j]];
        if (frq[n][A[i]] - frq[j][A[i]] == x) ans = max(ans, 2 * x + y);
      }
    }
    for (int i = 1; i <= 26; i++) ans = max(ans, frq[n][i]);
    cout << ans << "\n";
  }
}
