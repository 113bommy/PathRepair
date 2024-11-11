#include <bits/stdc++.h>
using namespace std;
long long dist[10002][1002], pos[1002], sok = 1000000000001;
bool v[10002][1002];
deque<pair<long long, long long> > q;
long long m, n, mod, r, mini;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  cin >> m >> n, mini = sok;
  for (long long i = 0; i < n; i++) cin >> pos[i];
  sort(pos, pos + n);
  cin >> mod >> r;
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < mod; j++) dist[i][j] = sok;
  q.push_back({0, 0}), dist[0][0] = 0;
  while (q.size() > 0) {
    long long id = q.front().first, ert = q.front().second;
    q.pop_front();
    if (!v[id][ert]) {
      v[id][ert] = 1;
      if (id) {
        long long tav = pos[id] - pos[id - 1], x = ert + tav, y = x % mod;
        if (x <= mod) {
          dist[id - 1][y] = min(dist[id - 1][y], dist[id][ert] + (y != x));
          if (y)
            q.push_front({id - 1, y});
          else
            q.push_back({id - 1, y});
        }
      }
      if (id + 1 < n) {
        long long tav = pos[id + 1] - pos[id], x = ert + tav, y = x % mod;
        if (x <= mod) {
          dist[id + 1][y] = min(dist[id + 1][y], dist[id][ert] + (y != x));
          if (y)
            q.push_front({id + 1, y});
          else
            q.push_back({id + 1, y});
        }
      }
    }
  }
  for (long long i = 0; i < n; i++)
    if (pos[n - 1] - pos[i] <= mod)
      mini = min(mini, dist[i][0] * (mod + r) + pos[n - 1] - pos[i]);
  if (mini == sok) mini = -1;
  cout << mini << "\n";
  return 0;
}
