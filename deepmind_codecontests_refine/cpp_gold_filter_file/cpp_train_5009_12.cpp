#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  if (max(a.first, a.second) != max(b.first, b.second))
    return max(a.first, a.second) < max(b.first, b.second);
  else if (a.first != b.first)
    return a.first < b.first;
  else
    return a.second > b.second;
}
int distt(pair<long long, long long> a, pair<long long, long long> b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
  sort(a.begin(), a.end(), cmp);
  pair<long long, long long> nxt[2];
  pair<long long, long long> pos[2] = {make_pair(0, 0)};
  long long nextDist[2];
  long long dist[2] = {0};
  for (int l = 0, r = 0; l < n; l = r) {
    while (r < n &&
           max(a[l].first, a[l].second) == max(a[r].first, a[r].second)) {
      r++;
    }
    nxt[0] = a[l];
    nxt[1] = a[r - 1];
    long long difff = distt(nxt[0], nxt[1]);
    nextDist[0] = min(dist[0] + difff + distt(pos[0], nxt[1]),
                      dist[1] + difff + distt(pos[1], nxt[1]));
    nextDist[1] = min(dist[0] + difff + distt(pos[0], nxt[0]),
                      dist[1] + difff + distt(pos[1], nxt[0]));
    for (int i = 0; i < 2; i++) {
      dist[i] = nextDist[i];
      pos[i] = nxt[i];
    }
  }
  cout << min(dist[0], dist[1]) << '\n';
  return 0;
}
