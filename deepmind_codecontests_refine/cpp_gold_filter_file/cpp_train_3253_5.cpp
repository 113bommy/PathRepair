#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int N, M;
  cin >> N >> M;
  int x, y;
  vector<vector<int>> v1(500005);
  for (int i = 0; i < M; i++) {
    cin >> x >> y;
    v1[x].push_back(y);
    v1[y].push_back(x);
  }
  int p;
  vector<pair<int, int>> v2;
  map<int, int> mp;
  for (int i = 1; i <= N; i++) {
    cin >> p;
    mp[i] = p;
    v2.push_back({p, i});
  }
  int t = 0;
  sort(v2.begin(), v2.end());
  for (int i = 0; i < N; i++) {
    int k1 = 0;
    map<int, int> mp2;
    for (int j = 0; j < v1[v2[i].second].size(); j++) {
      mp2[mp[v1[v2[i].second][j]]]++;
    }
    if (mp2[v2[i].first] >= 1) t = 1;
    for (int k = 1; k < v2[i].first; k++) {
      if (mp2[k] == 0) t = 1;
    }
    mp2.clear();
  }
  if (t)
    cout << "-1" << '\n';
  else {
    for (int i = 0; i < N; i++) {
      cout << v2[i].second << " ";
    }
  }
  return 0;
}
