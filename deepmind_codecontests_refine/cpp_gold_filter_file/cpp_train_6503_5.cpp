#include <bits/stdc++.h>
using namespace std;
struct edge {
  int u;
  int v;
  int l;
};
int n;
edge myedge[100001];
int subtree[100001];
long long prob[100001];
vector<int> node[100001];
int dfs(int now, int parent) {
  int res = 0;
  for (int i = 0; i < node[now].size(); i++) {
    int v = node[now][i];
    if (v == parent) continue;
    res += dfs(v, now);
  }
  subtree[now] = res + 1;
  return res + 1;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    scanf("%d%d%d", &myedge[i].u, &myedge[i].v, &myedge[i].l);
    node[myedge[i].u].push_back(myedge[i].v);
    node[myedge[i].v].push_back(myedge[i].u);
  }
  memset(subtree, 0, sizeof(subtree));
  dfs(1, 0);
  long long sum = 0;
  for (int i = 1; i < n; i++) {
    long long temp = min(subtree[myedge[i].u], subtree[myedge[i].v]);
    prob[i] = temp * (n - temp) * 6;
    sum += prob[i] * myedge[i].l;
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int b, w;
    cin >> b >> w;
    sum = sum - prob[b] * (myedge[b].l - w);
    myedge[b].l = w;
    cout << setprecision(25) << (sum * 1.0 / (1.0 * n * (n - 1))) << endl;
  }
  return 0;
}
