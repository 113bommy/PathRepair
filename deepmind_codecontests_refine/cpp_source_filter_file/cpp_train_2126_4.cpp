#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
  for (auto& vi : vec) os << vi << " ";
  return os;
}
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& ai : a) cin >> ai;
  if (a[0] > 1) return !(cout << -1 << endl);
  vector<pair<int, int>> lb(n), ub(n);
  lb[0] = ub[0] = {1, 1};
  for (int i = 1; i < n; i++) {
    lb[i] = lb[i - 1], ub[i] = ub[i - 1];
    if (++lb[i].second > 5) lb[i].first++, lb[i].second = 1;
    if (++ub[i].second > 2) ub[i].first++, ub[i].second = 1;
    if (a[i]) {
      if (lb[i].first <= a[i] && a[i] <= ub[i].first) {
        lb[i] = max(lb[i], {a[i], 1});
        ub[i] = min(ub[i], {a[i], 5});
      } else {
        return !(cout << -1 << endl);
      }
    }
  }
  auto ans = ub[n - 1];
  if (ans.second == 1) ans.first--, ans.second = 5;
  if (ans < lb[n - 1]) return !(cout << -2 << endl);
  cout << ans.first << endl;
  vector<int> second(ans.first + 1);
  a[n - 1] = ans.first, second[ans.first]++;
  for (int i = n - 2; i >= 0; i--) {
    a[i] = min(a[i + 1], ub[i].first);
    if (second[a[i]] == 5) a[i]--;
    second[a[i]]++;
  }
  cout << a << endl;
  return 0;
}
