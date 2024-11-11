#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a, i, pn, mn, sn, ans;
  vector<int> pro;
  vector<int> mat;
  vector<int> spo;
  while (scanf("%d", &n) == 1) {
    pn = sn = mn = 0;
    for (i = 1; i <= n; i++) {
      scanf("%d", &a);
      if (a == 1) {
        pro.push_back(i);
        pn++;
      } else if (a == 2) {
        mat.push_back(i);
        mn++;
      } else {
        spo.push_back(i);
        sn++;
      }
    }
    if (pn == 0 || sn == 0 || mn == 0) {
      printf("0\n");
      pro.clear();
      mat.clear();
      spo.clear();
      continue;
    }
    ans = min(pn, min(sn, mn));
    printf("%d\n", ans);
    for (i = 0; i < ans; i++) {
      printf("%d %d %d\n", pro[i], mat[i], spo[i]);
    }
    pro.clear();
    mat.clear();
    spo.clear();
  }
  return 0;
}
