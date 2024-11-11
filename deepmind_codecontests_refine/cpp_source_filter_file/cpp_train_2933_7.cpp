#include <bits/stdc++.h>
using namespace std;
int n, m;
int mx[100050], mmx[100050];
int idl[100050], idr[100050];
int sum[1 << 11];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int x, y, state = 0;
    scanf("%d", &x);
    for (int j = 1; j <= x; j++) {
      scanf("%d", &y);
      state |= (1 << (y - 1));
    }
    sum[state]++;
  }
  memset(mx, 0x3f, sizeof(mx));
  memset(mmx, 0x3f, sizeof(mmx));
  for (int i = 1; i <= m; i++) {
    int x, y, value, state = 0;
    scanf("%d%d", &value, &x);
    for (int j = 1; j <= x; j++) {
      scanf("%d", &y);
      state |= (1 << (y - 1));
    }
    if (mx[state] > value)
      mmx[state] = mx[state], mx[state] = value, idr[state] = idl[state],
      idl[state] = i;
    else if (mmx[state] > value)
      mmx[state] = value, idr[state] = i;
  }
  int ans = 0x3f3f3f3f, ansp = 0, ansl, ansr;
  for (int i = 0; i <= 512; i++)
    for (int j = 0; j <= 512; j++) {
      if (!idl[i] || !idl[j]) continue;
      if (i == j && (!idr[i] || !idl[i])) continue;
      int res = 0, now = 0, people = 0;
      if (i == j)
        res = mx[i] + mmx[j];
      else
        res = mx[i] + mx[j];
      for (int k = 0; k <= 512; k++) {
        if (((i | j) & k) == k) people += sum[k];
      }
      if (people > ansp) {
        if (i == j)
          ansl = idl[i], ansr = idr[i];
        else
          ansl = idl[i], ansr = idl[j];
        ans = res, ansp = people;
      } else if (people == ansp && res < ans) {
        ans = res;
        if (i == j)
          ansl = idl[i], ansr = idr[i];
        else
          ansl = idl[i], ansr = idl[j];
      }
    }
  printf("%d %d", ansl, ansr);
}
