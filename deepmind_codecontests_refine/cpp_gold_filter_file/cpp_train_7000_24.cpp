#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
template <typename... T>
void rd(T&... args) {
  ((cin >> args), ...);
}
template <typename... T>
void wr(T... args) {
  ((cout << args << " "), ...);
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < int((n + 1) / 2); ++i) {
    cin >> a[i];
  }
  int x;
  cin >> x;
  for (int i = (n + 1) / 2; i < n; i++) a[i] = x;
  vector<ll> ps(n + 1);
  partial_sum((a).begin(), (a).end(), ps.begin() + 1);
  if (ps.back() > 0) return cout << n, 0;
  if (x >= 0) return cout << -1, 0;
  ll N2 = n / 2, N1 = n - N2, sum = ps.back();
  ll mx = -1e18;
  for (int i = 0; i <= N2; i++) {
    mx = max(mx, ps[i] + x * ll(n - i));
    if (mx < sum + x * ll(n - i)) {
      cout << n - i;
      return 0;
    }
  }
  cout << -1;
  return 0;
}
