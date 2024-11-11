#include <bits/stdc++.h>
using namespace std;
const long long Mod = 1000000007;
const int N = 1e5 + 5;
char a[N], b[N];
int pre[N], suf[N];
int main() {
  scanf("%s%s", a + 1, b + 1);
  int n = strlen(a + 1);
  int m = strlen(b + 1);
  for (int i = 1, j = 1; i <= n; i++) {
    pre[i] = pre[i - 1];
    if (j <= m and a[i] == b[j]) pre[i]++, j++;
  }
  for (int i = n, j = m; i > 0; i--) {
    suf[i] = suf[i + 1];
    if (j > 0 and a[i] == b[j]) suf[i]++, j--;
  }
  int best = 0, idx = 0;
  for (int i = 1; i <= n; i++) {
    if (pre[i] + suf[i + 1] > best) {
      best = pre[i] + suf[i + 1];
      idx = i;
    }
  }
  if (!best)
    puts("-");
  else if (best >= m)
    printf("%s\n", b + 1);
  else {
    for (int i = 1; i <= pre[idx]; i++) {
      printf("%c", b[i]);
    }
    for (int i = suf[idx + 1]; i > 0; i--) {
      printf("%c", b[m - i + 1]);
    }
    puts("");
  }
}
