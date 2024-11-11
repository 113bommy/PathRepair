#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f, maxn = 100005;
int n, a[maxn], num[maxn], use[maxn];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), num[a[i]]++;
  int flag = 0;
  for (int i = 1; i <= n; i++)
    if (num[i] & 1) flag++;
  if (flag > 1)
    printf("0\n");
  else {
    int pos = 0;
    for (int i = 1; i <= n / 2; i++)
      if (a[i] != a[n - i + 1]) {
        pos = i;
        break;
      } else
        num[a[i]] -= 2;
    if (!pos)
      printf("%I64d\n", (long long)n * (n - 1));
    else {
      int cnt = 0;
      for (int i = pos; i <= n; i++) {
        use[a[i]]++;
        if (2 * use[a[i]] > num[a[i]]) {
          if (i < n - i + 1 || i == n - i + 1 && num[a[i]] % 2 == 0 ||
              a[i] != a[n - i + 1])
            break;
        }
        cnt++;
      }
      memset(use, 0, sizeof(use));
      for (int i = n - pos + 1; i >= 1; i--) {
        use[a[i]]++;
        if (2 * use[a[i]] > num[a[i]]) {
          if (i > n - i + 1 || i == n - i + 1 && num[a[i]] % 2 == 0 ||
              a[i] != a[n - i + 1])
            break;
        }
        cnt++;
      }
      printf("%I64d\n", (long long)pos * (pos + cnt));
    }
  }
  return 0;
}
