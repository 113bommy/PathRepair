#include <bits/stdc++.h>
using namespace std;
const int NMAX = 1000005;
int v[NMAX];
int a[] = {4, 8, 15, 16, 23, 42};
int st[10];
int findpoz(int x) {
  int i = 0;
  while (x != a[i]) {
    i++;
  }
  return i;
}
int main() {
  int n;
  scanf("%d", &n);
  bool ok = 0;
  int p = 0;
  int sol = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &v[++p]);
    int j;
    for (j = 0; j < 6; j++) {
      if (v[i] == a[j]) {
        j = 10;
      }
    }
    if (j < 10) {
      v[p--] = 0;
      sol++;
    }
  }
  n = p;
  for (int i = 1; i <= n; i++) {
    int poz = findpoz(v[i]) + 1;
    if (st[poz - 1] == 0) {
      if (poz == 1) {
        st[poz]++;
      } else {
        sol++;
      }
    } else {
      st[poz - 1]--;
      st[poz]++;
    }
  }
  for (int j = 1; j <= 5; j++) {
    sol += (st[j]) * j;
  }
  printf("%d\n", sol);
  return 0;
}
