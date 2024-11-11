#include <bits/stdc++.h>
using namespace std;
int n;
int w[501000], Mn[20][501000], Mx[20][501000], MM[501000], Res[501000], Ans;
pair<int, int> Get(int b, int e) {
  int t = MM[e - b];
  return {min(Mn[t][b], Mn[t][e - (1 << t)]),
          max(Mx[t][b], Mx[t][e - (1 << t)])};
}
int main() {
  int i, j;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &w[i]);
  }
  for (i = 1; i < 501000; i++) {
    MM[i] = MM[i - 1];
    while ((1 << MM[i] + 1) <= i) MM[i]++;
  }
  w[0] = w[1], w[n + 1] = w[n];
  for (i = 0; i <= n; i++) {
    Mn[0][i] = max(w[i], w[i + 1]);
    Mx[0][i] = min(w[i], w[i + 1]);
  }
  for (i = 0; i < 19; i++) {
    for (j = 0; j <= n - (1 << i); j++) {
      Mn[i + 1][j] = min(Mn[i][j], Mn[i][j + (1 << i)]);
      Mx[i + 1][j] = max(Mx[i][j], Mx[i][j + (1 << i)]);
    }
  }
  for (i = 1; i <= n; i++) {
    int b = 1, e = min(i, n + 1 - i), mid, r = 0;
    while (b <= e) {
      mid = (b + e) >> 1;
      pair<int, int> t = Get(i - mid, i + mid);
      if (t.first <= t.second) {
        r = mid;
        e = mid - 1;
      } else
        b = mid + 1;
    }
    if (r == 1)
      Res[i] = w[i];
    else {
      pair<int, int> t = Get(i - r, i + r);
      if (w[i] > w[i - 1]) {
        if (r % 2 == 0)
          Res[i] = t.second;
        else
          Res[i] = t.first;
      } else {
        if (r % 2 == 1)
          Res[i] = t.second;
        else
          Res[i] = t.first;
      }
    }
    Ans = max(Ans, r - 1);
  }
  printf("%d\n", Ans);
  for (i = 1; i <= n; i++) printf("%d ", Res[i]);
}
