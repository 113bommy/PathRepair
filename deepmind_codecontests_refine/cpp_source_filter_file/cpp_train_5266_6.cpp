#include <bits/stdc++.h>
using namespace std;
int n, m, k, x;
vector<int> elem;
vector<pair<int, int> > buy;
bool cannot() {
  for (int i = 0; i < n; i += k)
    if (elem[i] < i / k) return 1;
  return 0;
}
bool mere(int pos) {
  int elem_ind = 0;
  int buy_ind = m - 1;
  for (int i = 0; i < n + pos; i++) {
    if (buy_ind < m - pos ||
        (elem_ind < n && elem[elem_ind] < buy[buy_ind].first)) {
      x = elem[elem_ind];
      elem_ind++;
    } else {
      x = buy[buy_ind].first;
      buy_ind--;
    }
    if (i % k == 0 && x < i / k) return 0;
  }
  return 1;
}
void solve() {
  int st = 1;
  int dr = m + 1;
  int ans = 0;
  while (st < dr) {
    int mid = (st + dr) / 2;
    if (mere(mid)) {
      st = mid + 1;
      ans = mid;
    } else
      dr = mid;
  }
  cout << ans << "\n";
  for (int i = m - 1; i >= m - ans; i--) cout << buy[i].second << " ";
}
int main() {
  cin.sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    elem.push_back(x);
  }
  sort(elem.begin(), elem.end());
  for (int i = 1; i <= m; i++) {
    cin >> x;
    buy.push_back({x, i});
  }
  sort(buy.begin(), buy.end());
  if (cannot()) {
    cout << -1;
    return 0;
  }
  solve();
  return 0;
}
