#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000 + 5;
bool f[maxn];
int main() {
  string s;
  cin >> s;
  int n = s.size(), k = log2(n);
  int tot = (1 << k) - 1;
  for (int i = 0; i <= tot; i++) f[i] = true;
  for (int i = 1; i <= n - tot; i++) {
    for (int S = 0; S <= tot; S++)
      if (f[S])
        for (int j = 0; j < k; j++) f[S | (1 << j)] = true;
    char c = 'z';
    for (int S = 0; S <= tot; S++)
      if (f[S]) c = min(c, s[S + i - 1]);
    putchar(c);
    for (int S = 0; S <= tot; S++) f[S] &= (s[S + i - 1] == c);
  }
  return 0;
}
