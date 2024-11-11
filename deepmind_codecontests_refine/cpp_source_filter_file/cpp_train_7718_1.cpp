#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, m, deg[N];
bool ins[N], vis[N];
vector<int> G[N], H[N];
void tarjan(int k1) {
  vis[k1] = 1, ins[k1] = 1;
  for (auto j : G[k1]) {
    if (!ins[j]) H[k1].push_back(j), ++deg[j];
    if (!vis[j]) tarjan(j);
  }
  ins[k1] = 0;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= (m); ++i) {
    int k1, k2;
    scanf("%d%d", &k1, &k2);
    G[k1].push_back(k2);
  }
  for (int i = (1); i <= (n); ++i)
    if (!vis[i]) tarjan(i);
  queue<int> q;
  for (int i = (1); i <= (n); ++i)
    if (!deg[i]) q.push(i);
  while (((int)(q).size()) > 1) {
    int k1 = q.front();
    q.pop();
    int k2 = q.front();
    q.pop();
    printf("? %d %d\n", k1, k2);
    fflush(stdout);
    int k3;
    scanf("%d", &k3);
    if (k3) swap(k1, k2);
    q.push(k2);
    for (auto j : H[k1])
      if (!--deg[j]) q.push(j);
  }
  printf("%d\n", q.front());
  return 0;
}
