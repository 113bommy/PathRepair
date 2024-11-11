#include <bits/stdc++.h>
using namespace std;
int S = 0;
bitset<105> visited;
pair<int, int> intervals[105];
bool hasPath(int node, int objective) {
  if (node == objective) return true;
  visited[node] = true;
  for (int i = int(0); i < int(S); i++)
    if (!visited[i])
      if ((intervals[node].first > intervals[i].first &&
           intervals[node].first < intervals[i].second) ||
          (intervals[node].second > intervals[i].first &&
           intervals[node].second < intervals[i].second))
        if (hasPath(i, objective)) return true;
  return false;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int N, t, x, y;
  cin >> N;
  while (N--) {
    cin >> t >> x >> y;
    if (t == 1)
      intervals[S++] = make_pair(x, y);
    else {
      visited.reset();
      if (hasPath(x, y))
        cout << "YES" << '\n';
      else
        cout << "NO" << '\n';
    }
  }
  return 0;
}
