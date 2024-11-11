#include <bits/stdc++.h>
inline long long Input() {
  long long ret = 0;
  bool isN = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') isN = 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    ret = ret * 10 + c - '0';
    c = getchar();
  }
  return isN ? -ret : ret;
}
inline void Output(long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  int len = 0, data[25];
  while (x) {
    data[len++] = x % 10;
    x /= 10;
  }
  if (!len) data[len++] = 0;
  while (len--) putchar(data[len] + 48);
  putchar('\n');
}
#pragma comment(linker, "/STACK:124000000,124000000")
const long double PI = acos(-1.0);
using namespace std;
bool flag[1000005];
int pri[1000005], t;
void pre() {
  t = 0;
  memset(flag, 0, sizeof(flag));
  for (int i = 2; i < 1000005; i++) {
    if (!flag[i]) pri[t++] = i;
    for (int j = 0; j < t && i * pri[j] < 1000005; j++) {
      flag[i * pri[j]] = 1;
      if (i % pri[j] == 0) break;
    }
  }
}
int main() {
  int n, k;
  pre();
  scanf("%d%d", &n, &k);
  memset(flag, 0, sizeof(flag));
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    flag[x] = 1;
  }
  for (int i = 2; i <= k; i++)
    for (int j = i + i; j <= 1000005; j++) flag[i] |= flag[j];
  bool ans = 1;
  for (int i = 0; i < t && k > 1; i++) {
    if (k % pri[i] == 0) {
      int tmp = 1;
      while (k % pri[i] == 0) {
        tmp = tmp * pri[i];
        k = k / pri[i];
      }
      if (!flag[tmp]) {
        ans = 0;
        break;
      }
    }
  }
  printf("%s\n", ans ? "YES" : "NO");
  return 0;
}
