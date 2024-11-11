#include <bits/stdc++.h>
using namespace std;
char second[1000010], res[1000010], n;
bool flag;
void sol(int p, int fst, int sed, bool e) {
  if (p == n) {
    flag = true;
    res[n] = '\0';
    return;
  }
  if (e) {
    int i;
    for (i = p; fst * 2 < n; i++, fst++) res[i] = '4';
    for (; i < n; i++) res[i] = '7';
    res[n] = '\0';
    flag = true;
    return;
  } else {
    if ('7' < second[p]) return;
    if (fst * 2 < n && '4' >= second[p])
      res[p] = '4', sol(p + 1, fst + 1, sed, '4' > second[p]);
    if (flag) return;
    if (sed * 2 < n && '7' >= second[p])
      res[p] = '7', sol(p + 1, fst, sed + 1, '7' > second[p]);
  }
}
int main() {
  scanf("%s", second);
  n = strlen(second);
  if (n & 1) {
    n = (n + 1) / 2;
    for (int i = 0; i < n; i++) printf("4");
    for (int i = 0; i < n; i++) printf("7");
    printf("\n");
  } else {
    sol(0, 0, 0, 0);
    if (flag)
      printf("%s\n", res);
    else {
      n = (n + 2) / 2;
      for (int i = 0; i < n; i++) printf("4");
      for (int i = 0; i < n; i++) printf("7");
      printf("\n");
    }
  }
  return 0;
}
