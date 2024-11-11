#include <bits/stdc++.h>
using namespace std;
template <typename T>
void __read(T &a) {
  cin >> a;
}
template <typename T, typename... Args>
void __read(T &a, Args &...args) {
  cin >> a;
  __read(args...);
}
constexpr long long M7 = 1000000007ll;
constexpr long long M9 = 1000000009ll;
constexpr long long MFFT = 998244353ll;
template <class T>
void outv(T &a) {
  for (auto &x : a) cout << x << ' ';
}
static mt19937 rnd(static_cast<unsigned>(
    chrono::steady_clock::now().time_since_epoch().count()));
auto __fast_io__ = (ios_base::sync_with_stdio(false), cin.tie(nullptr));
int32_t main() {
  long long n;
  __read(n);
  long long k = -1, mx = -1;
  for (long long i = 2; i <= n; ++i) {
    long long val = n - (n + k - 1) / k - k + 1;
    if (val > mx) {
      mx = val;
      k = i;
    }
  }
  vector<long long> was(n);
  while (true) {
    vector<long long> a;
    for (long long j = 0; j < n; ++j) {
      if (j % k != 0 && !was[j]) {
        a.push_back(j);
      }
    }
    if (a.size() < k) {
      cout << 0 << endl;
      break;
    }
    cout << k;
    shuffle((a).begin(), (a).end(), rnd);
    for (long long i = 0; i < k; ++i) {
      cout << ' ' << a[i] + 1;
      was[a[i]] = 1;
    }
    cout << endl;
    long long x;
    __read(x);
    assert(x != -1);
    x--;
    for (long long i = 0; i < k; ++i) {
      was[(x + i) % n] = 0;
    }
  }
  return 0;
}
