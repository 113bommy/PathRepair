#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
struct _ {
  ios_base::Init i;
  _() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(10);
  }
} ___;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << "  ";
  __f(comma + 1, args...);
}
signed main() {
  string s;
  cin >> s;
  map<char, long long int> mm;
  for (auto it : s) mm[it]++;
  long long int n;
  cin >> n;
  if (n < mm.size()) {
    cout << -1;
    return 0;
  }
  long long int lo = 1, hi = 2000;
  while (hi > lo) {
    long long int mid = (hi + lo) >> 1;
    long long int sum = 0;
    for (auto it : mm) {
      long long int x = it.second / mid;
      if (it.second % mid != 0) x++;
      sum += x;
    }
    if (sum <= n)
      hi = mid;
    else
      lo = mid + 1;
  }
  string ans;
  char xx;
  for (auto it : mm) {
    long long int x = it.second / lo;
    if (it.second % lo != 0) x++;
    for (long long int i = 0; i++ < x;) ans += it.first;
    xx = it.first;
  }
  long long int dd = ans.size();
  for (long long int i = 0; i++ < n - dd;) ans += xx;
  cout << ans << '\n';
  cout << lo << '\n';
}
