#include <bits/stdc++.h>
using namespace std;
struct ji {
  long long a[5][5];
} a, b, c;
long long n, k;
int V, tr[2000005][5], f[5][5][100005];
char s[100005];
void ins(int k) {
  for (int i = k, j = 1; (i < k + 20) && (s[i]); j = tr[j][s[i++] - 'A'])
    if (!tr[j][s[i] - 'A']) {
      tr[j][s[i] - 'A'] = ++V;
      f[s[k] - 'A'][s[i] - 'A'][i - k]++;
    }
}
ji cheng(ji a, ji b) {
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) c.a[i][j] = n + 1;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 4; k++)
        c.a[i][k] = min(c.a[i][k], a.a[i][j] + b.a[j][k]);
  return c;
}
void ksm(ji a, long long n) {
  while (n) {
    if (n & 1) b = cheng(b, a);
    a = cheng(a, a);
    n /= 2;
  }
}
bool pd(ji a) {
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      if (a.a[i][j] < n) return 1;
  return 0;
}
int main() {
  scanf("%lld%s", &n, s);
  V = 1;
  for (int i = 0; s[i]; i++) ins(i);
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) {
      for (int k = 1; f[i][j][k] == (1 << (2 * k - 2)); k++) a.a[i][j] = k;
      a.a[i][j]++;
    }
  k = n;
  for (long long i = 0; i < k;) {
    memset(b.a, 0, sizeof(b.a));
    long long j = (i + k + 1 >> 1);
    ksm(a, j);
    if (pd(b))
      i = j;
    else
      k = j - 1;
  }
  printf("%lld", k + 1);
}
