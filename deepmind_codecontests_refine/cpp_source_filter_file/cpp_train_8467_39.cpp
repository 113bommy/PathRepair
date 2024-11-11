#include <bits/stdc++.h>
using namespace std;
long long n;
long long f[51];
void build() {
  f[0] = 0;
  f[1] = 1;
  for (int i = 2; i <= 50; i++) f[i] = f[i - 1] + f[i - 2];
}
int main() {
  build();
  cin >> n;
  for (int i = 1; f[i] <= n; i++)
    for (int j = 1; f[j] <= n; j++)
      for (int k = 1; f[k] <= n; k++)
        if (f[i] + f[j] + f[k] == n)
          return !printf("%I64d %I64d %I64d", f[i], f[j], f[k]);
  return !printf("I'm too stupid to solve this problem");
  return 0;
}
