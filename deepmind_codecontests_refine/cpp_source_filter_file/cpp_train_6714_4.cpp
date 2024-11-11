#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100000;
const int MAX_L = 800000;
char s[MAX_L + 4];
int ps[MAX_L], ds[MAX_L], cns[MAX_L], cs[MAX_N][26];
list<int> las[MAX_L], lbs[MAX_L];
pair<int, int> rs[MAX_N];
int set_word(char *cpt, int &n) {
  int u = 0;
  while (*cpt) {
    int c = *cpt - 'a';
    if (cs[u][c] < 0) {
      cns[u]++;
      int v = cs[u][c] = n++;
      ps[v] = u;
      ds[v] = ds[u] + 1;
    }
    u = cs[u][c];
    cpt++;
  }
  return u;
}
int main() {
  int n;
  scanf("%d", &n);
  memset(ps, -1, sizeof(ps));
  memset(cs, -1, sizeof(cs));
  int m = 1;
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    int u = set_word(s, m);
    las[u].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    int u = set_word(s, m);
    lbs[u].push_back(i);
  }
  queue<int> q;
  for (int u = 0; u < m; u++)
    if (cns[u] == 0) q.push(u);
  int k = 0;
  long long sum = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    while (!las[u].empty() && !lbs[u].empty()) {
      sum += ds[u];
      int a = las[u].front();
      las[u].pop_front();
      int b = lbs[u].front();
      lbs[u].pop_front();
      rs[k++] = pair<int, int>(a, b);
    }
    int up = ps[u];
    if (up >= 0) {
      las[up].splice(las[up].end(), las[u]);
      lbs[up].splice(lbs[up].end(), lbs[u]);
      if (--cns[up] == 0) q.push(up);
    }
  }
  printf("%lld\n", sum);
  for (int i = 0; i < n; i++)
    printf("%d %d\n", rs[i].first + 1, rs[i].second + 1);
  return 0;
}
