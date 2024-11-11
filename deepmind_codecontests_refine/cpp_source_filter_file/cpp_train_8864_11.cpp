#include <bits/stdc++.h>
int mod = 1e9 + 7;
const int inf = 1e7;
using namespace std;
const int size = 1e6 + 10;
const int l2 = 20;
vector<int> v[size + 1];
int lca[size + 1][l2 + 1];
int find(int l, int r) {
  if (lca[l][l2] < r) return inf;
  int t = inf, p = 1;
  for (int i = l2; i > 0; i--) {
    if (lca[l][i] >= r)
      t = min(t, p + 1 << i);
    else {
      l = lca[l][i];
      p += 1 << i;
    }
  }
  if (lca[l][0] < r)
    return min(t, p + 1);
  else
    return min(t, p);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n, Q;
  cin >> n >> Q;
  for (int i = 1; i < n + 1; i++) {
    int l, r;
    cin >> l >> r;
    l++;
    r++;
    l *= 2;
    r *= 2;
    v[l].push_back(r);
  }
  int pos[size + 1];
  for (int i = 0; i < size + 1; i++) pos[i] = i;
  int m = -inf;
  for (int i = 1; i < size + 1; i++) {
    for (int j : v[i]) m = max(m, j);
    pos[i] = max(pos[i], m);
  }
  for (int i = 0; i < l2 + 1; i++) lca[size][i] = size;
  for (int i = size - 1; i > 0; i--) {
    lca[i][0] = pos[i];
    for (int j = 1; j < l2 + 1; j++) lca[i][j] = lca[lca[i][j - 1]][j - 1];
  }
  while (Q--) {
    int l, r;
    cin >> l >> r;
    l++;
    r++;
    l *= 2;
    r *= 2;
    int x = find(l, r);
    if (x >= inf)
      cout << "-1\n";
    else
      cout << x << "\n";
  }
}
