#include <bits/stdc++.h>
using namespace std;
int main() {
  int c, n, mn = -200, nz = 0, i;
  vector<int> v, vn;
  scanf("%d ", &n);
  for (i = 0; i < n; i++) {
    scanf("%d ", &c);
    if (c < 0) {
      if (c > mn) {
        if (mn > -200) vn.push_back(mn);
        mn = c;
      } else {
        vn.push_back(c);
      }
    } else {
      if (c > 0)
        v.push_back(c);
      else
        nz++;
    }
  }
  if (v.size() == 0 && vn.size() == 0) {
    if (nz)
      printf("0\n");
    else
      printf("%d\n", mn);
  } else {
    if (vn.size() % 2) vn.push_back(mn);
    if (v.size() > 0) {
      for (i = 0; i < vn.size(); i++) printf("%d ", vn[i]);
      for (i = 0; i < v.size() - 1; i++) printf("%d ", v[i]);
      printf("%d\n", v[v.size() - 1]);
    } else {
      for (i = 0; i < vn.size() - 1; i++) printf("%d ", vn[i]);
      printf("%d\n", vn[vn.size() - 1]);
    }
  }
}
