#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> gr;
vector<long long> c;
vector<long long> ans;
long long fun(long long n) {
  if (n == 0) return 1;
  if (n < 10) return n;
  return max(fun(n / 10) * (n % 10), fun((n / 10) - 1) * 9);
}
void solve() {
  long long n;
  cin >> n;
  cout << fun(n) << endl;
}
int32_t main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
}
