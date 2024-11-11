#include <bits/stdc++.h>
long long a[11], gg = 0;
long long hhh() {
  long long g = 0, g1 = 1;
  for (long long i = 0; i <= 9; i++) g += a[i];
  for (long long i = 1; i <= g; i++) g1 *= i;
  for (long long i = 0; i <= 9; i++) {
    long long f = 1;
    for (long long j = 1; j <= a[i]; j++) f *= j;
    g1 /= f;
  }
  return g1;
}
long long jisuan() {
  long long g = 0, g1 = 1;
  for (long long i = 0; i <= 9; i++) g += a[i];
  for (long long i = 1; i <= g; i++) g1 *= i;
  for (long long i = 0; i <= 9; i++) {
    long long f = 1;
    for (long long j = 1; j <= a[i]; j++) f *= j;
    g1 /= f;
  }
  if (a[0]) {
    a[0]--;
    g1 -= hhh();
    a[0]++;
  }
  return g1;
}
void dfs() {
  gg += jisuan();
  for (long long i = 0; i <= 9; i++) {
    if (a[i] <= 1) continue;
    a[i]--;
    dfs();
    a[i]++;
  }
}
int main() {
  long long n;
  std::cin >> n;
  while (n) {
    a[n % 10]++;
    n /= 10;
  }
  dfs();
  std::cout << gg << std::endl;
}
