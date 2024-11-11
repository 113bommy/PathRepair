#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > H[500005];
int arr[30], L[500005], R[500005];
vector<int> st[500005];
char str[500005];
int n, m, tot;
void dfs(int p, int dep) {
  L[p] = ++tot;
  H[dep].push_back(make_pair(tot, H[dep].back().second ^ arr[str[p]]));
  for (int i = (0); i < (st[p].size()); i++) {
    int v = st[p][i];
    dfs(v, dep + 1);
  }
  R[p] = ++tot;
}
int main() {
  for (int i = (0); i < (28); i++) arr[i] = (1 << i);
  scanf("%d %d", &n, &m);
  for (int i = (1); i < (n + 1); i++) H[i].push_back(make_pair(0, 0));
  for (int i = (2); i < (n + 1); i++) {
    int x;
    scanf("%d", &x);
    st[x].push_back(i);
  }
  scanf("%s", str + 1);
  for (int i = (1); i < (n + 1); i++) str[i] -= 'a';
  dfs(1, 1);
  int v, h;
  for (int i = (1); i < (m + 1); i++) {
    scanf("%d %d", &v, &h);
    int l = lower_bound(H[h].begin(), H[h].end(), make_pair(L[v], -1)) -
            H[h].begin() - 1;
    int r = lower_bound(H[h].begin(), H[h].end(), make_pair(R[v], -1)) -
            H[h].begin() - 1;
    int t = H[h][r].second ^ H[h][l].second;
    int cnt = 0;
    for (int j = (0); j < (26); j++) {
      if (arr[j] & t) cnt++;
    }
    if (cnt >= 2)
      puts("No");
    else
      puts("YES");
  }
  return 0;
}
