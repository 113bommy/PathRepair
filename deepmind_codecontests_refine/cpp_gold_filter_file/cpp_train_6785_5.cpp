#include <bits/stdc++.h>
using namespace std;
long long n, cnt, mn = 1e9, a[135], d[135][135], e[135][135];
int main() {
  long long i, j, k, t;
  cin >> n;
  for (i = 0; i < n; i++) {
    scanf("%I64d", &t);
    if (t) {
      a[cnt++] = t;
      if (cnt > 128) break;
    }
  }
  if (i < n) {
    puts("3");
    return 0;
  }
  for (i = 0; i < cnt; i++)
    for (j = 0; j < cnt; j++) {
      if (i != j && a[i] & a[j])
        d[i][j] = e[i][j] = 1;
      else
        d[i][j] = e[i][j] = 1e9;
    }
  for (k = 0; k < cnt; k++) {
    for (i = 0; i < k; i++)
      for (j = i + 1; j < k; j++) {
        mn = min(mn, e[i][k] + e[k][j] + d[i][j]);
      }
    for (i = 0; i < cnt; i++)
      for (j = 0; j < cnt; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
  }
  cout << (mn < 1e9 ? mn : -1);
  return 0;
}
