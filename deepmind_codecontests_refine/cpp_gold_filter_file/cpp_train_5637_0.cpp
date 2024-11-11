#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename Arg1>
void debug(const char* name, Arg1&& arg1) {
  cerr << name << " = " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void debug(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " = " << arg1;
  debug(comma, args...);
}
void c_p_c() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
bool present[200001];
int32_t main() {
  c_p_c();
  long long n;
  cin >> n;
  long long* arr = new long long[n];
  ;
  for (long long i = 0; i < n; ++i) {
    cin >> arr[i];
    present[arr[i]] = 1;
  }
  sort(arr, arr + n);
  long long minsum = arr[0] + arr[1];
  long long maxsum = arr[n - 1] + arr[n - 2];
  long long ans = 0;
  for (long long sm = minsum; sm <= maxsum; ++sm) {
    long long curans = 0;
    for (long long i = 0; i < n && arr[i] < sm; ++i) {
      if (present[sm - arr[i]]) curans++;
    }
    curans /= 2;
    ans = max(ans, curans);
  }
  cout << ans << '\n';
  return 0;
}
