#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
using ll = long long;
using ii = pair<int, int>;
const int N = 1e5 + 5, LG = 19, MOD = 998244353;
const int SQ = 500;
const long double EPS = 1e-7;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<ii> cells;
  queue<int> q;
  int prv = 0;
  int head = 0;
  for (int i = 0; i < n; i++)
    if (a[i]) {
      if (a[i] == 1 && !q.empty()) {
        cells.emplace_back(q.front(), i + 1);
        q.pop();
      } else {
        if (prv == 3) cells.emplace_back(head, i + 1);
        cells.emplace_back(++head, i + 1);
        prv = a[i];
        if (a[i] == 2) q.push(prv);
      }
    }
  if (!q.empty() || prv == 3) {
    cout << "-1\n";
  } else {
    cout << cells.size() << endl;
    for (auto x : cells) cout << x.first << ' ' << x.second << '\n';
  }
  return 0;
}
