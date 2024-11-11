#include <bits/stdc++.h>
using namespace std;
const long long int INF = (1LL << 58);
const bool DEBUG = 0;
const int MAX_LIMIT = 1000006;
int rows, cols;
std::vector<vector<pair<int, int> > > row, col;
std::vector<int> adj[MAX_LIMIT], toProcess;
std::vector<vector<int> > mat, idMatrix;
int val[MAX_LIMIT];
void dfs(int node) {
  int i, limit = adj[node].size();
  if (limit == 0) val[node] = 1;
  for (i = 0; i < limit; i++) {
    int v = adj[node][i];
    if (!val[v]) dfs(v);
    val[node] = max(val[node], val[v] + 1);
  }
  return;
}
const int NODES_LIMIT = 1000006;
stack<int> st;
int nodes;
bool vis[NODES_LIMIT];
void topological_sort(int node) {
  if (vis[node]) return;
  vis[node] = 1;
  int limit = adj[node].size();
  int i;
  for (i = 0; i < limit; i++) topological_sort(adj[node][i]);
  st.push(node);
}
void drive_topological_sort() {
  int i;
  for (i = 1; i < nodes + 1; i++)
    if (!vis[i]) topological_sort(i);
  while (!st.empty()) {
    int ele = st.top();
    st.pop();
    toProcess.push_back(ele);
  }
  return;
}
const int ITEMS_NO = 1000006;
int par[ITEMS_NO], size[ITEMS_NO];
void initDSU(int noOfItems) {
  for (int i = 0; i < noOfItems; i++) {
    par[i] = i;
    size[i] = 1;
  }
}
int getRoot(int x) {
  if (par[x] == x) {
    return x;
  }
  return par[x] = getRoot(par[x]);
}
void merge(int x, int y) {
  int root1 = getRoot(x);
  int root2 = getRoot(y);
  if (root1 == root2) {
    return;
  }
  if (size[root1] < size[root2]) {
    swap(root1, root2);
  }
  size[root1] += size[root2];
  par[root2] = root1;
}
map<int, int> rowPresence[MAX_LIMIT], colPresence[MAX_LIMIT];
int idMapping[MAX_LIMIT];
int getCellId(int x, int y) { return (x * cols + y) + 1; }
int main() {
  int i, j;
  scanf("%d", &rows);
  scanf("%d", &cols);
  initDSU(rows * cols + 2);
  row.resize(rows);
  col.resize(cols);
  mat.resize(rows);
  idMatrix.resize(rows);
  for (i = 0; i < rows; i++) {
    idMatrix[i].resize(cols);
    mat[i].resize(cols);
  }
  int id = 1;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      int temp;
      scanf("%d", &temp);
      mat[i][j] = temp;
      rowPresence[i][temp] = getCellId(i, j);
      colPresence[j][temp] = getCellId(i, j);
    }
  }
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      int x = mat[i][j];
      int thisCellId = getCellId(i, j);
      int toMergeWith = rowPresence[i][x];
      merge(thisCellId, toMergeWith);
      toMergeWith = colPresence[j][x];
      merge(thisCellId, toMergeWith);
    }
  }
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      int x = mat[i][j];
      int thisCellId = getCellId(i, j);
      if (thisCellId == getRoot(thisCellId)) idMapping[thisCellId] = id++;
    }
  }
  for (i = 0; i < rows; i++) rowPresence[i].clear();
  for (j = 0; j < cols; j++) colPresence[j].clear();
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      int x = mat[i][j];
      int thisCellId = getCellId(i, j);
      idMatrix[i][j] = idMapping[getRoot(getCellId(i, j))];
      row[i].push_back(make_pair(mat[i][j], idMatrix[i][j]));
      col[j].push_back(make_pair(mat[i][j], idMatrix[i][j]));
    }
  }
  mat.clear();
  for (i = 0; i < rows; i++) {
    sort(row[i].begin(), row[i].end());
    for (j = 0; j < cols - 1; j++) {
      int u = row[i][j + 1].second;
      int v = row[i][j].second;
      if (u != v) adj[u].push_back(v);
    }
  }
  row.clear();
  for (j = 0; j < cols; j++) {
    sort(col[j].begin(), col[j].end());
    for (i = 0; i < rows - 1; i++) {
      int u = col[j][i + 1].second;
      int v = col[j][i].second;
      if (u != v) adj[u].push_back(v);
    }
  }
  col.clear();
  for (i = 1; i < id; i++) {
    vector<int>::iterator itr = unique(adj[i].begin(), adj[i].end());
    adj[i].resize(distance(adj[i].begin(), itr));
  }
  nodes = id - 1;
  drive_topological_sort();
  for (i = 0; i < toProcess.size(); i++) dfs(toProcess[i]);
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) printf("%d ", val[idMatrix[i][j]]);
    printf("\n");
  }
  return 0;
}
