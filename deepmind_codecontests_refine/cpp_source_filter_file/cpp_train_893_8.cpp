#include <bits/stdc++.h>
using namespace std;
const int MAXN = 25;
const int LIM = 18;
long long L, R;
int c[MAXN], dig[MAXN][2], ans = 0;
bool chk(int o, bool lower, bool upper) {
  if (o < 0) return 1;
  if (!lower && !upper)
    return 1;
  else if (!upper) {
    for (int i = 9; i >= dig[o][0]; i--)
      if (c[i] > 0) {
        c[i]--;
        bool vaild = chk(o - 1, (i == dig[o][0]), upper);
        c[i]++;
        if (vaild) return 1;
      }
  } else if (!lower) {
    for (int i = 0; i <= dig[o][1]; i++)
      if (c[i] > 0) {
        c[i]--;
        bool vaild = chk(o - 1, lower, (i == dig[o][1]));
        c[i]++;
        if (vaild) return 1;
      }
  } else {
    for (int i = dig[o][0] + 1; i <= dig[o][1] - 1; i++)
      if (c[i] > 0) return 1;
    if (dig[o][0] == dig[o][1]) {
      if (!c[dig[o][0]]) return 0;
      c[dig[o][0]]--;
      bool vaild = chk(o - 1, lower, upper);
      c[dig[o][0]]++;
      return vaild;
    }
    if (c[dig[o][0]] > 0) {
      c[dig[o][0]]--;
      bool vaild = chk(o - 1, lower, 0);
      c[dig[o][0]]++;
      if (vaild) return 1;
    }
    if (c[dig[o][1]] > 0) {
      c[dig[o][1]]--;
      bool vaild = chk(o - 1, 0, upper);
      c[dig[o][1]]++;
      if (vaild) return 1;
    }
  }
  return 0;
}
void DFS(int o, int sum) {
  if (o == 9) {
    c[o] = LIM - sum;
    ans += chk(LIM - 1, 1, 1);
    return;
  }
  for (int i = sum; i <= LIM; i++) {
    c[o] = i - sum;
    DFS(o + 1, i);
  }
}
int main() {
  scanf("%lld%lld", &L, &R);
  for (int i = 0; i <= LIM - 1; i++) {
    dig[i][0] = L % 10;
    L /= 10;
    dig[i][1] = R % 10;
    R /= 10;
  }
  DFS(0, 0);
  printf("%d\n", ans);
  return 0;
}
