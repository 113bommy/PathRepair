#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m, t;
  cin >> n >> m >> t;
  vector<long long> p(n);
  for (int i = 0; i < n; i++) cin >> p[i];
  vector<long long> q = p;
  sort(q.begin(), q.end());
  int L = -1, R = n;
  long long ans = 0, dans = 1;
  while (L + 1 < R) {
    int M = (L + R) / 2;
    int d = q[M];
    long long tm = 0, cnt = 0, lst = 0, br = 0;
    for (int i = 0; i < n; i++) {
      if (p[i] <= d) {
        if (tm + p[i] > t) {
          br = 1;
          break;
        }
        tm += p[i], lst += p[i], cnt++;
        if (cnt % m == 0) tm += lst, lst = 0;
      }
    }
    if (!br) {
      L = M;
    } else {
      R = M;
    }
    if (cnt > ans) {
      ans = cnt;
      dans = d;
    }
  }
  cout << ans << " " << dans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
