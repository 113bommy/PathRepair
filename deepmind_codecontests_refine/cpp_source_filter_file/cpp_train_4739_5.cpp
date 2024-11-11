#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
int n, globalMax = 0;
vector<vector<pii>> tree;
vector<int> used;
map<pii, int> m;
void LargestPath(int v, int path) {
  used[v] = 1;
  int leaf = 1;
  for (auto nvw : tree[v]) {
    int nv = nvw.first;
    int w = nvw.second;
    if (used[nv] == 0) {
      LargestPath(nv, path + w);
      leaf = 0;
    }
  }
  if (leaf == 1) {
    globalMax = max(globalMax, path);
  }
}
int main() {
  cin >> n;
  tree.resize(n, vector<pii>());
  used.resize(n, 0);
  int a, b, c, sum = 0;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b >> c;
    tree[a - 1].push_back(make_pair(b - 1, c));
    tree[b - 1].push_back(make_pair(a - 1, c));
    sum += c;
  }
  LargestPath(0, 0);
  cout << sum * 2 - globalMax;
  return 0;
}
