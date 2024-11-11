#include <bits/stdc++.h>
using namespace std;
inline int ty() {
  register int a = 0, b = 1, c = getchar();
  while (!isdigit(c)) b ^= c == '-', c = getchar();
  while (isdigit(c)) a = a * 10 + c - 48, c = getchar();
  return b ? a : -a;
}
const int _ = 102;
int val[_], n, ze[_], po[_], ne[_], lpo = 0, lne = 0, lze = 0;
int main() {
  register int i;
  n = ty();
  for (i = 1; i <= n; i++) {
    val[i] = ty();
    if (val[i] > 0)
      po[++lpo] = i;
    else if (val[i] < 0)
      ne[++lne] = i;
    else
      ze[++lze] = i;
  }
  if (lne % 2 == 0) {
    for (i = 2; i <= lne; i++)
      if (val[ne[i]] > val[ne[1]]) swap(ne[i], ne[1]);
    for (i = 1; i < lpo; i++) printf("1 %d %d\n", po[i], po[i + 1]);
    for (i = 1; i < lne; i++) printf("1 %d %d\n", ne[i], ne[i + 1]);
    for (i = 1; i < lze; i++) printf("1 %d %d\n", ze[i], ze[i + 1]);
    if (lze != 0 && (lpo != 0 || lne != 0)) printf("2 %d\n", ze[lze]);
    if (lne != 0 && lpo != 0) printf("1 %d %d\n", po[lpo], ne[lne]);
  } else {
    for (i = 2; i <= lne; i++)
      if (val[ne[i]] > val[ne[1]]) swap(ne[i], ne[1]);
    for (i = 1; i < lpo; i++) printf("1 %d %d\n", po[i], po[i + 1]);
    for (i = 2; i < lne; i++) printf("1 %d %d\n", ne[i], ne[i + 1]);
    for (i = 1; i < lze; i++) printf("1 %d %d\n", ze[i], ze[i + 1]);
    if (lze != 0) printf("1 %d %d\n", ze[lze], ne[1]);
    if (lne != 1 && lpo != 0) printf("1 %d %d\n", po[lpo], ne[lne]);
    if (!(lpo == 0 && lze && lne == 1)) printf("2 %d\n", ne[1]);
  }
  return 0;
}
