#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  std::cerr << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  std::cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
long long freq[1000005];
long long a[1000005];
long long cum[1000005];
long long righ[1000005];
long long n;
long long check(long long i) {
  for (long long j = 0; j < n - i + 1; j++) {
    if (cum[a[j + i - 1] - 1] - cum[a[j]] >= a[j + i - 1] - a[j] - 1) return 1;
  }
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(0);
  long long TESTS = 1;
  while (TESTS--) {
    cin >> n;
    for (long long i = 0; i < n; i++) {
      long long t;
      cin >> t;
      a[i] = t;
      freq[t]++;
    }
    sort(a, a + n);
    long long lo = 1, hi = n;
    for (long long i = 1; i < 200001; i++)
      if (freq[i] > 1) righ[i] = 1;
    for (long long i = 1; i < 200001; i++) {
      cum[i] = cum[i - 1] + righ[i];
    }
    while (lo <= hi) {
      long long mid = (lo + hi) >> 1;
      if (check(mid)) {
        lo = mid + 1;
        continue;
      } else {
        hi = mid - 1;
      }
    }
    cout << hi << '\n';
    for (long long j = 0; j < n - hi + 1; j++) {
      if (cum[a[j + hi - 1] - 1] - cum[a[j]] >= a[j + hi - 1] - a[j] - 1) {
        for (long long i = a[j]; i < a[j + hi - 1] + 1; i++) {
          for (long long k = 0; k < freq[i] - 1; k++) cout << i << " ";
        }
        for (long long i = a[j + hi - 1]; i >= a[j]; i--) cout << i << " ";
        return 0;
        ;
      }
    }
  }
}
