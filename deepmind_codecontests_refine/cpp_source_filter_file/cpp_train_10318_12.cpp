#include <bits/stdc++.h>
using namespace std;
struct NODE {
  int o, v, n;
};
NODE a[105];
int ans[105];
map<int, int> ma;
int main() {
  int n;
  scanf("%d", &n);
  int one = 0, two = 0, mo = 0;
  ma.clear();
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i].v);
    a[i].o = i;
    a[i].n = 0;
    if (ma.find(a[i].v) == ma.end()) ma[a[i].v] = 0;
    ma[a[i].v]++;
  }
  for (auto i = ma.begin(); i != ma.end(); i++) {
    if (i->second == 1)
      one++;
    else if (i->second == 2)
      two++;
    else
      mo++;
  }
  bool flag = true;
  if (one % 2 == 0) {
    int p = one / 2;
    for (int i = 0; i < n; i++) {
      if (ma[a[i].v] == 1) {
        a[i].n = 1;
        p--;
      }
      if (!p) break;
    }
  } else {
    if (mo == 0)
      flag = false;
    else {
      int p = one / 2, om = 1;
      for (int i = 0; i < n; i++) {
        if (ma[a[i].v] == 1) {
          a[i].n = 1;
          p--;
        } else if (om && ma[a[i].v] > 2) {
          a[i].n = 1;
          om--;
        }
        if (!p && !om) break;
      }
    }
  }
  printf("%s\n", flag ? "YES" : "NO");
  if (flag) {
    for (int i = 0; i < n; i++) ans[a[i].o] = a[i].n;
    for (int i = 0; i < n; i++) printf("%s ", ans[i] ? "A" : "B");
    printf("\n");
  }
  return 0;
}
