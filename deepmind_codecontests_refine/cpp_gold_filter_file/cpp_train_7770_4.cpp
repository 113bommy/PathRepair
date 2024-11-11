#include <bits/stdc++.h>
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  std::cout << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  std::cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long i, j, n, m, k, cnt = 0, ans = 0, t = 1;
  string a, b;
  cin >> a >> b;
  n = a.length();
  m = b.length();
  map<char, set<long long> > mm;
  for (i = 0; i < n; i++) mm[a[i]].insert(i);
  for (i = 0; i < m; i++)
    if (!mm.count(b[i])) return cout << -1, 0;
  long long pr = -1;
  for (i = 0; i < m; i++) {
    auto it = mm[b[i]].upper_bound(pr);
    if (it == mm[b[i]].end())
      i--, pr = -1, ans++;
    else
      pr = (*it);
  }
  return cout << ans + 1, 0;
  return 0;
}
