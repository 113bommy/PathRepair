#include <bits/stdc++.h>
using namespace std;
struct kk {
  int n, a, b;
  kk() {}
  kk(int nn, int na, int nb) : n(nn), a(na), b(nb) {}
};
vector<kk> v[10001];
vector<int> la;
int n, m, id;
int bg, ed, sol, a, b;
int mid, seem[10001];
bool flag;
bool inter(int a, int b, int bg, int ed) {
  return (ed >= b and bg <= a) ? 1 : 0;
}
void dfs(int u, int a, int b) {
  seem[u] = id;
  for (vector<kk>::iterator i = v[u].begin(); i < v[u].end(); i++)
    if (inter(a, b, i->a, i->b) and seem[i->n] != id) {
      dfs(i->n, a, b);
    }
}
bool find_(int mid) {
  for (int i = 0; i < la.size(); i++) {
    id++;
    dfs(1, la[i], la[i] + mid - 1);
    if (seem[n] == id) return 1;
  }
  return 0;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d %d", &a, &b, &bg, &ed);
    v[a].push_back(kk(b, bg, ed));
    v[b].push_back(kk(a, bg, ed));
    la.push_back(bg);
  }
  sort(la.begin(), la.end());
  la.resize(unique(la.begin(), la.end()) - la.begin());
  sol = -1;
  int mid;
  bg = 0, ed = 1e6;
  while (bg < ed) {
    mid = (bg + ed + 1) >> 1;
    (find_(mid)) ? bg = mid : ed = mid - 1;
    flag = false;
  }
  if (bg)
    printf("%d\n", bg);
  else
    printf("Nice work, Dima!\n");
}
