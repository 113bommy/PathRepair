#include <bits/stdc++.h>
using namespace std;
long long n, q;
long long a[(int)(3e5 + 10)];
long long x, y;
stack<pair<long long, long long> > S;
inline void read() {
  cin >> n >> q;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
}
inline void solve() {
  for (long long i = 1; i <= q; i++) {
    cin >> x >> y;
    long long t = 0, res = 0;
    while (!S.empty()) {
      S.pop();
    }
    for (long long j = x + 1; j <= y; j++) {
      long long p = labs(a[j] - a[j - 1]);
      long long beg = j;
      while (!S.empty() and S.top().first < p) {
        t -= S.top().first * (beg - S.top().second);
        beg = S.top().second;
        S.pop();
      }
      t += p * (j - beg + 1);
      S.push(make_pair(p, beg));
      res += t;
    }
    cout << res;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  read();
  solve();
  return 0;
}
