#include <bits/stdc++.h>
using namespace std;
bool debug = 1;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
long long ln, lk, lm;
int a[100025], cnt[100025], P;
int b[100025];
long long ans;
void pp() {
  printf("%lld\n", ans);
  exit(0);
}
void cal() {
  int ji = 0;
  for (int(i) = 1; (i) <= (int)(n); (i)++)
    if (cnt[i] % 2 == 1) ji++;
  if (ji > 1) pp();
  int i = 1;
  for (; i <= P; i++)
    if (a[i] != a[n + 1 - i]) break;
  if (i > P) {
    ans = (long long)n * (n + 1) / 2;
    pp();
  }
  for (int j = 1; j < i; j++) cnt[a[j]] -= 2;
  int j;
  int n2 = n & 1;
  for (j = n + 1 - i; j > P; j--) {
    int x = a[j];
    if (j == P + n2)
      b[x]++;
    else
      b[x] += 2;
    if (b[x] > cnt[x]) break;
  }
  if (j == P) {
    for (j -= n2; j >= i && a[j] == a[n + 1 - j]; j--)
      ;
  }
  assert(i <= j);
  ans = (long long)i * (n + 1 - j);
  memset(b, 0, sizeof b);
  i = n + 1 - i;
  for (j = n + 1 - i; j <= P + n2; j++) {
    int x = a[j];
    if (j == P + n2 && n2 == 1)
      b[x]++;
    else
      b[x] += 2;
    if (b[x] > cnt[x]) break;
  }
  if (j > P + n2)
    for (; j <= i && a[j] == a[n + 1 - j]; j++)
      ;
  ans += (long long)(n + 1 - i) * (j - (n + 1 - i));
  pp();
}
int main() {
  scanf("%d", &n);
  for (int(i) = 1; (i) <= (int)(n); (i)++) {
    scanf("%d", a + i);
    cnt[a[i]]++;
  }
  P = n / 2;
  cal();
  return 0;
}
