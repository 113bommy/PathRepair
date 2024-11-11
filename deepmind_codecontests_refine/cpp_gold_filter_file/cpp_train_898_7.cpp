#include <bits/stdc++.h>
using namespace std;
const int MAXN = -1;
int n;
string aux, tipo;
map<string, int> M;
int main() {
  while (scanf("%d", &n) == 1) {
    M.clear();
    for (int i = (0); i < (int)(n); i++) {
      cin >> aux >> tipo;
      M[tipo]++;
    }
    int tM = max(M["soft"], M["hard"]), tm = min(M["soft"], M["hard"]);
    int ans = 1;
    while (((ans * ans) / 2 < tm) || ((ans * ans + 1) / 2 < tM)) ans++;
    printf("%d\n", ans);
  }
  return 0;
}
