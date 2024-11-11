#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
  return out << '(' << p.first << ", " << p.second << ')';
}
vector<int64_t> fib = {1, 2};
vector<pair<int, int> > tmpa, tmpb;
pair<int, int> solve(int64_t i, int n, vector<pair<int, int> >& tmp) {
  if (n == 0) return tmp[n] = {0, 0};
  if (n == 1) return tmp[n] = {i != 1, i != 2};
  if (i > fib[n - 1]) {
    auto ans = solve(i - fib[n - 1], n - 2, tmp);
    return tmp[n] = {ans.first + 1, ans.second};
  } else {
    auto ans = solve(i, n - 1, tmp);
    return tmp[n] = {min(ans.first, ans.second + 2),
                     min(ans.first, ans.second) + 1 + n / 2};
  }
}
int solve(int64_t a, int64_t b, int n) {
  if (a == b) return 0;
  if (n == 1) return 1;
  if (b > fib[n - 1]) return solve(a - fib[n - 1], b - fib[n - 1], n - 2);
  if (a <= fib[n - 1])
    return min({solve(a, b, n - 1), tmpa[n - 1].first + tmpb[n - 1].second + 2,
                tmpa[n - 1].second + tmpb[n - 1].first + 2});
  return tmpa[n - 2].first + min(tmpb[n - 1].first, tmpb[n - 1].second) + 1;
}
signed main() {
  while (fib.back() < 100000000000000000LL)
    fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
  int t, n;
  cin >> t >> n;
  if (n > fib.size()) n = fib.size();
  tmpa.resize(n + 1);
  tmpb.resize(n + 1);
  fib.resize(n);
  while (t--) {
    int64_t a, b;
    cin >> a >> b;
    if (a < b) swap(a, b);
    fill((tmpa).begin(), (tmpa).end(), make_pair(0, 0));
    fill((tmpb).begin(), (tmpb).end(), make_pair(0, 0));
    solve(a, n, tmpa), solve(b, n, tmpb);
    cout << solve(a, b, n) << endl;
  }
}
