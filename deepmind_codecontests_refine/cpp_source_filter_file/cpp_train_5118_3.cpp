#include <bits/stdc++.h>
using namespace std;
const int N = 223;
set<int> st[N];
int mp[N][N];
bool ok(set<int> &a, set<int> &b) {
  for (auto it : a) {
    if (b.find(it) == b.end()) return false;
  }
  return true;
}
int n, m;
int deg[N];
int main() {
  cin >> n >> m;
  for (int k = 0; k < n; k++) {
    for (int i = 1; i <= m; i++) st[i * 2 + 1].insert(i);
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
      int t;
      scanf("%d", &t);
      st[k * 2].insert(t);
      st[k * 2 + 1].erase(t);
    }
    mp[2 * k][2 * k + 1] = 1;
    deg[2 * k + 1]++;
    for (int i = 0; i < k * 2; i++) {
      if (ok(st[2 * k], st[i])) {
        mp[i][2 * k] = 1;
        deg[2 * k]++;
      }
      if (ok(st[i], st[2 * k])) {
        mp[2 * k][i] = 1;
        deg[i]++;
      }
      if (ok(st[2 * k + 1], st[i])) {
        mp[i][2 * k + 1] = 1;
        deg[2 * k + 1]++;
      }
      if (ok(st[i], st[2 * k + 1])) {
        mp[2 * k + 1][i] = 1;
        deg[i]++;
      }
    }
  }
  queue<int> que;
  int sum = 0;
  for (int i = 0; i < 2 * n; i++)
    if (deg[i] == 0) sum++, que.push(i);
  while (que.empty() == false) {
    int cur = que.front();
    que.pop();
    for (int v = 0; v < 2 * n; v++) {
      if (mp[cur][v] == 1) {
        if (--deg[v] == 0) {
          que.push(v);
          sum++;
        }
      }
    }
  }
  if (sum == 2 * n)
    puts("possible");
  else
    puts("impossible");
}
