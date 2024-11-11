#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
std::pair<T, U> operator+(const std::pair<T, U>& l, const std::pair<T, U>& r) {
  return {l.first + r.first, l.second + r.second};
}
typedef void (*callback_function)(void);
const long long ZERO = 0LL;
const long long INF64 = 1e18;
const long long INF32 = 1e9;
const long long MOD = 1e9 + 7;
const long double PI = acos(-1.0L);
const long double EPS = static_cast<long double>(1e-9);
inline long long Pow(long long a, long long k) {
  long long s = 1;
  for (; k; k >>= 1) {
    k& 1 ? s = 1LL * s * a % MOD : 0;
    a = 1LL * a * a % MOD;
  }
  return s;
}
const long long N = 1e6 + 7;
void input() {}
void output() {}
void preprocess() {}
void debug() {
  if (true) {
  }
}
long long cnt[123];
void solve() {
  preprocess();
  long long n, m;
  cin >> n >> m;
  long long a[n];
  for (long long i = (0); i < (n); i++) {
    cin >> a[i];
    a[i]--;
  }
  long long b[m];
  long long sum = 0;
  for (long long i = (0); i < (m); i++) {
    cin >> b[i];
    sum += b[i];
  }
  for (long long i = (0); i < (sum); i++) {
    cnt[a[i]]++;
  }
  long long C = 0;
  for (long long i = (0); i < (m); i++) {
    if (cnt[i] == b[i]) {
      C++;
    }
  }
  if (C == m) {
    cout << "YES" << endl;
    return;
  }
  for (long long i = (sum); i < (n); i++) {
    long long x = a[i - sum];
    cnt[x]--;
    if (cnt[x] == b[x] - 1) {
      C--;
    }
    x = a[i];
    cnt[x]++;
    if (cnt[x] == b[x]) {
      C++;
    }
    if (C == m) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  {
    input();
    solve();
    output();
  }
  return 0;
}
