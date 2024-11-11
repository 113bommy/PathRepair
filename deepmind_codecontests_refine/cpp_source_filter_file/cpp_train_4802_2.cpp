#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
const long long maxn = 5e6 + 2;
long long powers[maxn];
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (long long i = 1; i < maxn; i++) {
    powers[i] = i * i;
  }
  long long n;
  cin >> n;
  map<long long, long long> mappa;
  vector<long long> a(n);
  for (long long i = 0; i < n / 2; i++) {
    cin >> a[i];
  }
  vector<long long> ans(n + 1);
  long long pos = 2;
  long long curr = 0;
  long long p = 1;
  for (long long i = 0; i < n / 2; i++) {
    ans[pos] = a[i];
    pos += 2;
  }
  for (long long i = 2; i <= n; i += 2) {
    long long tizio = -1;
    for (; p < maxn;) {
      if (powers[p] - powers[p - 1] > ans[i]) {
        break;
      }
      if (mappa.count(powers[p] - ans[i]) && powers[p] - ans[i] > 0) {
        tizio = powers[p] - ans[i];
        mappa[powers[p]]++;
        p++;
        break;
      } else {
        mappa[powers[p]]++;
      }
      p++;
    }
    if (tizio == -1) {
      cout << "No" << '\n';
      return 0;
    }
    ans[i - 1] = tizio - curr;
    curr = tizio + ans[i];
  }
  cout << "Yes" << '\n';
  for (long long i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << '\n';
}
