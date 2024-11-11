#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<long, long>;
using vi = vector<int>;
using vll = vector<ll>;
using vpi = vector<pi>;
using vpll = vector<pll>;
const int mod = 1e9 + 7;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
int v[200005];
int n;
struct comp_interv {
  bool operator()(pi a, pi b) {
    return (a.second - a.first + 1 < b.second - b.first + 1) ||
           (a.second - a.first + 1 == b.second - b.first + 1 &&
            a.first > b.first);
  }
};
void bfs() {
  priority_queue<pair<int, int>, vector<pi>, comp_interv> q;
  q.push({1, n});
  int cont = 1;
  while (!q.empty()) {
    auto curr = q.top();
    q.pop();
    int len = curr.second - curr.first + 1;
    int m = len % 2 == 0 ? (curr.first + curr.second - 1) / 2
                         : (curr.first + curr.second) / 2;
    v[m] = cont++;
    if (len == 1) continue;
    if (curr.first < m) q.push({curr.first, m - 1});
    if (curr.second > m) q.push({m + 1, curr.second});
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    memset(v, 0, sizeof(v));
    cin >> n;
    bfs();
    for (int i = int((1)); i <= int((n)); i++) cout << v[i] << ' ';
    cout << '\n';
  }
  return 0;
}
