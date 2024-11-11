#include <bits/stdc++.h>
using namespace std;
struct A {
  int id, key;
} node[600000];
int n, m, p, k, minn, sum;
int flow[600000];
bool mark[600000], book[600000], inque[600000];
vector<int> way[600000], id[600000], ans;
queue<int> que;
bool cmp(A x, A y) { return x.key < y.key; }
int main() {
  int a, b;
  cin >> n >> m >> p;
  for (int i = 1; i <= m; i++) {
    cin >> a;
    way[0].push_back(a);
  }
  for (int i = 1; i < n; i++) {
    cin >> a >> b;
    way[a].push_back(b);
    id[a].push_back(i);
    way[b].push_back(a);
    id[b].push_back(i);
  }
  que.push(0);
  book[0] = true;
  flow[0] = p + 1;
  while (!que.empty()) {
    k = que.front();
    que.pop();
    for (int i = 0; i < way[k].size(); i++) {
      if (!book[way[k][i]]) {
        flow[way[k][i]] = flow[k] - 1;
        book[way[k][i]] = true;
        que.push(way[k][i]);
      }
    }
  }
  minn = p + 1;
  for (int i = 1; i <= n; i++) {
    node[i].id = i;
    node[i].key = flow[i];
  }
  sort(1 + node, 1 + n + node, cmp);
  for (int i = 1; i <= n; i++) que.push(node[i].id);
  while (!que.empty()) {
    k = que.front();
    que.pop();
    mark[k] = true;
    sum = 0;
    for (int i = 0; i < way[k].size(); i++) {
      if (!mark[way[k][i]]) {
        if (flow[way[k][i]] == flow[k]) {
          ans.push_back(id[k][i]);
        } else if (flow[way[k][i]] == flow[k] + 1) {
          sum++;
        }
      }
    }
    for (int i = 0; i < way[k].size(); i++) {
      if (flow[way[k][i]] == flow[k] + 1 && sum != 1) {
        sum--;
        ans.push_back(way[k][i]);
      }
    }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  return 0;
}
