#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e6 + 100;
const int mod = (int)1e9 + 7;
int n, k, fa[maxn], tot[maxn], ans;
char s[maxn];
vector<int> v[maxn];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void join(int x, int y) {
  x = find(x);
  y = find(y);
  if (x != y) fa[x] = y, tot[y] += tot[x];
}
int get(int x) { return min(tot[find(x)], tot[find(x + k)]); }
int main() {
  scanf("%d%d%s", &n, &k, s + 1);
  for (int i = (1); i <= (k); ++i) {
    int x, c;
    scanf("%d", &c);
    while (c--) scanf("%d", &x), v[x].push_back(i);
  }
  for (int i = (1); i <= (2 * k + 1); ++i) fa[i] = i, tot[i] = (i <= k);
  tot[2 * k + 1] = mod;
  for (int i = (1); i <= (n); ++i) {
    if (v[i].size() == 1) {
      int tmp = v[i][0] + (s[i] == '0') * k;
      ans -= get(v[i][0]);
      join(tmp, 2 * k + 1);
      ans += get(v[i][0]);
    }
    if (v[i].size() == 2) {
      int x = v[i][0], y = v[i][1];
      if (s[i] == '1' && find(x) != find(y)) {
        ans -= (get(x) + get(y));
        join(x, y);
        join(x + k, y + k);
        ans += get(x);
      }
      if (s[i] == '0' && find(x) != find(y + k)) {
        ans -= (get(x) + get(y + k));
        join(x, y + k);
        join(x + k, y);
        ans += get(x);
      }
    }
    printf("%d\n", ans);
  }
}
