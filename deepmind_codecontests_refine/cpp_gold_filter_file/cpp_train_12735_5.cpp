#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> adj[100010], BIT[100010];
int raiz, ntripas, tamtripa[100010], nivel[100010], tripa[100010];
int are[100010][2];
int dfs(int u, int paiu) {
  int soma = 1;
  for (int i = 0; i < (int)adj[u].size(); i++)
    if (adj[u][i] != paiu) {
      nivel[adj[u][i]] = nivel[u] + 1;
      tripa[adj[u][i]] = tripa[u];
      soma += dfs(adj[u][i], u);
    }
  return soma;
}
void update(int t, int u, int x) {
  for (int i = u; i <= tamtripa[t]; i += i & -i) BIT[t][i] += x;
}
int query(int t, int u) {
  int res = 0;
  for (int i = u; i; i -= i & -i) res += BIT[t][i];
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) adj[i].clear();
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
    are[i][0] = a;
    are[i][1] = b;
  }
  raiz = 0;
  for (int i = 0; i < n; i++)
    if ((int)adj[i].size() > 2) {
      raiz = i;
      break;
    }
  nivel[raiz] = 0;
  tripa[raiz] = 0;
  ntripas = (int)adj[raiz].size();
  for (int i = 0; i < ntripas; i++) {
    nivel[adj[raiz][i]] = 1;
    tripa[adj[raiz][i]] = i;
    tamtripa[i] = dfs(adj[raiz][i], raiz);
    BIT[i].resize(tamtripa[i] + 2);
    for (int j = 0; j < tamtripa[i] + 2; j++) BIT[i][j] = 0;
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int type;
    scanf("%d", &type);
    if (type == 1 or type == 2) {
      int id;
      scanf("%d", &id);
      id--;
      int a = are[id][0], b = are[id][1];
      if (nivel[b] < nivel[a]) swap(a, b);
      update(tripa[b], nivel[b], (type == 1 ? -1 : +1));
      continue;
    }
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    b--;
    if (a != raiz and b != raiz and tripa[a] != tripa[b]) {
      int p1 = query(tripa[a], nivel[a]);
      int p2 = query(tripa[b], nivel[b]);
      if (p1 != 0 or p2 != 0)
        printf("-1\n");
      else
        printf("%d\n", nivel[a] + nivel[b]);
    } else {
      if (nivel[b] < nivel[a]) swap(a, b);
      int p = query(tripa[b], nivel[b]) -
              (a == raiz ? 0 : query(tripa[b], nivel[a]));
      printf("%d\n", p != 0 ? -1 : nivel[b] - nivel[a]);
    }
  }
  return 0;
}
