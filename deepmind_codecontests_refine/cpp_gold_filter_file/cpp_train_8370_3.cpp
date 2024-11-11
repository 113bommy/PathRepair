#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, m, w[100000];
  int i;
  scanf("%d%d", &n, &m);
  for (i = 0; i < m; i++) scanf("%*d%d", &w[i]);
  sort(w, w + m, greater<int>());
  int qtde = 1;
  long long need;
  for (i = m; i > 0; i--) {
    if (i & 1)
      need = 0;
    else
      need = (i - 2) / 2;
    need += i * (long long)(i - 1) / 2;
    if (need < n) {
      qtde = i;
      break;
    }
  }
  long long ans = 0;
  for (i = 0; i < qtde; i++) ans += w[i];
  cout << ans << endl;
  return 0;
}
