#include <bits/stdc++.h>
using namespace std;
long long pp;
int n, x, pr[110000];
long long mo(long long a) {
  if (a >= 0 && a < pp) return a;
  a %= pp;
  if (a < 0) a += pp;
  return a;
}
long long ksm(long long a, int b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = mo(ans * a);
    a = mo(a * a);
    b /= 2;
  }
  return ans;
}
void fenjie(int n) {
  for (int i = 2; i <= n; i++)
    if (n % i == 0) {
      pr[++pr[0]] = i;
      while (n % i == 0) n /= i;
    }
}
int main() {
  cin >> n >> x;
  for (int i = 2; i * i <= n + 1; i++)
    if ((n + 1) % i == 0) {
      printf("-1\n");
      return 0;
    }
  fenjie(n);
  pp = n + 1;
  for (int i = x - 1; i > 1; i--) {
    bool ok = 1;
    for (int j = 1; j <= pr[0]; j++)
      if (ksm(i, n / pr[j]) == 1) {
        ok = 0;
        break;
      }
    if (ok) {
      printf("%d\n", i);
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}
