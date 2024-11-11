#include <bits/stdc++.h>
using namespace std;
char S[1010][10];
int go(int a, int b) {
  int k = 0;
  for (int i = 0; i < 6; i++) k += (S[a][i] != S[b][i]);
  return (ceil(k / 2.0) - 1);
}
int main() {
  int cs, t, i, j, k, n;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%s", S[i]);
  int ans = 6;
  for (i = 1; i <= n; i++) {
    for (j = i + 1; j <= n; j++) ans = min(ans, go(i, j));
  }
  cout << ans << endl;
  return 0;
}
