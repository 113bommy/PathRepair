#include <bits/stdc++.h>
using namespace std;
struct edge {
  long long first, t, w;
  edge(long long first, long long t, long long w) : first(first), t(t), w(w) {}
  bool operator<(const edge& e) const { return (w > e.w); }
};
long long gcd(long long x, long long y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
long long fx(long long n, long long md) { return ((n % md) + md) % md; }
void O_o() {
  ios::sync_with_stdio(0);
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
}
int main() {
  O_o();
  string alpha = "abcdefghijklnopqrstuvwxyz", ans = "";
  int n, k, cnt = 0;
  cin >> n >> k;
  while (((int)(ans.size())) < n) {
    ans += alpha[cnt++ % k];
  }
  cout << ans << endl;
}
