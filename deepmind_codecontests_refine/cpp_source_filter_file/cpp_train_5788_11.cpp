#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 5;
vector<int> adj[MAX], centroid_tree[MAX];
bool computed[MAX];
int size[MAX], centroid_father[MAX], dis[MAX];
int n, k, tree_size, centroid_root;
int dfs(int source, int father = -1, int cur_dis = 0) {
  dis[source] = cur_dis;
  size[source] = 1;
  tree_size++;
  for (auto &each : adj[source]) {
    if (each != father && !computed[each]) {
      size[source] += dfs(each, source, cur_dis + 1);
    }
  }
  return size[source];
}
int find_centroid(int source, int father = -1) {
  for (auto &each : adj[source]) {
    if (each != father && !computed[each] && size[each] > tree_size / 2) {
      return find_centroid(each, source);
    }
  }
  return source;
}
void build_centroid(int source, int last_centroid = -1) {
  tree_size = 0;
  dfs(source);
  int centroid = find_centroid(source);
  if (last_centroid != -1) {
    centroid_tree[last_centroid].push_back(centroid);
  } else {
    centroid_root = centroid;
  }
  centroid_father[centroid] = last_centroid;
  computed[centroid] = true;
  for (auto &each : adj[centroid]) {
    if (!computed[each]) {
      build_centroid(each, centroid);
    }
  }
}
long long get(int source, const vector<int> &app, const vector<long long> &len,
              vector<int> &new_app, vector<long long> &new_len) {
  long long v = (dis[source] + (k - 1)) / k;
  int r = dis[source] % k;
  long long total = v;
  for (int i = int(0); i < int(k + 1 - r); i++) {
    total += v * app[i];
    if (r == 0 && i > 0) {
      total += app[i];
    }
    total += len[i];
  }
  for (int i = int(k + 1 - r); i < int(k); i++) {
    total += v * app[i];
    total += len[i];
    total += app[i];
  }
  for (auto &each : centroid_tree[source]) {
    total += get(each, app, len, new_app, new_len);
  }
  new_app[r]++;
  new_len[r] += dis[source] / k;
  return total;
}
long long roll(int source) {
  dfs(source);
  long long total = 0;
  vector<int> app(5, 0);
  vector<long long> len(5, 0);
  for (auto &each : centroid_tree[source]) {
    vector<int> new_app(5, 0);
    vector<long long> new_len(5, 0);
    total += get(each, app, len, new_app, new_len);
    for (int i = int(0); i < int(5); i++) {
      app[i] += new_app[i];
      len[i] += new_len[i];
    }
  }
  computed[source] = true;
  for (auto &each : centroid_tree[source]) {
    total += roll(each);
  }
  return total;
}
int main() {
  scanf("%d %d", &n, &k);
  for (int i = int(0); i < int(n - 1); i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  build_centroid(1);
  memset(computed, false, sizeof computed);
  printf("%lld\n", roll(centroid_root));
  return 0;
}
