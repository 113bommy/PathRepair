#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  long long int test, i, j;
  test = 1;
  while (test--) {
    long long int n, k;
    cin >> n >> k;
    vector<long long int> a(n), col(n);
    map<long long int, long long int> mp;
    long long int mf = -1;
    for (i = 0; i < n; i++) cin >> a[i], mp[a[i]]++, mf = max(mf, mp[a[i]]);
    if (mf > k && n < k)
      cout << "NO\n";
    else {
      long long int c = 1;
      cout << "YES\n";
      for (auto x : mp) {
        long long int el = x.first;
        for (i = 0; i < n; i++) {
          if (a[i] == el) col[i] = c, c++, c %= k;
          if (c == 0) c = k;
        }
      }
      for (auto x : col) cout << x << ' ';
      cout << '\n';
    }
  }
  return 0;
}
