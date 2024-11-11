#include <bits/stdc++.h>
using namespace std;
int n, lmax = 0, longest_path[100010], center;
char color[100010];
vector<int> a[100010];
void find_disted(int v, int l, int &disted, int par, int &res) {
  int i, j;
  if (l >= lmax) {
    lmax = l;
    disted = v;
  }
  for (i = 0; i < a[v].size(); i++) {
    if (a[v][i] != par && !color[a[v][i]])
      find_disted(a[v][i], l + 1, disted, v, res);
  }
  if (l == lmax / 2) res = v;
}
void color_subtree(int root, char let) {
  lmax = 0;
  int distedA, distedB, res;
  find_disted(root, 0, distedA, -1, res);
  find_disted(distedA, 0, distedB, -1, res);
  color[res] = let;
  for (int i = 0; i < a[res].size(); i++) {
    if (!color[a[res][i]]) color_subtree(a[res][i], let + 1);
  }
}
int main() {
  int i, p, q, distedA;
  cin >> n;
  for (i = 0; i < n - 1; i++) {
    cin >> p >> q;
    a[p - 1].push_back(q - 1);
    a[q - 1].push_back(p - 1);
  }
  color_subtree(0, 'A');
  for (i = 0; i < n; i++) {
    cout << color[i] << ' ';
  }
}
