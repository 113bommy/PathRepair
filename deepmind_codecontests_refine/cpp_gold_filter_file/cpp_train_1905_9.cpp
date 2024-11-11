#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, m, T, te, s, num;
int a[100010], b[100010], c[1010][1010], f[100010];
map<int, int> Map;
set<int> Set;
long long an;
inline void work(int x) {
  int k = x;
  for (; k; k /= 10) {
    int A = k % 10;
    if (A != 4 && A != 7) return;
  }
  if (!Map.count(x)) Map[x] = ++s;
  int A = Map[x];
  a[++m] = i;
  b[m] = A;
  c[A][++*c[A]] = i;
}
inline long long get4(long long x) {
  long long a[4] = {x, x - 1, x - 2, x - 3};
  int i, j;
  for (j = 4; j; j--)
    for (i = 0; i <= 3; i++)
      if (a[i] % j == 0) {
        a[i] /= j;
        break;
      }
  long long s = 1;
  for (i = 0; i <= 3; i++) s *= a[i];
  return s;
}
inline void suan1(int x) {
  int i, j;
  long long A = a[x - 1] - 1, s = A * (A - 1) / 2 + A;
  Set.clear();
  Set.insert(0);
  Set.insert(A + 1);
  ++num;
  for (i = x; i <= m; i++) {
    long long re = 1ll * (a[x] - a[x - 1]) * (a[i + 1] - a[i]);
    int B = b[i];
    if (f[B] != num) {
      f[B] = num;
      for (j = 1; j <= *c[B]; j++) {
        int C = c[B][j];
        if (C == a[i] || C == A + 1) break;
        set<int>::iterator a1 = Set.lower_bound(C);
        int r = *a1, l = *(--a1);
        s -= 1ll * (C - l) * (r - C);
        Set.insert(C);
      }
    }
    an += re * s;
    {
      long long A = a[x] - a[x - 1];
      if (A >= 3) an += 1ll * (a[i + 1] - a[i]) * (A * (A - 1) * (A - 2) / 6);
      if (A >= 2) an += 1ll * (a[i + 1] - a[i]) * (A * (A - 1) / 2);
    }
    if (x > 1 && f[b[x - 1]] != num) {
      set<int>::iterator a1 = Set.end();
      a1--;
      a1--;
      long long y = *a1;
      long long A = a[x] - a[x - 1] + 1;
      an += 1ll * (a[i + 1] - a[i]) * (A * (A - 1) / 2) * (a[x - 1] - y);
    }
  }
  {
    long long A = a[x] - a[x - 1] - 1;
    if (A >= 3) an += 1ll * (A * (A - 1) * (A - 2) / 6) * (a[x - 1]);
    if (A >= 2) an += 1ll * (A * (A - 1) / 2) * (a[x - 1]);
  }
  {
    long long A = a[x] - a[x - 1] - 1;
    long long B = a[x - 1];
    an += (A * (A - 1) / 2 + A) * (B * (B - 1) / 2 + B);
  }
}
inline void suan2(int x) {
  long long A = a[x] - a[x - 1] - 1;
  if (A >= 4) an += get4(A);
  if (A >= 3) an += A * (A - 1) * (A - 2) / 6 * 2;
  if (A >= 2) an += A * (A - 1) / 2;
}
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &k);
    work(k);
  }
  a[m + 1] = n + 1;
  for (i = 1; i <= m + 1; i++) {
    suan1(i);
    suan2(i);
  }
  printf("%I64d\n", an);
  return 0;
}
