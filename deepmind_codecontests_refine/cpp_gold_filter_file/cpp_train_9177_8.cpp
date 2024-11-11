#include <bits/stdc++.h>
const long long N = 3e5 + 5, MOD = 1e9 + 7, INF = LONG_MAX;
using namespace std;
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
long long n, m, t, a[N];
deque<pair<long long, long long> > pos, neg, zero;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i] > 0)
      pos.push_back({-1 * a[i] - 1, i});
    else if (a[i] < 0)
      pos.push_back({a[i], i});
    else
      a[i] = -1;
  }
  if (n & 1 && !pos.size()) a[n] = 0;
  sort(pos.begin(), pos.end());
  if (n % 2 && pos.size()) {
    a[pos[0].second] = -pos[0].first - 1;
    pos.pop_front();
  }
  for (auto it : pos) a[it.second] = it.first;
  for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
}
