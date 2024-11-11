#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 200000;
int N, P[MAX_N + 5], V[MAX_N + 5], r, g, ans;
void dfs(int nw) {
  if (nw == r) return;
  if (V[nw] == g) {
    P[nw] = r;
    ans++;
    return;
  } else if (V[nw])
    return;
  V[nw] = g;
  dfs(P[nw]);
}
int main() {
  int i;
  scanf("%d", &N);
  for (i = 1; i <= N; i++) scanf("%d", P + i);
  for (i = 1; i <= N; i++)
    if (P[i] == i) r = i;
  for (i = 1; i <= N; i++) {
    ++g;
    dfs(i);
  }
  printf("%d\n", ans);
  for (i = 1; i <= N; i++) {
    if (!P[i]) {
      if (!r) r = i;
      printf("%d ", r);
    } else
      printf("%d ", P[i]);
  }
  return 0;
}
