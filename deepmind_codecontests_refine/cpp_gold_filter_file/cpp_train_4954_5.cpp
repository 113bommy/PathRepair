#include <bits/stdc++.h>
using namespace std;
int N;
set<int> adj[111111];
int nextv(int a, int b) {
  if (a == *adj[b].rbegin())
    return *adj[b].begin();
  else
    return *++(adj[b].find(a));
}
int PID = 0;
vector<int> polygons[111111];
vector<int> adjp[111111];
int dfs(int a, int b) {
  int start = a;
  int p = PID++;
  polygons[p].push_back(a);
  polygons[p].push_back(b);
  vector<pair<int, int>> neighbors;
  while (true) {
    int c = nextv(a, b);
    if (c != (b + 1) % N && c != (b + N - 1) % N) {
      int pc = dfs(c, b);
      adjp[p].push_back(pc);
      adjp[pc].push_back(p);
    }
    if (c == start) break;
    polygons[p].push_back(c);
    a = b;
    b = c;
  }
  return p;
}
int assigned[111111];
int sizes[111111];
void compute_sizes(int r, int p = -1) {
  sizes[r] = 1;
  for (auto k : adjp[r]) {
    if (k != p && !assigned[k]) {
      compute_sizes(k, r);
      sizes[r] += sizes[k];
    }
  }
}
int get_centroid(int r, int p, int whole) {
  for (auto k : adjp[r])
    if (k != p && !assigned[k]) {
      if (sizes[k] > whole / 2) return get_centroid(k, r, whole);
    }
  return r;
}
void assign_labels(int r, int l) {
  compute_sizes(r);
  r = get_centroid(r, -1, sizes[r]);
  assigned[r] = l;
  for (int k : adjp[r])
    if (!assigned[k]) assign_labels(k, l + 1);
}
int main() {
  int M;
  scanf("%d%d", &N, &M);
  for (int i = 0; i < (M); ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    adj[a].insert(b);
    adj[b].insert(a);
  }
  for (int a = 0; a < (N); ++a) {
    adj[a].insert((a + 1) % N);
    adj[a].insert((a + N - 1) % N);
  }
  int root;
  for (int i = 0; i < (N); ++i)
    if (adj[i].size() == 2) {
      root = dfs((i + 1) % N, i);
      break;
    }
  assign_labels(root, 1);
  vector<pair<vector<int>, int>> sorted;
  for (int i = 0; i < (PID); ++i) {
    sorted.push_back({vector<int>(polygons[i].begin(), polygons[i].end()), i});
    sort(sorted[i].first.rbegin(), sorted[i].first.rend());
  }
  sort(sorted.begin(), sorted.end());
  for (int i = 0; i < (PID); ++i) {
    printf("%d ", assigned[sorted[i].second]);
  }
  printf("\n");
}
