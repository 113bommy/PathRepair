#include <bits/stdc++.h>
using namespace std;
const int mxN = 600000;
const int mxQ = 600000;
int n, q;
vector<pair<int, int> > adj[mxN + 5];
int subsz[mxN + 5];
bool used[mxN + 5];
int get_subtree_size(int u, int p = -1) {
  subsz[u] = 1;
  for (auto& to : adj[u]) {
    if (to.first != p && !used[to.first]) {
      subsz[u] += get_subtree_size(to.first, u);
    }
  }
  return subsz[u];
}
int get_centroid(int desired, int u, int p = -1) {
  for (auto& to : adj[u]) {
    if (to.first != p && !used[to.first] && subsz[to.first] >= desired) {
      return get_centroid(desired, to.first, u);
    }
  }
  return u;
}
long long w1[mxN + 5], w2[mxN + 5][2];
int qu[mxQ + 5][2];
vector<int> qus[mxQ + 5];
long long result[mxQ + 5];
int n_cent;
long long dist_tmp[mxN + 5][2];
int is_cal[mxQ + 5];
void compute(int u, int p = -1) {
  for (auto& v : qus[u]) {
    if (result[v] == -1) {
      if (is_cal[v] == n_cent) {
        int &x = qu[v][0], &y = qu[v][1];
        result[v] = min(dist_tmp[x][0] + dist_tmp[y][0],
                        dist_tmp[x][1] + dist_tmp[y][1]);
      } else {
        is_cal[v] = n_cent;
      }
    }
  }
  for (auto& to : adj[u]) {
    if (!used[to.first] && to.first != p) {
      for (int k = 0; k < 2; k++) {
        long long &dst0 = dist_tmp[to.first << 1][k],
                  &dst1 = dist_tmp[to.first << 1 | 1][k];
        dst0 = dist_tmp[u << 1][k] + w2[to.second][0];
        dst1 = dist_tmp[u << 1 | 1][k] + w2[to.second][1];
        dst0 = min(dst0, dst1 + w1[to.first]);
        dst1 = min(dst1, dst0 + w1[to.first]);
      }
      compute(to.first, u);
    }
  }
}
void centroid_decomp(int u) {
  int centroid = get_centroid(get_subtree_size(u) >> 1, u);
  used[centroid] = true;
  for (auto& to : adj[centroid]) {
    if (!used[to.first]) {
      centroid_decomp(to.first);
    }
  }
  used[centroid] = false;
  dist_tmp[centroid << 1][0] = dist_tmp[centroid << 1 | 1][1] = 0;
  dist_tmp[centroid << 1][1] = dist_tmp[centroid << 1 | 1][0] = w1[centroid];
  n_cent++;
  compute(centroid);
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> w1[i];
  }
  for (int i = 0, x, y; i + 1 < n; i++) {
    cin >> x >> y >> w2[i][0] >> w2[i][1];
    x--, y--;
    adj[x].emplace_back(y, i);
    adj[y].emplace_back(x, i);
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> qu[i][0] >> qu[i][1];
    qu[i][0]--, qu[i][1]--;
    qus[qu[i][0] >> 1].emplace_back(i);
    qus[qu[i][1] >> 1].emplace_back(i);
  }
  priority_queue<pair<long long, int> > pq;
  for (int i = 0; i < n; i++) {
    pq.emplace(-w1[i], i);
  }
  while (!pq.empty()) {
    int u = pq.top().second;
    int cdist = -pq.top().first;
    pq.pop();
    if (w1[u] < cdist) continue;
    for (auto& to : adj[u]) {
      if (w1[to.first] > cdist + w2[to.second][0] + w2[to.second][1]) {
        pq.emplace(
            -(w1[to.first] = cdist + w2[to.second][0] + w2[to.second][1]),
            to.first);
      }
    }
  }
  for (int i = 0; i < q; i++) {
    result[i] = -1;
  }
  n_cent = 0;
  centroid_decomp(0);
  for (int i = 0; i < q; i++) {
    cout << result[i] << " ";
  }
  return 0;
}
