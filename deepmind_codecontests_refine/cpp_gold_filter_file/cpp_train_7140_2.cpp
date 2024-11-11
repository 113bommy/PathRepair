#include <bits/stdc++.h>
using LL = long long int;
using namespace std;
const int NN = 500000;
const int MM = (1 << 20);
int n;
int ch[NN];
int CB[NN];
int ans[NN];
bool visited[NN] = {};
vector<int> sorted;
struct Node {
  int st, ed;
  pair<int, int> mx;
};
Node tree[MM];
pair<int, int> getMax(int st, int ed, int node) {
  Node& nd = tree[node];
  if (nd.st > ed || nd.ed < st) return make_pair(-1, -1);
  if (st <= nd.st && nd.ed <= ed) return nd.mx;
  return max(getMax(st, ed, node * 2), getMax(st, ed, node * 2 + 1));
}
void visit(int x, int node) {
  Node& nd = tree[node];
  if (x < nd.st || nd.ed < x) return;
  if (nd.st == nd.ed) {
    assert(nd.st == x);
    nd.mx = make_pair(-1, x);
    return;
  }
  visit(x, node * 2);
  visit(x, node * 2 + 1);
  nd.mx = max(tree[node * 2].mx, tree[node * 2 + 1].mx);
}
void buildTree(int node, int st, int ed) {
  Node& nd = tree[node];
  nd.st = st;
  nd.ed = ed;
  if (st == ed) {
    nd.mx = make_pair(CB[st], st);
    return;
  }
  int m = (st + ed) / 2;
  buildTree(node * 2, st, m);
  buildTree(node * 2 + 1, m + 1, ed);
  nd.mx = max(tree[node * 2].mx, tree[node * 2 + 1].mx);
}
void dfs(int cur) {
  visit(cur, 1);
  visited[cur] = true;
  if (CB[cur] < n && !visited[CB[cur]]) {
    dfs(CB[cur]);
  }
  while (ch[cur] > 0) {
    auto next = getMax(0, ch[cur] - 1, 1);
    if (next.first < 0 || next.second < 0 || next.first < cur) break;
    assert(!visited[next.second]);
    dfs(next.second);
  }
  sorted.push_back(cur);
}
int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    CB[i] = n;
  }
  for (int i = 0; i < n; ++i) {
    cin >> ch[i];
    ch[i]--;
    if (ch[i] >= 0) {
      CB[ch[i]] = i;
    } else {
      ch[i] = n;
    }
  }
  buildTree(1, 0, n - 1);
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      dfs(i);
    }
  }
  assert(sorted.size() == n);
  for (int i = 0; i < n; ++i) {
    ans[sorted[i]] = i + 1;
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " \n"[i == n - 1];
  }
}
