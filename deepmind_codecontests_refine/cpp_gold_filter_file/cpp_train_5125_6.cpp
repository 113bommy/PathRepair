#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  if (fopen("inp.txt", "r"))
    freopen("inp.txt", "r", stdin), freopen("out.txt", "w", stdout);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n, d;
    cin >> n >> d;
    long long a[n];
    for (long long i = 0; i < n; ++i) cin >> a[i];
    long long ans = 0;
    for (long long i = 1; i < n; ++i) {
      long long dis = i;
      for (long long j = 0; j < a[i]; ++j)
        if (d - dis >= 0) d -= dis, ans++;
    }
    cout << a[0] + ans << "\n";
  }
  return 0;
}
