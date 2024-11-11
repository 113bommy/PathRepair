#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> v[100001], w[100001];
bitset<100001> odw, fixedd;
void wczytaj() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i < n; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    v[a].push_back(b);
    v[b].push_back(a);
    w[a].push_back(c);
    w[b].push_back(c);
  }
}
int Odl = 0, d[100001], root, ilef = 0, ojciec[100001];
bool kek;
void find_root(int x = 1) {
  d[x] = 0;
  odw[x] = true;
  for (int i = 0; i < (int)v[x].size(); ++i)
    if (!odw[v[x][i]]) {
      find_root(v[x][i]);
      if (root) return;
      d[x] = max(d[x], d[v[x][i]] + w[x][i]);
      if (d[x] > Odl) {
        root = v[x][i];
        return;
      }
    }
}
void ustaw(int x) {
  while (x) {
    fixedd[x] = true;
    x = ojciec[x];
    ++ilef;
  }
}
bool dfs(int x) {
  odw[x] = true, d[x] = 0;
  for (int i = 0; i < (int)v[x].size(); ++i)
    if (!odw[v[x][i]]) {
      ojciec[v[x][i]] = x;
      if (!dfs(v[x][i])) return false;
      if (!fixedd[v[x][i]]) d[x] = max(d[x], d[v[x][i]] + w[x][i]);
      if (!kek && d[x] > Odl)
        ustaw(v[x][i]), kek = true;
      else if (kek && !fixedd[v[x][i]] && d[v[x][i]] + w[x][i] > Odl)
        return false;
    }
  return true && ilef <= k;
}
bool TRUE(int x) {
  Odl = x, root = 0, ilef = 0;
  odw = 0;
  find_root();
  odw = 0;
  kek = false;
  fixedd = 0;
  ojciec[root] = 0;
  return dfs(root);
}
int bsrch() {
  int pocz = 1, kon = 1000000000;
  while (pocz < kon) {
    int sr = (pocz + kon) >> 1;
    if (!TRUE(sr))
      pocz = sr + 1;
    else
      kon = sr;
  }
  return pocz;
}
int main() {
  wczytaj();
  printf("%d\n", bsrch());
  return 0;
}
