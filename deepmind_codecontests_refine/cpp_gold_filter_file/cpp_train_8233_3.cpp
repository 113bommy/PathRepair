#include <bits/stdc++.h>
using namespace std;
const int NMAX = 12;
vector<int> nxt[NMAX];
vector<int> a[NMAX];
int N, M;
pair<int, int> fillFar(int u, vector<pair<int, int> >& far,
                       map<pair<int, int>, int>& cnt, const int M) {
  if (far[u].first != -1) {
    return far[u];
  }
  if (cnt[pair<int, int>(u, nxt[0][u])] == M) {
    pair<int, int> res = fillFar(nxt[0][u], far, cnt, M);
    res.second++;
    far[u] = res;
    return res;
  }
  far[u] = pair<int, int>(u, 1);
  return pair<int, int>(u, 1);
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> N >> M;
  map<pair<int, int>, int> cnt;
  for (int i = 0; i < M; ++i) {
    a[i] = vector<int>(N);
    nxt[i] = vector<int>(N + 1, 0);
    for (int j = 0; j < a[i].size(); ++j) {
      cin >> a[i][j];
      if (j != 0) {
        nxt[i][a[i][j - 1]] = a[i][j];
        cnt[pair<int, int>(a[i][j - 1], a[i][j])]++;
      }
    }
  }
  vector<pair<int, int> > far(N + 1, pair<int, int>(-1, -1));
  long long ans = 0;
  for (int i = 1; i <= N; ++i) {
    fillFar(i, far, cnt, M);
    ans += far[i].second;
  }
  cout << ans << endl;
  return 0;
}
