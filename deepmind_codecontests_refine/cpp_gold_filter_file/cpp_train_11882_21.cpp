#include <bits/stdc++.h>
using namespace std;
using namespace std;
int n;
int cz[2 * 100005][2], tot;
int num[100005];
struct AR {
  int id, val;
} arr[100005];
int cmp(AR a, AR b) { return a.val < b.val; }
bool luck(int x) {
  while (x) {
    int t = x % 10;
    if (t != 4 && t != 7) return 0;
    x /= 10;
  }
  return 1;
}
int zhizhen[100005];
void doswap(int x, int y) {
  swap(num[x], num[y]);
  swap(zhizhen[x], zhizhen[y]);
  swap(arr[zhizhen[x]].id, arr[zhizhen[y]].id);
}
int main() {
  scanf("%d", &n);
  int f1 = 0, f2 = -1;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &num[i]);
    arr[i].id = i;
    arr[i].val = num[i];
    if (f2 == -1 && luck(num[i])) {
      f2 = i;
    }
    if (i) {
      if (num[i] < num[i - 1]) f1 = 1;
    }
  }
  if (!f1) {
    printf("0\n");
  } else if (f2 == -1) {
    printf("-1\n");
  } else {
    sort(arr, arr + n, cmp);
    for (int i = 0; i < n; ++i) {
      zhizhen[arr[i].id] = i;
    }
    int lucksite = f2;
    tot = 0;
    for (int i = 0; i < n; ++i) {
      int where = arr[i].id;
      if (where == i) continue;
      if (luck(num[i]) || luck(num[where])) {
        cz[tot][0] = i;
        cz[tot++][1] = where;
        if (i == lucksite)
          lucksite = where;
        else if (where == lucksite)
          lucksite = i;
        doswap(i, where);
      } else {
        cz[tot][0] = lucksite;
        cz[tot++][1] = i;
        doswap(lucksite, i);
        lucksite = i;
        cz[tot][0] = lucksite;
        cz[tot++][1] = where;
        doswap(lucksite, where);
        lucksite = where;
      }
    }
    printf("%d\n", tot);
    for (int i = 0; i < tot; ++i) {
      printf("%d %d\n", cz[i][0] + 1, cz[i][1] + 1);
    }
    puts("");
  }
}
