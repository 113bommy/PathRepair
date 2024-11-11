#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int len = (int)sqrt(30 * N) + 1;
const int M = 70;
int n, m, a[N], tab[M][10002], add[M];
vector<int> luck;
bool chk[10002];
char str[N];
bool IsLucky(int u) {
  while (u) {
    if (u % 10 != 4 and u % 10 != 7) return false;
    u /= 10;
  }
  return true;
}
void Count() {
  int lt, rt, ln, rn;
  scanf("%d %d", &lt, &rt);
  lt--, rt--;
  ln = lt / len + (lt % len != 0);
  rn = (rt + 1) / len;
  int rlt(0);
  for (int i = ln; i < rn; i++) {
    for (int j = 0; j < luck.size(); j++) {
      int u = luck[j] - add[i];
      if (u < 0) continue;
      rlt += tab[i][u];
    }
  }
  if (ln <= rn) {
    for (int i = lt; i < len * ln; i++) {
      if (chk[a[i] + add[ln - 1]]) rlt++;
    }
    for (int i = len * rn; i <= rt; i++) {
      if (chk[a[i] + add[rn]]) rlt++;
    }
  } else {
    for (int i = lt; i <= rt; i++) {
      if (chk[a[i] + add[ln - 1]]) rlt++;
    }
  }
  printf("%d\n", rlt);
}
void Add() {
  int lt, rt, val, ln, rn;
  scanf("%d %d %d", &lt, &rt, &val);
  lt--, rt--;
  ln = lt / len + (lt % len != 0);
  rn = (rt + 1) / len;
  for (int i = ln; i < rn; i++) add[i] += val;
  if (ln <= rn) {
    for (int i = lt; i < len * ln; i++) {
      tab[ln - 1][a[i]]--;
      a[i] += val;
      tab[ln - 1][a[i]]++;
    }
    for (int i = len * rn; i <= rt; i++) {
      tab[rn][a[i]]--;
      a[i] += val;
      tab[rn][a[i]]++;
    }
  } else {
    for (int i = lt; i <= rt; i++) {
      tab[ln - 1][a[i]]--;
      a[i] += val;
      tab[ln - 1][a[i]]++;
    }
  }
}
int main() {
  for (int i = 1; i < 10000; i++)
    if (IsLucky(i)) {
      luck.push_back(i);
      chk[i] = 1;
    }
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 0; i * len < n; i++)
    for (int j = i * len; j < n && j < (i + 1) * len; j++) tab[i][a[i]]++;
  for (int i = 0; i < m; i++) {
    scanf("%s", str);
    if (str[0] == 'c')
      Count();
    else
      Add();
  }
  return 0;
}
