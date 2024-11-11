#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
using v = vector<T>;
struct Minqueue {
  deque<pair<ll, ll>> q;
  ll cntadded = 0, cntremoved = 0;
  ll min() { return q.front().first; }
  void add(ll x) {
    while (!q.empty() && q.back().first > x) {
      q.pop_back();
    }
    q.push_back({x, cntadded});
    cntadded++;
  }
  void del() {
    if (!q.empty() && q.front().second == cntremoved) {
      q.pop_front();
    }
    cntremoved++;
  }
};
struct Entry {
  ll row, col, val;
  bool operator<(const Entry &rhs) const {
    if (val == rhs.val) {
      if (row == rhs.row) {
        return col > rhs.col;
      }
      return row > rhs.row;
    }
    return val > rhs.val;
  }
};
ll n, m, a, b;
const ll N = 1000;
ll mp[N + 1][N + 1];
ll minmp[N + 1][N + 1];
ll minrow[N + 1][N + 1];
ll summp[N + 1][N + 1];
ll sumrow[N + 1][N + 1];
bool marked[N + 1][N + 1] = {};
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  cin >> n >> m >> a >> b;
  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= m; j++) {
      cin >> mp[i][j];
    }
  }
  for (ll i = 1; i <= n; i++) {
    sumrow[i][1] = 0;
    for (ll j = 1; j <= b; j++) {
      sumrow[i][1] += mp[i][j];
    }
    for (ll j = 2; j <= m - b + 1; j++) {
      sumrow[i][j] = sumrow[i][j - 1] + mp[i][j + b - 1] - mp[i][j - 1];
    }
  }
  for (ll j = 1; j <= m - b + 1; j++) {
    summp[1][j] = 0;
    for (ll i = 1; i <= a; i++) {
      summp[1][j] += sumrow[i][j];
    }
    for (ll i = 2; i <= n - a + 1; i++) {
      summp[i][j] = summp[i - 1][j] + sumrow[i + a - 1][j] - sumrow[i - 1][j];
    }
  }
  for (ll i = 1; i <= n; i++) {
    Minqueue q;
    for (ll j = 1; j <= b - 1; j++) {
      q.add(mp[i][j]);
    }
    for (ll j = 1; j <= m - b + 1; j++) {
      q.add(mp[i][j + b - 1]);
      minrow[i][j] = q.min();
      q.del();
    }
  }
  for (ll j = 1; j <= m - b + 1; j++) {
    Minqueue q;
    for (ll i = 1; i <= a - 1; i++) {
      q.add(minrow[i][j]);
    }
    for (ll i = 1; i <= n - a + 1; i++) {
      q.add(minrow[i + a - 1][j]);
      minmp[i][j] = q.min();
      q.del();
    }
  }
  priority_queue<Entry> pq;
  const ll mult = a * b;
  for (ll i = 1; i <= n - a + 1; i++) {
    for (ll j = 1; j <= m - b + 1; j++) {
      pq.push(Entry{i, j, summp[i][j] - mult * minmp[i][j]});
    }
  }
  v<Entry> res;
  while (!pq.empty()) {
    const Entry cur = pq.top();
    pq.pop();
    if (!marked[cur.row][cur.col]) {
      res.push_back(cur);
      const ll loi = max<ll>(cur.row - (a - 1), 1);
      const ll hii = min<ll>(cur.row + (a - 1), n - a + 1);
      const ll loj = max<ll>(cur.col - (b - 1), 1);
      const ll hij = min<ll>(cur.col + (b - 1), m - b + 1);
      for (ll i = loi; i <= hii; i++) {
        for (ll j = loj; j <= hij; j++) {
          marked[i][j] = true;
        }
      }
    }
  }
  cout << res.size() << "\n";
  for (const Entry &cur : res) {
    cout << cur.row << " " << cur.col << " " << cur.val << "\n";
  }
}
