#include <bits/stdc++.h>
using namespace std;
const int N = int(1e5) + 10;
const int LOGN = 20;
const int INF = int(2e9);
vector<int> tree[N];
int DP[N][LOGN];
int root;
int visited[N];
int n, m;
int prefixSumTime[N];
int level[N];
vector<pair<int, int> > ST[4 * N];
int baseArray[N];
int posInBaseArray[N];
int lenBA;
int numChain[N];
int chainHead[N];
int chainParent[N];
int sizeSubtree[N];
int chainNo;
void dfs(int u) {
  visited[u] = 1;
  sizeSubtree[u] = 1;
  for (int i = 0; i < (int)(tree[u].size()); i++) {
    int w = tree[u][i];
    if (!visited[w]) {
      level[w] = level[u] + 1;
      dfs(w);
      sizeSubtree[u] += sizeSubtree[w];
    }
  }
}
void HLD(int u) {
  visited[u] = 1;
  numChain[u] = chainNo;
  posInBaseArray[u] = lenBA;
  baseArray[lenBA++] = u;
  int sc = -1;
  int mx = -INF;
  for (int i = 0; i < (int)(tree[u].size()); i++) {
    int w = tree[u][i];
    if (!visited[w] && sizeSubtree[w] > mx) {
      sc = w;
      mx = sizeSubtree[w];
    }
  }
  if (sc != -1) HLD(sc);
  for (int i = 0; i < (int)(tree[u].size()); i++) {
    int w = tree[u][i];
    if (!visited[w]) {
      chainNo++;
      chainHead[chainNo] = w;
      chainParent[chainNo] = u;
      HLD(w);
    }
  }
}
void build_ST(int node = 1, int l = 0, int r = lenBA) {
  if (l == r - 1) {
    ST[node].push_back(make_pair(0, 0));
    return;
  }
  int leftChild = node << 1;
  int rightChild = leftChild | 1;
  int mid = (l + r) >> 1;
  build_ST(leftChild, l, mid);
  build_ST(rightChild, mid, r);
  int la = ST[leftChild][0].second;
  int ra = ST[rightChild][0].second;
  ST[node].push_back(make_pair(0, la + ra));
}
void update_ST(int pos, int val, int year, int node = 1, int l = 0,
               int r = lenBA) {
  if (l == pos && l == r - 1) {
    ST[node].push_back(make_pair(year, val));
    return;
  }
  int leftChild = node << 1;
  int rightChild = leftChild | 1;
  int mid = (l + r) >> 1;
  if (pos < mid)
    update_ST(pos, val, year, leftChild, l, mid);
  else
    update_ST(pos, val, year, rightChild, mid, r);
  int lc = (int)(ST[leftChild].size()) - 1;
  int rc = (int)(ST[rightChild].size()) - 1;
  ST[node].push_back(
      make_pair(year, ST[leftChild][lc].second + ST[rightChild][rc].second));
}
int query_ST_ok(int L, int R, int year, int node = 1, int l = 0,
                int r = lenBA) {
  if (L <= l && r <= R) {
    vector<pair<int, int> > &A = ST[node];
    int l = 0, h = (int)(A.size()) - 1;
    int ans;
    while (l < h - 1) {
      int m = (l + h) >> 1;
      if (A[m].first <= year)
        l = m;
      else if (A[m].first > year)
        h = m - 1;
    }
    if (A[h].first <= year)
      ans = h;
    else
      ans = l;
    int destroyed = A[(int)(A.size()) - 1].second - A[ans].second;
    int total = (r - l);
    return total - destroyed;
  }
  if (l >= R || r <= L) return 0;
  int leftChild = node << 1;
  int rightChild = leftChild | 1;
  int mid = (l + r) >> 1;
  int leftAns = query_ST_ok(L, R, year, leftChild, l, mid);
  int rightAns = query_ST_ok(L, R, year, rightChild, mid, r);
  return leftAns + rightAns;
}
pair<int, int> query_ST_ans_left(int L, int R, int K, int year, int node = 1,
                                 int l = 0, int r = lenBA) {
  if (l >= R || r <= L) return make_pair(0, -1);
  pair<int, int> la, ra;
  if (L <= l && r <= R) {
    vector<pair<int, int> > &A = ST[node];
    int low = 0, high = (int)(A.size()) - 1;
    int ans;
    while (low < high - 1) {
      int mid = (low + high) >> 1;
      if (A[mid].first <= year)
        low = mid;
      else if (A[mid].first > year)
        high = mid - 1;
    }
    if (A[high].first <= year)
      ans = high;
    else
      ans = low;
    int destroyed = A[(int)(A.size()) - 1].second - A[ans].second;
    int total = r - l;
    int n = total - destroyed;
    if (n < K) return make_pair(n, -1);
    if (l == r - 1) return make_pair(n, l);
    int lc = node << 1;
    int rc = lc | 1;
    int mid = (l + r) >> 1;
    la = query_ST_ans_left(L, R, K, year, lc, l, mid);
    if (la.second != -1) return la;
    return query_ST_ans_left(L, R, K - la.first, year, rc, mid, r);
  }
  int lc = node << 1;
  int rc = lc | 1;
  int mid = (l + r) >> 1;
  la = query_ST_ans_left(L, R, K, year, lc, l, mid);
  if (la.second != -1) return la;
  ra = query_ST_ans_left(L, R, K - la.first, year, rc, mid, r);
  if (ra.second != -1) return ra;
  return make_pair(la.first + ra.first, -1);
}
pair<int, int> query_ST_ans_right(int L, int R, int K, int year, int node = 1,
                                  int l = 0, int r = lenBA) {
  if (l >= R || r <= L) return make_pair(0, -1);
  pair<int, int> la, ra;
  if (L <= l && r <= R) {
    vector<pair<int, int> > &A = ST[node];
    int low = 0, high = (int)(A.size()) - 1;
    int ans;
    while (low < high - 1) {
      int mid = (low + high) >> 1;
      if (A[mid].first <= year)
        low = mid;
      else if (A[mid].first > year)
        high = mid - 1;
    }
    if (A[high].first <= year)
      ans = high;
    else
      ans = low;
    int destroyed = A[(int)(A.size()) - 1].second - A[ans].second;
    int total = r - l;
    int n = total - destroyed;
    if (n < K) return make_pair(n, -1);
    if (l == r - 1) return make_pair(n, l);
    int lc = node << 1;
    int rc = lc | 1;
    int mid = (l + r) >> 1;
    ra = query_ST_ans_right(L, R, K, year, rc, mid, r);
    if (ra.second != -1) return ra;
    return query_ST_ans_right(L, R, K - ra.first, year, lc, l, mid);
  }
  int lc = node << 1;
  int rc = lc | 1;
  int mid = (l + r) >> 1;
  ra = query_ST_ans_right(L, R, K, year, rc, mid, r);
  if (ra.second != -1) return ra;
  la = query_ST_ans_right(L, R, K - ra.first, year, lc, l, mid);
  if (la.second != -1) return la;
  return make_pair(la.first + ra.first, -1);
}
int a, b, k, y;
int query_up_ans(int u, int p, int year, int &k) {
  pair<int, int> ret;
  if (u == DP[u][0]) return -1;
  u = DP[u][0];
  while (numChain[u] != numChain[p]) {
    ret = query_ST_ans_right(posInBaseArray[chainHead[numChain[u]]],
                             posInBaseArray[u] + 1, k, year);
    if (ret.second != -1) return ret.second;
    u = chainParent[numChain[u]];
    k -= ret.first;
  }
  ret = query_ST_ans_right(posInBaseArray[p] + (p == b ? 1 : 0),
                           posInBaseArray[u] + 1, k, year);
  if (ret.second != -1) return ret.second;
  k -= ret.first;
  return -1;
}
int query_down_ans(int p, int v, int year, int &k) {
  pair<int, int> ret;
  if (v == DP[v][0]) return -1;
  v = DP[v][0];
  stack<pair<int, int> > Q;
  while (numChain[v] != numChain[p]) {
    Q.push(make_pair(posInBaseArray[chainHead[numChain[v]]],
                     posInBaseArray[v] + 1));
    v = chainParent[numChain[v]];
  }
  Q.push(make_pair(posInBaseArray[p] + 1, posInBaseArray[v] + 1));
  while (!Q.empty()) {
    int l = Q.top().first, r = Q.top().second;
    Q.pop();
    ret = query_ST_ans_left(l, r, k, year);
    if (ret.second != -1) return ret.second;
    k -= ret.first;
  }
  return -1;
}
int lca(int a, int b) {
  if (level[a] > level[b]) swap(a, b);
  int d = level[b] - level[a];
  for (int i = 0; (1 << i) <= d; i++)
    if (d & (1 << i)) b = DP[b][i];
  if (a == b) return a;
  int msb = 0;
  for (int i = 0; DP[a][i] != DP[b][i]; i++) msb = i;
  for (int i = msb; i >= 0; i--)
    if (DP[a][i] != DP[b][i]) {
      a = DP[a][i];
      b = DP[b][i];
    }
  return DP[a][0];
}
void processTree() {
  memset(visited, 0, sizeof(visited));
  level[root] = 0;
  dfs(root);
  memset(visited, 0, sizeof(visited));
  chainNo = 0;
  lenBA = 0;
  chainHead[chainNo] = root;
  chainParent[chainNo] = root;
  HLD(root);
  build_ST();
  for (int i = 1; i < LOGN; i++)
    for (int j = 0; j < n; j++) DP[j][i] = DP[DP[j][i - 1]][i - 1];
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    if (v == 0) {
      root = i;
      DP[root][0] = root;
    } else {
      tree[v - 1].push_back(i);
      tree[i].push_back(v - 1);
      DP[i][0] = v - 1;
    }
  }
  processTree();
  scanf("%d", &m);
  for (int year = 1; year <= m; year++) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int c;
      scanf("%d", &c);
      c--;
      update_ST(posInBaseArray[c], 1, year);
    } else {
      scanf("%d %d %d %d", &a, &b, &k, &y);
      a--;
      b--;
      int LCA = lca(a, b);
      if (LCA == a) {
        int ans = query_down_ans(a, b, y, k);
        if (ans == -1)
          printf("%d\n", ans);
        else
          printf("%d\n", baseArray[ans] + 1);
        continue;
      }
      if (LCA == b) {
        int ans = query_up_ans(a, b, y, k);
        if (ans == -1)
          printf("%d\n", ans);
        else
          printf("%d\n", baseArray[ans] + 1);
        continue;
      }
      int up = query_up_ans(a, LCA, y, k);
      if (up != -1) {
        printf("%d\n", baseArray[up] + 1);
        continue;
      }
      int down = query_down_ans(LCA, b, y, k);
      if (down != -1) {
        printf("%d\n", baseArray[down] + 1);
        continue;
      }
      printf("%d\n", -1);
    }
  }
  return 0;
}
