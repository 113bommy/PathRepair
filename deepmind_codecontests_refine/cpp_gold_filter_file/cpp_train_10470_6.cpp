#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, i, x, ans;
  cin >> n;
  set<long long> s;
  ans = 0;
  for (i = 0; i < n; i++) {
    cin >> x;
    if (x == i + 1)
      ans++;
    else
      s.insert(x);
  }
  cout << ans + (s.size()) / 2 << '\n';
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  { solve(); }
  cerr << " Execution : " << (1.0 * clock()) / CLOCKS_PER_SEC << "s \n";
  return 0;
}
