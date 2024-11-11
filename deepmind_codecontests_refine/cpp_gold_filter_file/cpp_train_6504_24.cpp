#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e3 + 10;
int n, ans, t, p;
int edge[MAXN], rnum[MAXN], lnum[MAXN];
int pow(int a, int b) {
  if (!b)
    return 1;
  else
    return pow(a, b - 1) * a;
}
void dfs(int source) {
  if (source > t) return;
  int a = 2 * source, b = a + 1;
  dfs(a), dfs(b);
  rnum[source] = max(rnum[b], lnum[b]) + edge[b];
  lnum[source] = max(rnum[a], lnum[a]) + edge[a];
}
void make(int source) {
  if (source >= t) return;
  int a = 2 * source, b = a + 1, c, r = rnum[source], l = lnum[source];
  c = (r < l ? l - r : r - l);
  ans += c, make(a), make(b);
}
int main() {
  cin >> n;
  t = pow(2, n), p = pow(2, n + 1);
  for (int i = 2; i < p; i++) cin >> edge[i];
  dfs(1), make(1);
  cout << ans;
  return 0;
}
