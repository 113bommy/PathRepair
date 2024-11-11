#include <bits/stdc++.h>
using namespace std;
int PAR[1000000 + 7], baseArray[1000000 + 7], chainInd[1000000 + 7],
    posInbase[1000000 + 7];
int chainHead[1000000 + 7], SUB_TREE[1000000 + 7], P[1000000 + 7][20],
    L[1000000 + 7], Fi[1000000 + 7], Se[1000000 + 7], ar[1000000 + 7];
int IND, CHAIN_NO;
vector<int> adj[1000000 + 7], cost[1000000 + 7], TOPO;
long long dist[1000000 + 7];
struct info {
  int prop, sum;
};
info tree[1000000 + 7];
void update_TREE(int node, int beg, int end, int i, int j, int x) {
  if (i > end || j < beg) return;
  if (beg >= i && end <= j) {
    tree[node].sum = tree[node].sum + ((end - beg + 1) * x);
    tree[node].prop = tree[node].prop + x;
    return;
  }
  int Left = node * 2;
  int Right = node * 2 + 1;
  int mid = (beg + end) / 2;
  update_TREE(Left, beg, mid, i, j, x);
  update_TREE(Right, mid + 1, end, i, j, x);
  tree[node].sum =
      tree[Left].sum + tree[Right].sum + (end - beg + 1) * tree[node].prop;
}
int query_TREE(int node, int beg, int end, int i, int j, int carry) {
  if (i > end || j < beg) return 0;
  if (beg >= i && end <= j) return tree[node].sum + (end - beg + 1) * carry;
  int Left = node * 2;
  int Right = node * 2 + 1;
  int mid = (beg + end) / 2;
  int p1 = query_TREE(Left, beg, mid, i, j, carry + tree[node].prop);
  int p2 = query_TREE(Right, mid + 1, end, i, j, carry + tree[node].prop);
  return p1 + p2;
}
int query_UP(int u, int v) {
  int uchain, vchain = chainInd[v];
  int ans = 0;
  while (1) {
    uchain = chainInd[u];
    if (uchain == vchain) {
      ans += (query_TREE(1, 1, IND, posInbase[v], posInbase[u], 0));
      break;
    }
    ans += (query_TREE(1, 1, IND, posInbase[chainHead[chainInd[u]]],
                       posInbase[u], 0));
    u = chainHead[uchain];
    u = PAR[u];
  }
  return ans;
}
void update_UP(int u, int v) {
  int uchain, vchain = chainInd[v];
  while (1) {
    uchain = chainInd[u];
    if (uchain == vchain) {
      update_TREE(1, 1, IND, posInbase[v], posInbase[u], 1);
      break;
    }
    update_TREE(1, 1, IND, posInbase[chainHead[chainInd[u]]], posInbase[u], 1);
    u = chainHead[uchain];
    u = PAR[u];
  }
}
void HLD(int curr, int parent) {
  int siz, now, nowInd, nowCost, i, j;
  if (chainHead[CHAIN_NO] == -1) {
    chainHead[CHAIN_NO] = curr;
  }
  chainInd[curr] = CHAIN_NO;
  posInbase[curr] = IND + 1;
  baseArray[IND + 1] = ar[curr];
  IND++;
  siz = adj[curr].size();
  now = 0;
  nowInd = -1;
  for (i = 0; i < siz; i++) {
    j = adj[curr][i];
    if (SUB_TREE[j] > now && j != parent) {
      now = SUB_TREE[j];
      nowInd = j;
    }
  }
  if (now) {
    HLD(nowInd, curr);
  }
  for (i = 0; i < siz; i++) {
    j = adj[curr][i];
    if (j != nowInd && j != parent) {
      CHAIN_NO++;
      HLD(j, curr);
    }
  }
}
void dfs(int curr, int parent) {
  int i, j, k, siz;
  siz = adj[curr].size();
  PAR[curr] = parent;
  SUB_TREE[curr] = 1;
  for (i = 0; i < siz; i++) {
    j = adj[curr][i];
    if (j != parent) {
      L[j] = L[curr] + 1;
      dist[j] = dist[curr] + cost[curr][i];
      dfs(j, curr);
      SUB_TREE[curr] += SUB_TREE[j];
    }
  }
  TOPO.push_back(curr);
}
void process(int N) {
  int i, j;
  for (i = 0; i < N; i++) {
    for (j = 0; 1 << j < N; j++) {
      P[i][j] = -1;
    }
  }
  for (i = 0; i < N; i++) {
    P[i][0] = PAR[i];
  }
  for (j = 1; 1 << j < N; j++) {
    for (i = 0; i < N; i++) {
      if (P[i][j - 1] != -1) {
        P[i][j] = P[P[i][j - 1]][j - 1];
      }
    }
  }
}
int query_LCA(int N, int p, int q) {
  int tmp, log, i, curr_parent;
  if (L[p] < L[q]) {
    tmp = p, p = q, q = tmp;
  }
  for (log = 1; 1 << log <= L[p]; log++)
    ;
  log--;
  for (i = log; i >= 0; i--) {
    if (L[p] - (1 << i) >= L[q]) {
      p = P[p][i];
    }
  }
  if (p == q)
    curr_parent = p;
  else {
    for (i = log; i >= 0; i--) {
      if (P[p][i] != -1 && P[p][i] != P[q][i]) {
        p = P[p][i], q = P[q][i];
      }
    }
    curr_parent = PAR[p];
  }
  return curr_parent;
}
int query_MAIN(int u, int v) { return query_UP(v, u); }
void update_MAIN(int i, int j) { update_UP(j, i); }
int jumptree(int curr, int jump) {
  int i, log;
  if (jump == 0) return curr;
  for (log = 1; 1 << log <= jump; log++)
    ;
  log--;
  for (i = log; i >= 0; i--) {
    if ((1 << i) > jump) continue;
    curr = P[curr][i];
    jump -= (1 << i);
  }
  return curr;
}
int XX;
int BS(int low, int high) {
  if (low == high) return low;
  if (low == high - 1) {
    if (dist[XX] - dist[jumptree(XX, high)] <= ar[XX]) return high;
    return low;
  }
  int mid = (low + high) / 2;
  if (dist[XX] - dist[jumptree(XX, mid)] <= ar[XX]) return BS(mid, high);
  return BS(low, mid);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int i, j, k, l, n, m, ans, ind, sum, tot, root, curr, siz, jump, node, q, now;
  for (i = 0; i < 1000000; i++) {
    tree[i].prop = 0;
    tree[i].sum = 0;
  }
  cin >> n;
  for (i = 0; i < n; i++) cin >> ar[i];
  for (i = 0; i < n - 1; i++) {
    cin >> j >> k;
    j--;
    adj[j].push_back(i + 1);
    adj[i + 1].push_back(j);
    cost[j].push_back(k);
    cost[i + 1].push_back(k);
    Fi[i] = i + 1;
    Se[i] = j;
  }
  root = 0;
  IND = 0;
  L[root] = 0;
  dfs(root, -1);
  process(n);
  memset(chainHead, -1, sizeof(chainHead));
  for (i = 0; i < n - 1; i++) {
    if (PAR[Fi[i]] == Se[i]) swap(Fi[i], Se[i]);
  }
  CHAIN_NO = 0;
  HLD(root, -1);
  for (i = 0; i < n; i++) {
    curr = TOPO[i];
    XX = curr;
    int now_ = jumptree(curr, BS(0, L[curr]));
    update_MAIN(now_, curr);
  }
  for (i = 0; i < n; i++) {
    ans = query_MAIN(i, i);
    cout << ans - 1 << " ";
  }
  cout << endl;
}
