#include <bits/stdc++.h>
using namespace std;
const int LIM = 1000000;
int etf[1000010];
int factor[1000010];
int inp[1000006];
int powers[1000006];
void precomp() {
  int i, j;
  for (i = 1; i <= LIM; i++) etf[i] = i, factor[i] = i;
  for (i = 2; i <= LIM; i++)
    if (etf[i] == i)
      for (j = 2 * i; j <= LIM; j += i)
        etf[j] = etf[j] - (etf[j] / i), factor[j] = i;
  for (i = 2; i <= LIM; i++)
    if (etf[i] == i) etf[i] = i - 1;
}
int main() {
  precomp();
  int n, k;
  scanf("%d", &n);
  scanf("%d", &k);
  for (int i = 0; i < n; i++) scanf("%d", &inp[i]);
  memset(powers, 0, sizeof powers);
  for (int i = 0; i < n; i++) {
    int curr = inp[i];
    while (curr != 1) {
      int f = factor[curr], cnt = 0;
      while (curr % f == 0) curr /= f, cnt++;
      powers[f] = max(powers[f], cnt);
    }
  }
  int mod = 1;
  for (int i = 1; i <= 1000000; i++)
    for (int j = 0; j < powers[i]; j++) mod = (mod * 1LL * i) % k;
  if (mod == 0)
    cout << "Yes\n";
  else
    cout << "No\n";
  return 0;
}
