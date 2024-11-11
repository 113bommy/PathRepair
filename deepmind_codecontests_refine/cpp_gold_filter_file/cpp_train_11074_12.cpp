#include <bits/stdc++.h>
using namespace std;
const int N = 200000;
int prime[N], primes[N];
void sieve() {
  for (int i = 2; i <= N; i++) prime[i] = 1;
  for (int i = 2; i * i <= N; i++)
    if (prime[i])
      for (int y = i * i; y <= N; y += i) prime[y] = 0;
}
int main() {
  sieve();
  int idx = 0;
  for (int i = 0; i < N; i++) {
    if (prime[i]) primes[idx++] = i;
  }
  int n, m, arr[501][501];
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int y = 0; y < m; y++) {
      scanf("%d", &arr[i][y]);
      if (prime[arr[i][y]])
        arr[i][y] = 0;
      else {
        int *ptr = upper_bound(primes, primes + idx, arr[i][y]);
        arr[i][y] = *ptr - arr[i][y];
      }
    }
  }
  int mn[2];
  mn[0] = mn[1] = 1e6;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int y = 0; y < m; y++) {
      sum += arr[i][y];
    }
    mn[0] = min(mn[0], sum);
  }
  for (int i = 0; i < m; i++) {
    int sum = 0;
    for (int y = 0; y < n; y++) {
      sum += arr[y][i];
    }
    mn[1] = min(mn[1], sum);
  }
  printf("%d\n", min(mn[0], mn[1]));
  return 0;
}
