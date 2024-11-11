#include <bits/stdc++.h>
using namespace std;
int sum[300010], pre[300010], pos[300010][2];
long long read() {
  long long tmp = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') {
    tmp = tmp * 10 + c - '0';
    c = getchar();
  }
  return tmp;
}
int main() {
  int n = read();
  for (int i = 1; i <= n; i++) {
    long long x = read();
    while (x) {
      sum[i] += x % 2;
      x /= 2;
    }
    pre[i] = pre[i - 1] + sum[i];
  }
  pos[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    pos[i][0] = pos[i - 1][0];
    pos[i][1] = pos[i - 1][1];
    pos[i][pre[i] % 2]++;
  }
  long long res = 0;
  for (int i = 1; i <= n; i++) {
    int mx = 0, tot = 0;
    for (int j = i; j >= 1; j--) {
      tot += sum[j];
      mx = max(mx, sum[j]);
      if (tot % 2 == 0 && mx <= tot / 2) res++;
      if (tot > 70) {
        if (j > 1) res += pos[j - 2][pre[i] % 2];
        break;
      }
    }
  }
  printf("%I64d\n", res);
  return 0;
}
