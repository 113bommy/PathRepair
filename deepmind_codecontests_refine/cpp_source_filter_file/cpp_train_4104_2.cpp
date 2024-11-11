#include <bits/stdc++.h>
using namespace std;
const int mx = 5009;
int n, t, a[mx], an[mx], num[mx], l[mx];
int v;
int L(int i) { return i & (-i); }
int main() {
  int i, j, M;
  int b, c, d, t;
  scanf("%d", &n);
  t = 0;
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i]++;
    l[i] = 0;
    for (j = a[i]; j > 0; j -= L(j)) l[i] += an[j];
    t += i - l[i];
    for (j = a[i]; j <= n; j += L(j)) an[j]++;
  }
  c = 0;
  d = 0;
  for (i = 0; i < n; i++) {
    v = 0;
    for (j = i + 1; j < n; j++)
      if (a[i] > a[j]) {
        b = l[j];
        for (M = a[i]; M > 0; M -= L(M)) b -= num[M];
        if (v - b > d) d = v - b, c = 0;
        if (v - b == d) c++;
        v++;
      }
    for (j = a[i]; j <= n; j += L(j)) num[j]++;
  }
  printf("%d %d", t - d - d - 1, c);
}
