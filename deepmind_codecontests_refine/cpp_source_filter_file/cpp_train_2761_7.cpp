#include <bits/stdc++.h>
using namespace std;
const int MX = 2 * 100000 + 10;
long long n, k, a, b, q, srt;
long long as[MX], bs[MX], abl[MX], bbl[MX];
int sqr(int x) { return x / srt; }
void pr1(long long x, long long y) {
  long long p = min(y, b - bs[x]);
  bbl[sqr(x)] += p;
  bs[x] += p;
  p = min(y, a - as[x]);
  abl[sqr(x)] += p;
  as[x] += p;
}
void pr2(long long x) {
  int l = sqr(x) - 1;
  int r = sqr(x + k) + 1;
  long long ans = 0;
  for (int i = 0; i <= l; i++) {
    ans += bbl[i];
  }
  for (int j = r; j <= sqr(n); j++) {
    ans += abl[j];
  }
  long long ind = x - 1;
  while (ind <= x && sqr(ind) == sqr(x)) {
    ans += bs[ind];
    ind--;
  }
  ind = x + k;
  while (ind >= x + k && sqr(ind) == sqr(x + k)) {
    ans += as[ind++];
  }
  cout << ans << endl;
}
int main() {
  std::ios::sync_with_stdio(false);
  cin >> n >> k >> a >> b >> q;
  ;
  srt = sqrt(n);
  for (int i = 0, t, x, y; i < q; i++) {
    cin >> t;
    if (t == 1) {
      cin >> x >> y;
      pr1(x, y);
    } else {
      cin >> x;
      pr2(x);
    }
  }
  return 0;
}
