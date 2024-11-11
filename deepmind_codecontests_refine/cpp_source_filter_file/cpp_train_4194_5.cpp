#include <bits/stdc++.h>
using namespace std;
double start_moment = 0;
double get_runtime() { return 1.0 * clock() / CLOCKS_PER_SEC; }
void reset_timer() { start_moment = get_runtime(); }
double timer_time() { return get_runtime() - start_moment; }
void runtime() { cout << fixed << setprecision(5) << get_runtime() << '\n'; }
template <class T>
void read(vector<T> &a, long long n) {
  T x;
  a.clear();
  for (long long i = 0; i < n; i++) {
    cin >> x;
    a.push_back(x);
  }
}
template <class T>
void write(vector<T> &a) {
  for (T x : a) cout << x << ' ';
  cout << '\n';
}
const long long INF = 1LL * 1001 * 1001 * 1001 * 1001 * 1001 * 1001;
int T;
long long a, b, c, d;
long long first(long long x) {
  long long res = x * a;
  res -= (long long)x * c * b;
  long long cnt = min((long long)x - 1, (long long)c / d);
  res += (long long)c * b;
  res += (long long)c * cnt * b;
  res -= cnt * (cnt + 1) / 2 * d * b;
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> T;
  while (T--) {
    cin >> a >> b >> c >> d;
    long long l = 1;
    long long r = 1000;
    long long mx = -INF;
    while (r - l > 2) {
      long long m1 = l + (r - l) / 3;
      long long m2 = r - (r - l) / 3;
      if (first(m1) > first(m2)) {
        r = m2;
      } else {
        l = m1;
      }
    }
    for (long long i = l; i <= r; i++) {
      mx = max(mx, first(i));
    }
    if (first(1001) > mx) {
      cout << -1 << '\n';
    } else {
      cout << mx << '\n';
    }
  }
}
