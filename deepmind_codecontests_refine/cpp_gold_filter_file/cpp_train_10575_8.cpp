#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const int N = 300005, CL = 26;
typedef struct node {
  int sz;
  int pnt[CL];
  void ResetNode() { sz = 0, memset(pnt, 0, sizeof(pnt)); }
} Node;
class Trie {
 public:
  map<int, Node> M;
  vector<int> DN[N];
  Node ND[N + N];
  int tmproot[CL];
  void insert(int u, int v, char z) { ND[u].pnt[z - 'a'] = v; }
  int dfs(int root, int d) {
    DN[d].push_back(root);
    ND[root].sz = 1;
    for (int i = 0; i < CL; i++)
      if (ND[root].pnt[i]) ND[root].sz += dfs(ND[root].pnt[i], d + 1);
    return ND[root].sz;
  }
  void merge(int root1, int root2) {
    if (!root2 || root1 == root2) return;
    if (!M.count(root1)) M[root1] = ND[root1];
    for (int i = 0; i < CL; i++) {
      if (!ND[root2].pnt[i]) continue;
      ND[root1].sz -= ND[ND[root1].pnt[i]].sz;
      if (!ND[root1].pnt[i] ||
          (ND[ND[root1].pnt[i]].sz < ND[ND[root2].pnt[i]].sz)) {
        merge(ND[root2].pnt[i], ND[root1].pnt[i]);
        ND[root1].pnt[i] = ND[root2].pnt[i];
      } else
        merge(ND[root1].pnt[i], ND[root2].pnt[i]);
      ND[root1].sz += ND[ND[root1].pnt[i]].sz;
    }
  }
  void reversechange() {
    for (auto c : M) ND[c.first] = c.second;
  }
  pair<int, int> solve() {
    dfs(1, 0);
    int sum = 0, v, val;
    pair<int, int> MN = {0, 123456789};
    for (int i = 0; DN[i + 1].size() > 0; i++) {
      sum += DN[i].size();
      val = 0;
      for (auto p : DN[i]) {
        memset(tmproot, 0, sizeof(tmproot));
        M.clear();
        for (int k = 0; k < CL; k++)
          if ((v = ND[p].pnt[k]))
            for (int j = 0; j < CL; j++)
              if (ND[ND[v].pnt[j]].sz > ND[tmproot[j]].sz)
                tmproot[j] = ND[v].pnt[j];
        for (int k = 0; k < CL; k++)
          if ((v = ND[p].pnt[k]))
            for (int j = 0; j < CL; j++) merge(tmproot[j], ND[v].pnt[j]);
        for (int k = 0; k < CL; k++) val += ND[tmproot[k]].sz;
        reversechange();
      }
      if (MN.second > val + sum) MN.first = i + 1, MN.second = val + sum;
    }
    return MN;
  }
};
Trie T;
int main() {
  int n, u, v;
  scanf("%d", &n);
  char c;
  for (int i = 1; i < n; i++) scanf("%d %d %c", &u, &v, &c), T.insert(u, v, c);
  pair<int, int> OUT = T.solve();
  return 0 * printf("%d\n%d\n", OUT.second, OUT.first);
}
