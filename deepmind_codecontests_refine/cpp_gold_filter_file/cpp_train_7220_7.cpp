#include <bits/stdc++.h>
using namespace std;
int n, i = 1, a, b, ij[3001], ji[3001], wynn = 10000;
vector<vector<int> > tab(3001);
vector<vector<int> > e(3001);
inline int min(int a, int b) {
  if (a <= b) return a;
  return b;
}
inline int max(int a, int b) {
  if (a >= b) return a;
  return b;
}
int s[3001], s2[3001], check[3001], f[3001], is = 0, par[3001];
int proc_tree(int a, int n, int x) {
  int b, minn = 5000;
  for (int z = 0; z <= n; z++) ji[z] = ij[z];
  s[0] = a, is = 1, check[a] = 1;
  while (is > 0) {
    a = s[is - 1];
    if (ji[a] > 0 && (par[a] == tab[a][ji[a] - 1] || tab[a][ji[a] - 1] == x))
      ji[a]--;
    if (ji[a] > 0 && (par[a] == tab[a][ji[a] - 1] || tab[a][ji[a] - 1] == x))
      ji[a]--;
    if (ji[a] > 0) {
      b = s[is] = tab[a][ji[a] - 1], par[b] = a, check[b] = 1;
      s2[is] = e[a][ji[a] - 1];
      ji[a]--, is++;
    } else {
      f[par[a]] += f[a] + s2[is - 1];
      is--;
    }
  }
  for (int z = 0; z <= n; z++) ji[z] = ij[z];
  s[0] = a, is = 1;
  while (is > 0) {
    a = s[is - 1];
    if (ji[a] > 0 && (par[a] == tab[a][ji[a] - 1] || tab[a][ji[a] - 1] == x))
      ji[a]--;
    if (ji[a] > 0 && (par[a] == tab[a][ji[a] - 1] || tab[a][ji[a] - 1] == x))
      ji[a]--;
    if (ji[a] > 0) {
      b = s[is] = tab[a][ji[a] - 1], par[b] = a;
      if (e[a][ji[a] - 1] == 0)
        f[b] = f[a] + 1;
      else
        f[b] = f[a] - 1;
      ji[a]--, is++;
    } else
      is--;
  }
  for (int z = 1; z <= n; z++) {
    if (f[z] < minn && check[z] == 1) minn = f[z];
    f[z] = 0, check[z] = 0;
  }
  return minn;
}
void make_par() {
  int b;
  for (int z = 0; z <= n; z++) ji[z] = ij[z];
  s[0] = 1, is = 1;
  while (is > 0) {
    a = s[is - 1];
    if (ji[a] > 0 && par[a] == tab[a][ji[a] - 1]) ji[a]--;
    if (ji[a] > 0)
      b = s[is] = tab[a][ji[a] - 1], par[b] = a, ji[a]--, is++;
    else
      is--;
  }
}
int main() {
  scanf("%d", &n);
  while (i < n) {
    scanf("%d %d", &a, &b);
    tab[a].push_back(b), tab[b].push_back(a);
    e[a].push_back(0), e[b].push_back(1);
    ij[a]++, ij[b]++;
    i++;
  }
  make_par();
  for (i = 2; i <= n; i++)
    wynn = min(wynn, proc_tree(1, n, i) + proc_tree(i, n, par[i]));
  if (n == 1) wynn = 0;
  printf("%d\n", wynn);
  return 0;
}
