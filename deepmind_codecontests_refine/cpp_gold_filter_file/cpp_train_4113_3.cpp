#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  n *= 2;
  int x = 0;
  long long s[640000], tmp;
  for (int i = 1; i < n; i++)
    for (int j = 0; j < i; j++) {
      scanf("%I64d", &tmp);
      s[x++] = tmp * 800 * 800 + i * 800 + j;
    }
  sort(s, s + x);
  int t[802] = {0};
  for (int k = x - 1; k >= 0; k--) {
    int i = s[k] % 800;
    int j = s[k] / 800 % 800;
    if (!t[i] && !t[j]) {
      t[i] = j + 1;
      t[j] = i + 1;
    }
  }
  for (int i = 0; i < n; i++) printf("%d%c", t[i], i + 1 < n ? ' ' : '\n');
  return 0;
}
