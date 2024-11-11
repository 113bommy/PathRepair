#include <bits/stdc++.h>
using namespace std;
multiset<int> sh_ras, sw_ras;
set<int> sh_nom, sw_nom;
long long n, m, nom, l, r, i, j, k, a, b, x, w, h;
int main() {
  scanf("%d %d %d", &w, &h, &m);
  sh_nom.insert(0);
  sh_nom.insert(h);
  sh_ras.insert(h);
  set<int>::iterator it;
  sw_nom.insert(0);
  sw_nom.insert(w);
  sw_ras.insert(w);
  for (j = 1; j <= m; j++) {
    char c;
    int x;
    scanf(" %c %d", &c, &x);
    if (c == 'H') {
      it = sh_nom.lower_bound(x);
      r = *it;
      it--;
      l = *it;
      sh_ras.erase(sh_ras.find(r - l));
      sh_ras.insert(r - x);
      sh_ras.insert(x - l);
      sh_nom.insert(x);
    }
    if (c == 'V') {
      it = sw_nom.lower_bound(x);
      r = *it;
      it--;
      l = *it;
      sw_ras.erase(sw_ras.find(r - l));
      sw_ras.insert(r - x);
      sw_ras.insert(x - l);
      sw_nom.insert(x);
    }
    long long ans = (*(sh_ras.rbegin())) * (*(sw_ras.rbegin()));
    printf("%I64d\n", ans);
  }
}
