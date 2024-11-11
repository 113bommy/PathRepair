#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 4;
int sg[maxn];
int a[maxn];
int SG(int x) {
  if (x == 2)
    return 0;
  else if (x == 3)
    return 1;
  else if (x == 4)
    return 2;
  else if (x & 1)
    return 0;
  if (SG(x / 2) == 0)
    return 1;
  else if (SG(x / 2) == 1)
    return 2;
  else
    return 1;
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (k & 1) {
      if (a[i] == 1)
        ans ^= 1;
      else if (a[i] == 2)
        ans ^= 0;
      else if (a[i] == 3)
        ans ^= 1;
      else if (a[i] == 4)
        ans ^= 2;
      else if (a[i] & 1)
        ans ^= 0;
      else {
        ans ^= SG(a[i]);
      }
    } else {
      if (a[i] == 1)
        ans ^= 1;
      else if (a[i] == 2)
        ans ^= 2;
      else if (a[i] & 1) {
        ans ^= 0;
      } else
        ans ^= 1;
    }
  }
  if (ans)
    printf("Kevin\n");
  else
    printf("Nicky\n");
}
