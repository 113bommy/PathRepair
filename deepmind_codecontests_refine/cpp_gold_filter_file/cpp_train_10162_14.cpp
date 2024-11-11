#include <bits/stdc++.h>
using namespace std;
int n, m, s[30 + 1], f[100010], flag[100010], k, la[100010], ff[100010 * 2];
struct node {
  int a, b, c;
} e[100010 * 2];
void add(int a, int b, int c) {
  e[++k] = (node){a, b, c};
  ff[k] = la[a];
  la[a] = k;
  e[++k] = (node){b, a, c};
  ff[k] = la[b];
  la[b] = k;
}
class linear_basis {
 public:
  void insert(int num) {
    for (int i = 30; i >= 0; i--)
      if (num >> i) {
        if (!s[i]) {
          s[i] = num;
          return;
        }
        num ^= s[i];
      }
  }
  int qry(int num) {
    int res = num;
    for (int i = 30; i >= 0; i--) res = min(res, res ^ s[i]);
    return res;
  }
} S;
void dfs(int x, int fa) {
  flag[x] = 1;
  for (int a = la[x]; a; a = ff[a]) {
    if (e[a].b == fa) continue;
    if (flag[e[a].b])
      S.insert(f[x] ^ f[e[a].b] ^ e[a].c);
    else
      f[e[a].b] = f[x] ^ e[a].c, dfs(e[a].b, x);
  }
}
int main() {
  int a, b, c;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) scanf("%d%d%d", &a, &b, &c), add(a, b, c);
  dfs(1, 0);
  printf("%d\n", S.qry(f[n]));
  return 0;
}
