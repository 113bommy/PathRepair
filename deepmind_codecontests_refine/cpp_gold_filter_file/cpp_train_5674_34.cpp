#include <bits/stdc++.h>
using namespace std;
int cmpfunc(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
long long int gcd(long long int m, long long int n) {
  if (n == 0) return m;
  return gcd(n, m % n);
}
long long int fastpow(long long int a, long long int b, long long int m) {
  long long int r = 1;
  while (b > 0) {
    if (b % 2 == 1) r = (r * a) % m;
    b = b >> 1;
    a = (a * a) % m;
  }
  return r;
}
int prime(long long int x) {
  if (x == 1) return 0;
  if (x <= 3) return 1;
  if (x % 6 == 1 || x % 6 == 5) {
    long long int y = sqrt(x), i;
    for (i = 2; i <= y; i++)
      if (x % i == 0) return 0;
    return 1;
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long long int n, m;
  cin >> n >> m;
  long long int candidates[n + 1];
  for (long long int i = 1; i <= n; i++) candidates[i] = 0;
  long long int a[m + 1][n + 1];
  for (long long int i = 1; i <= m; i++)
    for (long long int j = 1; j <= n; j++) cin >> a[i][j];
  long long int winner[m + 1];
  for (long long int i = 1; i <= m; i++) {
    winner[i] = 0;
  }
  for (long long int i = 1; i <= m; i++) {
    long long int maxindex = 0;
    long long int max = -1;
    for (long long int j = 1; j <= n; j++) {
      if (a[i][j] > max) {
        max = a[i][j];
        maxindex = j;
      }
    }
    winner[i] = maxindex;
  }
  long long int value[101];
  for (long long int i = 1; i <= 100; i++) value[i] = 0;
  for (long long int i = 1; i <= m; i++) {
    value[winner[i]]++;
  }
  long long int max = 0;
  long long int maxindex = 0;
  for (long long int i = 1; i <= 100; i++) {
    if (value[i] > max) {
      max = value[i];
      maxindex = i;
    }
  }
  cout << maxindex << endl;
  return 0;
}
