#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long N = 5e3 + 3, M = 1e5 + 3, BIG = (long long)1e9 + 3,
                MOD = 1e9 + 7, P = 29, P2 = 'z' - 'a' + 1, K = 4;
const double PI = 3.14159265359;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long n, s, f, ans = 0, ans_v = BIG;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  cin >> s >> f;
  for (int i = 0; i < n; ++i) a.push_back(a[i]);
  vector<long long> pref(a.size());
  for (int i = 0; i < a.size(); ++i) pref[i] = (i > 0 ? pref[i - 1] : 0) + a[i];
  long long sum_now = 0, sz = f - s;
  ans = pref[sz - 1];
  ans_v = 1;
  long long t = 1;
  for (int i = sz; i < a.size(); ++i) {
    sum_now = pref[i] - pref[i - sz];
    --t;
    if (t == 0) t = n;
    if (ans < sum_now || (ans == sum_now && t < ans_v)) {
      ans = sum_now;
      ans_v = t;
    }
  }
  cout << ans_v;
  return 0;
}
