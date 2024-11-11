#include <bits/stdc++.h>
using namespace std;
vector<int> w[200020];
int a, b, ar[200020], bas[200020], son[200020], tmp, tek[200020], ger[200020],
    ters[200020], segment[200020 * 5][2];
void dfs(int n, int der) {
  bas[n] = ++tmp;
  tek[n] = der % 2;
  for (int i = 0; i < w[n].size(); i++)
    if (!bas[w[n][i]]) dfs(w[n][i], der + 1);
  son[n] = tmp;
}
bool cmp(int a, int b) { return bas[a] < bas[b]; }
void update(int k, int b, int s, int x, int y, int m, int e) {
  if (x <= b && s <= y) {
    segment[k][e] += m;
    return;
  }
  if (x > s || b > y) return;
  update(2 * k, b, (b + s) / 2, x, y, m, e);
  update(2 * k + 1, (b + s) / 2 + 1, s, x, y, m, e);
}
int find(int k, int b, int s, int x) {
  int top = (segment[k][0] - segment[k][1]) * (tek[ger[x]] ? -1 : 1);
  if (b == s && s == x) return ar[ger[x]] + top;
  if (b > x || s < x) return 0;
  if (x <= (b + s) / 2)
    return find(2 * k, b, (b + s) / 2, x) + top;
  else
    return find(2 * k + 1, (b + s) / 2 + 1, s, x) + top;
}
int main() {
  scanf("%d %d", &a, &b);
  for (int i = 1; i <= a; i++) scanf("%d", &ar[i]);
  for (int i = 1; i < a; i++) {
    int j, k;
    scanf("%d %d", &j, &k);
    w[j].push_back(k);
    w[k].push_back(j);
  }
  dfs(1, 1);
  for (int i = 1; i <= a; i++) ger[i] = i;
  sort(ger + 1, ger + 1 + a, cmp);
  for (int i = 1; i <= a; i++) ters[ger[i]] = i;
  for (int i = 1; i <= b; i++) {
    int t, e, r;
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d %d", &e, &r);
      update(1, 1, a, bas[e], son[e], r, tek[e] % 2);
    }
    if (t == 2) {
      scanf("%d", &e);
      printf("%d\n", find(1, 1, a, ters[e]));
    }
  }
  return 0;
}
