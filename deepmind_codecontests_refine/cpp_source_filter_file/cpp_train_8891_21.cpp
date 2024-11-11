#include <bits/stdc++.h>
using namespace std;
void faster(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int arr[200009], arr1[200009], arr2[200009];
int n, cnt1, cnt2;
vector<int> adj[200009];
vector<bool> visited;
vector<int> ans;
int cnt[200009];
int parent[200009];
int st1[200009], st2[200009];
int en1[200009], en2[200009];
queue<int> vak1[200009], vak2[200009];
bool vis[200009];
int depth[200009];
queue<int> q;
int getSum(int BITree[], int index) {
  int sum = 0;
  index = index + 1;
  while (index > 0) {
    sum += BITree[index];
    index -= index & (-index);
  }
  return sum;
}
void updateBIT(int BITree[], int n, int index, int val) {
  index = index + 1;
  while (index <= n) {
    BITree[index] += val;
    index += index & (-index);
  }
}
int sum(int x, int BITTree1[], int BITTree2[]) {
  return (getSum(BITTree1, x) * x) - getSum(BITTree2, x);
}
void updateRange(int BITTree1[], int BITTree2[], int n, int val, int l, int r) {
  updateBIT(BITTree1, n, l, val);
  updateBIT(BITTree1, n, r + 1, -val);
  updateBIT(BITTree2, n, l, val * (l - 1));
  updateBIT(BITTree2, n, r + 1, -val * r);
}
int rangeSum(int l, int r, int BITTree1[], int BITTree2[]) {
  return sum(r, BITTree1, BITTree2) - sum(l - 1, BITTree1, BITTree2);
}
int *constructBITree(int n) {
  int *BITree = new int[n + 1];
  for (int i = 1; i <= n; i++) BITree[i] = 0;
  return BITree;
}
void dfs(int v) {
  visited[v] = true;
  for (int u : adj[v]) {
    if (!visited[u]) dfs(u);
  }
  ans.push_back(v);
}
void topological_sort() {
  visited.assign(n + 1, false);
  ans.clear();
  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) dfs(i);
  }
  reverse(ans.begin(), ans.end());
}
void dfs2(int s, int e) {
  cnt[s] = 1;
  for (auto u : adj[s]) {
    if (u == e) continue;
    parent[u] = s;
    dfs2(u, s);
    cnt[s] += cnt[u];
  }
}
void bfs(int x) {
  vis[x] = true;
  depth[x] = 1;
  q.push(x);
  while (!q.empty()) {
    int s = q.front();
    q.pop();
    for (auto u : adj[s]) {
      if (vis[u]) continue;
      vis[u] = true;
      depth[u] = depth[s] + 1;
      q.push(u);
    }
  }
}
int32_t main() {
  faster();
  int q, x, i, j, y, chk;
  cin >> n >> q;
  for (i = 1; i <= n; i++) cin >> arr[i];
  for (i = 1; i < n; i++) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  topological_sort();
  dfs2(1, 1);
  bfs(1);
  for (i = 0; i < n; i++) {
    if (depth[ans[i + cnt[ans[i]] - 1]] & 1)
      vak1[ans[i + cnt[ans[i]] - 1]].push(ans[i]);
    else
      vak2[ans[i + cnt[ans[i]] - 1]].push(ans[i]);
  }
  for (i = 0; i < n; i++) {
    if (depth[ans[i]] & 1) {
      arr1[++cnt1] = ans[i];
      while (vak1[ans[i]].size()) {
        en1[vak1[ans[i]].front()] = cnt1;
        vak1[ans[i]].pop();
      }
    } else {
      arr2[++cnt2] = ans[i];
      while (vak2[ans[i]].size()) {
        en2[vak2[ans[i]].front()] = cnt2;
        vak2[ans[i]].pop();
      }
    }
  }
  st1[1] = 1;
  for (i = 2; i <= cnt1; i++) {
    if (st1[parent[arr1[i]]] == 0) st1[parent[arr1[i]]] = i;
    if (st1[arr1[i]] == 0) st1[arr1[i]] = i;
  }
  for (i = 1; i <= cnt2; i++) {
    if (st2[parent[arr2[i]]] == 0) st2[parent[arr2[i]]] = i;
    if (st2[arr2[i]] == 0) st2[arr2[i]] = i;
  }
  for (i = 1; i <= n; i++) {
    if (en1[i]) {
      en2[i] = st2[i] + cnt[i] - (en1[i] - st1[i] + 1) - 1;
    } else {
      en1[i] = st1[i] + cnt[i] - (en2[i] - st2[i] + 1) - 1;
    }
  }
  int *tree11, *tree12, *tree21, *tree22;
  tree11 = constructBITree(cnt1);
  tree12 = constructBITree(cnt1);
  tree21 = constructBITree(cnt2);
  tree22 = constructBITree(cnt2);
  for (i = 1; i <= cnt1; i++)
    updateRange(tree11, tree12, cnt1, arr[arr1[i]], i - 1, i - 1);
  for (i = 1; i <= cnt2; i++)
    updateRange(tree21, tree22, cnt2, arr[arr2[i]], i - 1, i - 1);
  while (q--) {
    cin >> chk;
    if (chk == 1) {
      cin >> x >> y;
      if (depth[x] % 2 == 0) y = -y;
      if (st1[x] < en1[x])
        updateRange(tree11, tree12, cnt1, y, st1[x] - 1, en1[x] - 1);
      if (st2[x] < en2[x])
        updateRange(tree21, tree22, cnt2, -y, st2[x] - 1, en2[x] - 1);
    } else {
      cin >> x;
      if (depth[x] & 1)
        cout << rangeSum(st1[x] - 1, st1[x] - 1, tree11, tree12) << endl;
      else
        cout << rangeSum(st2[x] - 1, st2[x] - 1, tree21, tree22) << endl;
    }
  }
  return 0;
}
