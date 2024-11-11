#include <bits/stdc++.h>
using namespace std;
const int MAX = 5005;
vector<int> llist[MAX];
int dpA[MAX], dpB[MAX];
int n, a, b, c, d, ofA, ofB, ofC, ofD, p[MAX], leaf[MAX];
void dfs(int u, int v) {
  p[u] = v;
  for (int i = 0; i < llist[u].size(); ++i) {
    int t = llist[u][i];
    if (t == v) continue;
    dfs(t, u);
    leaf[u] += leaf[t];
  }
  if (llist[u].size() == 1) leaf[u] = 1;
}
int trace(int u) {
  if (p[u] == 1) return u;
  return trace(p[u]);
}
int main() {
  int x;
  cin >> n >> a >> b >> c >> d;
  for (int i = 2; i <= n; ++i) {
    cin >> x;
    llist[x].push_back(i);
    llist[i].push_back(x);
  }
  dfs(1, 0);
  ofA = trace(a);
  ofB = trace(b);
  ofC = trace(c);
  ofD = trace(d);
  if (leaf[1] % 2 == 1) {
    cout << "NO" << endl;
    return 0;
  }
  dpA[leaf[ofA]] = 1;
  dpB[leaf[ofC]] = 1;
  for (int i = 0; i < llist[1].size(); ++i) {
    int t = llist[1][i];
    if (t == ofA || t == ofB || t == ofC) continue;
    for (int j = leaf[1] - leaf[t]; j > 0; --j) {
      if (dpA[j] == 1) dpA[j + leaf[t]] = 1;
    }
  }
  for (int i = 0; i < llist[1].size(); ++i) {
    int t = llist[1][i];
    if (t == ofB || t == ofA || t == ofD) continue;
    for (int j = leaf[1] - leaf[t]; j > 0; --j) {
      if (dpA[j] == 1) dpA[j + leaf[t]] = 1;
    }
  }
  int upper = leaf[1] / 2 - 1;
  int lowerA = leaf[1] / 2 - 1 - leaf[ofA] - leaf[ofB];
  int lowerB = leaf[1] / 2 - 1 - leaf[ofC] - leaf[ofD];
  bool resultA = false, resultB = false;
  for (int i = lowerA; i <= upper; ++i) {
    if (i >= 0 && dpA[i]) resultA = true;
  }
  for (int i = lowerB; i <= upper; ++i) {
    if (i >= 0 && dpB[i]) resultB = true;
  }
  if (resultA && resultB)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
