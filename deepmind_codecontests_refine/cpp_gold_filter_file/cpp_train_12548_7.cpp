#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
const double EPS = 1e-6;
const long long INF = 1e9;
const int base = 1e6;
long long prime[MAXN];
int cnt = 0;
int a[MAXN], b[MAXN], c[MAXN];
int pr[3000][300];
int len[3000];
int mult(int n1, int n2, int id) {
  long long p = 0, tmp;
  int n3 = 0;
  for (int i = 0; i < n2; i++) {
    for (int j = 0; j < n1; j++) {
      tmp = p + pr[id][i] * a[j];
      c[i + j] += tmp % base;
      p = tmp / base;
      n3 = max(i + j, n3);
    }
  }
  if (p) c[++n3] = p;
  n3++;
  return n3;
}
int main() {
  int n;
  scanf("%d", &n);
  cnt = 1;
  prime[0] = 2;
  if (n == 2) {
    printf("-1");
    return 0;
  }
  for (long long i = 3; cnt < n; i++) {
    bool ispr = true;
    for (int j = 0; j < cnt; j++) {
      if (i % prime[j] == 0) {
        ispr = false;
        break;
      }
    }
    if (ispr) {
      prime[cnt++] = i;
    }
  }
  for (int i = 0; i < n; i++) {
    int a = prime[i];
    int cur = 0;
    while (a) {
      int t = a % base;
      pr[i][cur++] = t;
      a /= base;
    }
    len[i] = cur;
  }
  int n1, n2, n3;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 200; j++) {
      a[j] = 0;
      b[j] = 0;
      c[j] = 0;
    }
    a[0] = 1;
    n1 = 1;
    n2 = 0;
    n3 = 0;
    for (int j = 0; j < n; j++) {
      if (i != j) {
        int lenn = mult(n1, len[j], j);
        n1 = lenn;
        for (int h = 0; h < n1; h++) {
          a[h] = c[h];
          c[h] = 0;
        }
      }
    }
    for (int j = n1 - 1; j >= 0; j--) {
      if (j < n1 - 1)
        printf("%06d", a[j]);
      else
        printf("%d", a[j]);
    }
    printf("\n");
  }
  return 0;
}
