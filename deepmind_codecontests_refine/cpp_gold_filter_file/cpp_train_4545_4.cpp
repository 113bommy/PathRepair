#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int n, m, k;
int f[N];
char c[N];
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> c + 1;
  n = strlen(c + 1);
  k = log2(n);
  m = n - (1 << k) + 1;
  f[0] = 1;
  for (int i = 1; i <= m; i++) {
    char mn = 'z';
    for (int j = 0; j < (1 << k); j++) {
      for (int l = 0; l < k; l++)
        if (j & (1 << l)) f[j] |= f[j ^ (1 << l)];
      if (f[j]) mn = min(c[i + j], mn);
    }
    putchar(mn);
    for (int j = 0; j < (1 << k); j++)
      if (c[i + j] != mn) f[j] = 0;
  }
  return 0;
}
