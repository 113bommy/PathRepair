#include <bits/stdc++.h>
using namespace std;
int so[100100], tr[100100];
int ansnum;
int ans[200100][2], a[100100];
void swaps(int x, int y) {
  int t = tr[x];
  tr[x] = tr[y];
  tr[y] = t;
  so[tr[x]] = x;
  so[tr[y]] = y;
  ans[ansnum][0] = x;
  ans[ansnum][1] = y;
  ansnum++;
}
bool ck(int w) {
  while (w) {
    if (w % 10 != 4 && w % 10 != 7) return 0;
    w /= 10;
  }
  return 1;
}
bool cmp(const int &u, const int &v) { return a[u] < a[v]; }
int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    bool flag = 1;
    for (int i = 1; i < n; i++)
      if (a[i] < a[i - 1]) flag = 0;
    if (flag) {
      puts("0");
      continue;
    }
    int num = -1;
    for (int i = 0; i < n; i++)
      if (ck(i)) {
        num = i;
        break;
      }
    if (num == -1) {
      puts("-1");
      continue;
    }
    for (int i = 0; i < n; i++) so[i] = i;
    sort(so, so + n, cmp);
    for (int i = 0; i < n; i++) tr[so[i]] = i;
    ansnum = 0;
    for (int i = 0; i < n; i++)
      if (so[i] != i) {
        if (num != i) {
          swaps(num, i);
          num = i;
        }
        int tt = so[i];
        if (so[i] != num) swaps(so[i], num);
        num = tt;
      }
    printf("%d\n", ansnum);
    for (int i = 0; i < ansnum; i++)
      printf("%d %d\n", ans[i][0] + 1, ans[i][1] + 1);
    for (int i = 0; i < ansnum; i++) {
      int t1 = ans[i][0];
      int t2 = ans[i][1];
      int t = a[t1];
      a[t1] = a[t2], a[t2] = t;
    }
  }
  return 0;
}
