#include <bits/stdc++.h>
using namespace std;
bool isPrime[2000000];
int g[100005];
int n, x;
void findPrimes() {
  memset(isPrime, true, sizeof(isPrime));
  isPrime[1] = false;
  for (int i = 2; i < 2000; i++)
    if (isPrime[i])
      for (int j = i * i; j < 2000000; j += i) isPrime[j] = false;
}
int main() {
  scanf("%d%d", &n, &x);
  for (int i = 0; i < n; i++) {
    scanf("%d", &g[i]);
  }
  findPrimes();
  sort(g, g + n);
  if (x == 2) {
    printf("0");
    return 0;
  }
  if (n == 0) {
    printf("-1");
    return 0;
  }
  if (g[0] == 1) {
    printf("1");
    return 0;
  }
  int ans = 0;
  for (int i = 2, j = 0, to = min(x, 200000);;) {
    while (i < to && !isPrime[i]) i++;
    if (i == to) break;
    while (j < n && g[j] < i) j++;
    if (j == n || g[j] > i) {
      printf("-1");
      return 0;
    }
    ans++;
    i++;
  }
  printf("%d", ans);
  return 0;
}
