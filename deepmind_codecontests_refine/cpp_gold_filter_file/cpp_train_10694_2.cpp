#include <bits/stdc++.h>
using namespace std;
int gi() {
  int a;
  scanf("%d", &a);
  return a;
}
long long gli() {
  long long a;
  scanf("%I64d", &a);
  return a;
}
int x[200000];
int y[200000];
int w[200000];
int f[200000];
int c1[200000];
int c2[200000];
int L;
int mknd(int ww) {
  x[L] = gi();
  y[L] = gi();
  w[L] = ww;
  f[L] = 1;
  return L++;
}
int mkp(int n1, int n2, int m) {
  f[n2] = m;
  x[L] = x[n1] + m * x[n2];
  y[L] = y[n1] + m * y[n2];
  f[L] = 1;
  c1[L] = n1;
  c2[L] = n2;
  return L++;
}
void st(int a, int ff) {
  ff *= f[a];
  if (w[a] == -1) {
    st(c1[a], ff);
    st(c2[a], ff);
  } else
    x[w[a]] = ff;
}
int sm(long long x, long long y, long long c) { return x * x + y * y <= c * c; }
int main() {
  int n = gi();
  if (n == 1) {
    printf("1\n");
    return 0;
  }
  memset(w, -1, sizeof(w));
  L = 0;
  int nn[3];
  nn[0] = mknd(0);
  nn[1] = mknd(1);
  for (int i = 2; i < n; i++) {
    nn[2] = mknd(i);
    int cnt = 1;
    for (int j = 0; j < 3 && cnt; j++)
      for (int k = j + 1; k < 3 && cnt; k++)
        for (int s = -1; s < 2 && cnt; s += 2)
          if (sm(x[nn[j]] + s * x[nn[k]], y[nn[j]] + s * y[nn[k]], 1000000LL)) {
            cnt = 0;
            nn[j] = mkp(nn[j], nn[k], s);
            if (k == 1) nn[1] = nn[2];
          }
  }
  st(mkp(nn[0], nn[1],
         sm(x[nn[0]] + x[nn[1]], y[nn[0]] + y[nn[1]], 1500000LL) ? 1 : -1),
     1);
  for (int i = 0; i < n; i++) printf("%d%c", x[i], (i == n - 1 ? '\n' : ' '));
  return 0;
}
