#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = 0;
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
  return x * f;
}
const int maxn = 10010;
vector<pair<int, int> > g, g1;
int a[maxn], b[maxn], fa[maxn], fb[maxn];
int n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) a[i] = read();
  for (int i = 1; i <= n; ++i) b[i] = read();
  for (int i = 1; i <= n; ++i) {
    int k = i;
    for (int j = i + 1; j <= n; ++j) k = a[j] > a[k] ? j : k;
    if (k != i)
      g.push_back(make_pair(i, k)), g.push_back(make_pair(k, i)),
          g.push_back(make_pair(i, k)), swap(a[i], a[k]);
    for (int j = 30; j >= 0; --j)
      if ((a[i] & (1 << j))) {
        fa[i] = 1 << j;
        break;
      }
    for (int j = 1; j <= n; ++j)
      if (i != j && (a[j] & fa[i])) g.push_back(make_pair(j, i)), a[j] ^= a[i];
  }
  for (int i = 1; i <= n; ++i) {
    int k = i;
    for (int j = i + 1; j <= n; ++j) k = b[j] > b[k] ? j : k;
    if (k != i)
      g1.push_back(make_pair(i, k)), g1.push_back(make_pair(k, i)),
          g1.push_back(make_pair(i, k)), swap(b[i], b[k]);
    for (int j = 30; j >= 0; --j)
      if ((b[i] & (1 << j))) {
        fb[i] = 1 << j;
        break;
      }
    for (int j = 1; j <= n; ++j)
      if (i != j && (b[j] & fb[i])) g1.push_back(make_pair(j, i)), b[j] ^= b[i];
  }
  for (int i = 1; i <= n; ++i)
    if (a[i] != b[i]) {
      if (fa[i] < fb[i])
        return puts("-1"), 0;
      else if (fa[i] > fb[i]) {
        g.push_back(make_pair(i, i));
        fa[i] = 0;
        a[i] = 0;
        for (int j = i + 1; j <= n; ++j) {
          if (!a[j]) break;
          g.push_back(make_pair(j - 1, j)), g.push_back(make_pair(j, j - 1)),
              g.push_back(make_pair(j - 1, j));
          swap(a[j], a[j - 1]);
          swap(fa[j], fa[j - 1]);
        }
        i--;
      } else {
        for (int j = i + 1; j <= n; ++j) {
          if (!a[j]) break;
          if (fa[j] & b[i]) g.push_back(make_pair(i, j)), a[i] ^= a[j];
        }
        if (a[i] != b[i]) return puts("-1"), 0;
      }
    }
  reverse(g1.begin(), g1.end());
  printf("%d\n", g.size() + g1.size());
  for (int i = 0; i < g.size(); ++i) printf("%d %d\n", g[i].first, g[i].second);
  for (int i = 0; i < g1.size(); ++i)
    printf("%d %d\n", g1[i].first, g[i].second);
}
