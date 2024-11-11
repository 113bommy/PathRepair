#include <bits/stdc++.h>
using namespace std;
int cond = 1;
vector<int> v[101013];
int c[101013], ret;
int nwd(int a, int b) {
  if (b < 0) return nwd(a, -b);
  return a ? nwd(b % a, a) : b;
}
void dfs(int x) {
  for (__typeof((v[x]).begin()) i = ((v[x]).begin()); i != (v[x]).end(); ++i)
    if (!c[*i]) {
      c[*i] = c[x] + 1;
      dfs(*i);
    } else
      ret = nwd(ret, c[x] + 1 - c[*i]);
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  while (m--) {
    int a, b;
    scanf("%d %d", &a, &b);
    v[a].push_back(b);
  }
  c[1] = 1;
  dfs(1);
  printf("%d\n", ret);
  int x = 0;
  for (__typeof(1) i = (1); i <= (n); ++i)
    if (c[i] % ret == 1 % ret) x++;
  printf("%d\n", x);
  for (__typeof(1) i = (1); i <= (n); ++i)
    if (c[i] % ret == 1 % ret && c[i]) printf("%d ", i);
  puts("");
  return 0;
}
