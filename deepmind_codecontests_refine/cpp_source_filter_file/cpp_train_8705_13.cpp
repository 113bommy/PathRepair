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
constexpr long long M7 = 1000000007;
constexpr long long M9 = 1000000009ll;
constexpr long long MFFT = 998244353ll;
constexpr long long E6 = 1000000ll;
constexpr long long E9 = 1000000000ll;
constexpr long long INF = 2000000000000000000ll;
template <class T>
void outv(T &a) {
  for (auto &x : a) cout << x << ' ';
}
long long find_l(vector<long long> &a, long long x) {
  long long l = -1;
  long long r = a.size();
  while (l + 1 < r) {
    long long mid = (l + r) / 2;
    if (a[mid] > x)
      r = mid;
    else
      l = mid;
  }
  return l;
}
void solve() {
  long long n, m;
  __read(n, m);
  vector<long long> a(n);
  for (auto &v : a) cin >> v;
  long long mid = n / 2;
  vector<long long> first(1 << mid);
  vector<long long> second(1 << (n - mid));
  for (long long i = 0; i < 1 << mid; ++i) {
    long long sum = 0;
    for (long long j = 0; j < mid; ++j) {
      if (i & (1 << j)) {
        sum = (sum + a[j]) % m;
      }
    }
    first[i] = sum;
  }
  for (long long i = 0; i < 1 << (n - mid); ++i) {
    long long sum = 0;
    for (long long j = 0; j < (n - mid); ++j) {
      if (i & (1 << j)) {
        sum = (sum + a[mid + j]) % m;
      }
    }
    second[i] = sum;
  }
  sort((second).begin(), (second).end());
  long long res = 0;
  for (auto el : second) {
    res = max(res, el);
  }
  for (auto el : first) {
    long long l = find_l(second, el);
    if (l == second.size()) continue;
    res = max(res, (el + second[l]) % m);
    res = max(res, el);
  }
  cout << res << '\n';
}
signed main(signed argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  if (argc > 1 && (string)argv[1] == "local") {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long i = 1;
    clock_t start_time, end_time;
    cout << "/////Test #" << i << "/////\n";
    start_time = clock();
    solve();
    end_time = clock();
    long double seconds_pass =
        (long double)(end_time - start_time) / CLOCKS_PER_SEC;
    cout << "\n//Time: ";
    cout << setprecision(15) << seconds_pass << '\n';
    while (cin.peek() != -1) {
      ++i;
      cout << '\n';
      cout << '\n';
      cout << "/////Test #" << i << "/////\n";
      start_time = clock();
      solve();
      end_time = clock();
      seconds_pass = (long double)(end_time - start_time) / CLOCKS_PER_SEC;
      cout << "\n//Time: ";
      cout << setprecision(15) << seconds_pass << '\n';
    }
  } else {
    solve();
  }
  return 0;
}
