#include <bits/stdc++.h>
using namespace std;
const long long md = 1e9 + 7;
long long a[1000005], n;
deque<long long> v[300005];
deque<pair<long long, long long>> d;
bool mark[300005];
int main() {
  ios_base::sync_with_stdio(0);
  memset(mark, false, sizeof(mark));
  long long q, m, k, h, ans = 0, sum = 0, p, x, y;
  cin >> n >> q;
  for (int i = 0; i < q; ++i) {
    int type;
    cin >> type >> x;
    if (type == 1) {
      ++ans;
      v[x].push_back(i);
      d.push_back({i, x});
    } else if (type == 2) {
      while (!v[x].empty()) {
        mark[v[x].front()] = true;
        v[x].pop_front();
        --ans;
      }
    } else {
      while (d.size() and d.front().first <= x) {
        int j = d.front().first;
        int t = d.front().second;
        d.pop_front();
        if (!mark[j]) {
          mark[j] = true;
          v[t].pop_front();
          --ans;
        }
      }
    }
    cout << ans << '\n';
  }
}
