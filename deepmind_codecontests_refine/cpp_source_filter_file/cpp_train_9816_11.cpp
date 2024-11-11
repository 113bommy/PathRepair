#include <bits/stdc++.h>
using namespace std;
long long t, n, m, k, a[300010], q, l, r, x, o;
long long suf[200010];
long long fac[30];
void build() {
  for (long long i = n; i >= 1; i--) {
    a[i] = i;
    suf[i] = suf[i + 1] + a[i];
  }
  fac[0] = 1;
  for (long long i = 1; i <= 15; i++) {
    fac[i] = fac[i - 1] * i;
  }
}
void update() {
  long long x = t;
  vector<long long> v;
  for (long long i = max(1ll, n - 15); i <= n; i++) {
    v.push_back(i);
  }
  for (long long i = max(1ll, n - 15); i <= n; i++) {
    a[i] = v[(x - 1) / (fac[(n - i)])];
    v.erase(v.begin() + (x - 1) / fac[n - i]);
    x -= ((x - 1) / fac[(n - i)]) * fac[n - i];
  }
  for (long long i = n; i >= (max(n - 15, 1ll)); i--) {
    suf[i] = suf[i + 1] + a[i];
  }
}
void check() {
  cin >> n >> q;
  build();
  while (q--) {
    long long x;
    cin >> x;
    t = x;
    update();
    for (long long i = 1; i <= n; i++) {
      cout << a[i] << " ";
    }
    cout << "\n";
  }
}
int32_t main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  cin >> n >> q;
  build();
  suf[n + 1] = 0;
  while (q--) {
    cin >> o;
    if (o == 1) {
      cin >> l >> r;
      cout << (suf[l] - suf[r + 1]) << "\n";
    } else {
      cin >> x;
      t += x;
      update();
    }
  }
  return 0;
}
