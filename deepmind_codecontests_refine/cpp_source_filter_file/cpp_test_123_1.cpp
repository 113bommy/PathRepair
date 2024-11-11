#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
struct Node {
  vector<int> neighbors;
  bool vis = false;
  int begin;
  int end;
  int dep;
  int p;
  bool lf = true;
  bool r = false;
};
vector<int> dfsOrder;
void DFS(Node* graph, int s) {
  graph[s].vis = true;
  graph[s].begin = dfsOrder.size();
  dfsOrder.push_back(s);
  for (int i = 0; i < graph[s].neighbors.size(); i++) {
    int currNei = graph[s].neighbors[i];
    if (graph[currNei].vis) {
      continue;
    }
    graph[s].lf = false;
    graph[currNei].p = s;
    graph[currNei].dep = graph[s].dep + 1;
    DFS(graph, currNei);
  }
  graph[s].end = dfsOrder.size() - 1;
}
struct STNode {
  pair<int, int> mn;
  int l;
  int r;
  int ad;
  STNode() { ad = 0; }
};
struct SegmentTree {
  STNode* arr;
  int sz;
  SegmentTree(int sz_inp) {
    sz = 1 << ((int)log2(sz_inp) + 2);
    arr = new STNode[sz];
    initControl(1);
    for (int i = 0; i < sz_inp; i++) {
      arr[i + sz / 2].mn = {0, i};
    }
    for (int i = sz_inp + sz / 2; i < sz; i++) {
      arr[i].mn = {-inf, -inf};
    }
    initContent(1);
  }
  void updateNode(int x) { arr[x].mn = max(arr[left(x)].mn, arr[right(x)].mn); }
  void initContent(int x) {
    if (isLeaf(x)) {
      return;
    }
    initContent(left(x));
    initContent(right(x));
    updateNode(x);
  }
  void initControl(int x) {
    if (isLeaf(x)) {
      arr[x].l = x - sz / 2;
      arr[x].r = x - sz / 2;
      return;
    }
    initControl(left(x));
    initControl(right(x));
    arr[x].l = arr[left(x)].l;
    arr[x].r = arr[right(x)].r;
  }
  void doResp(int x) {
    if (arr[x].ad) {
      giveRespSet(left(x), arr[x].ad);
      giveRespSet(right(x), arr[x].ad);
      arr[x].ad = 0;
    }
  }
  void giveRespSet(int x, int newVal) {
    arr[x].mn.first += newVal;
    if (!isLeaf(x)) {
      arr[x].ad += newVal;
    }
  }
  void updateRangeSet(int l, int r, int newVal) {
    updateRangeSet(1, l, r, newVal);
  }
  void updateRangeSet(int x, int l, int r, int newVal) {
    if (arr[x].l > r || arr[x].r < l) {
      return;
    }
    if (arr[x].l >= l && arr[x].r <= r) {
      giveRespSet(x, newVal);
      return;
    }
    doResp(x);
    updateRangeSet(left(x), l, r, newVal);
    updateRangeSet(right(x), l, r, newVal);
    updateNode(x);
  }
  pair<int, int> queryRange(int l, int r) { return queryRange(1, l, r); }
  pair<int, int> queryRange(int x, int l, int r) {
    if (arr[x].l > r || arr[x].r < l) {
      return {-inf, -inf};
    }
    if (arr[x].l >= l && arr[x].r <= r) {
      return arr[x].mn;
    }
    doResp(x);
    return max(queryRange(left(x), l, r), queryRange(right(x), l, r));
  }
  int left(int x) { return 2 * x; }
  int right(int x) { return 2 * x + 1; }
  int parent(int x) { return x / 2; }
  bool isLeaf(int x) { return x >= sz / 2; }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    Node* graph = new Node[n];
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      graph[u].neighbors.push_back(v);
      graph[v].neighbors.push_back(u);
    }
    graph[0].dep = 0;
    graph[0].p = inf;
    DFS(graph, 0);
    SegmentTree st(n);
    for (int i = 0; i < n; i++) {
      st.updateRangeSet(i, i, graph[dfsOrder[i]].dep);
    }
    long long ans = -inf;
    long long nmunblocked = n;
    for (long long nmr = 1; nmr <= k; nmr++) {
      pair<int, int> nxt = st.queryRange(0, n - 1);
      int nxtdfs = nxt.second;
      int nxti = dfsOrder[nxtdfs];
      if (graph[nxti].r) {
        if (nmr - 1 <= n / 2) {
          long long r = min(n / 2, k);
          ans = r * (n - r);
        }
        break;
      }
      int curr = nxti;
      while (curr != inf) {
        if (graph[curr].r) break;
        graph[curr].r = true;
        nmunblocked--;
        st.updateRangeSet(graph[curr].begin, graph[curr].end, -1);
        curr = graph[curr].p;
      }
      long long currans = nmr * (n - nmr);
      long long b = min(n / 2, nmunblocked);
      currans -= b * (n - b);
      ans = max(ans, currans);
    }
    cout << ans << '\n';
  }
  cin >> t;
}
