#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1000000;
int n, T;
char str[MAXN];
int scnt, hcnt, righth;
bool check(int mid) {
  int num = mid;
  int pos = -1;
  int t = 0;
  for (int i = 0; i <= righth; i++) {
    t++;
    if (str[i] == 'H') {
      if (num == 0 && pos == -1) pos = i;
      num--;
    }
    if (str[i] == 'S') num++;
    if (pos != -1 && num == 0) {
      if ((i - pos) * 2 < (righth - pos)) {
        t += (i - pos) * 2;
        pos = -1;
      }
    }
  }
  if (pos != -1) {
    if (num >= 0)
      t += righth - pos;
    else {
      for (int i = righth + 1; i < n; i++) {
        t++;
        if (str[i] == 'S') num--;
        if (num == 0) {
          t += i - pos;
          break;
        }
      }
    }
  }
  return t <= T;
}
int erfen(int left, int right) {
  int mid;
  if (!check(right)) return -1;
  while (left <= right) {
    mid = (left + right) >> 1;
    if (check(mid))
      right = mid - 1;
    else
      left = mid + 1;
  }
  return left;
}
void solved(int cas) {
  scanf("%d %d", &n, &T);
  scanf("%s", str);
  scnt = hcnt = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] == 'S') scnt++;
    if (str[i] == 'H') {
      righth = i;
      hcnt++;
    }
  }
  printf("%d\n", erfen(max(0, hcnt - scnt), hcnt));
}
int main() {
  int T = 1;
  for (int i = 1; i <= T; i++) solved(i);
  return 0;
}
