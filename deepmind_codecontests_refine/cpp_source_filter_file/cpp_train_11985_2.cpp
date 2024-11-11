#include <bits/stdc++.h>
using namespace std;
vector<int> Tree[300005];
vector<pair<int, long long> > Query[300005];
void dfsUpdate(int v, int parent, vector<long long>& height,
               vector<long long>& ans, long long prev, int h) {
  for (int i = 0; i < Query[v].size(); i++) {
    pair<int, long long> q = Query[v][i];
    long long value = q.second;
    int d = q.first;
    height[h] += value;
    if (h + d + 1 < height.size()) height[h + d + 1] -= value;
  }
  ans[v] = height[h] + prev;
  for (int i = 0; i < Tree[v].size(); i++) {
    int child = Tree[v][i];
    if (child != parent) {
      dfsUpdate(child, v, height, ans, ans[v], h + 1);
    }
  }
  for (int i = 0; i < Query[v].size(); i++) {
    pair<int, long long> q = Query[v][i];
    long long value = q.second;
    int d = q.first;
    height[h] -= value;
    if (h + d + 1 < height.size()) height[h + d + 1] += value;
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d", &u);
    scanf("%d", &v);
    Tree[u].push_back(v);
    Tree[v].push_back(u);
  }
  vector<long long> height(n + 1, 0);
  int q1;
  cin >> q1;
  for (int i = 0; i < q1; i++) {
    int v, d;
    long long x;
    scanf("%d", &v);
    scanf("%d", &d);
    scanf("%d", &x);
    Query[v].push_back({d, x});
  }
  vector<long long> ans(n + 1, 0);
  dfsUpdate(1, 0, height, ans, 0, 0);
  for (int i = 1; i <= n; i++) {
    printf("%d ", ans[i]);
  }
}
