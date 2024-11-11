#include <bits/stdc++.h>
using namespace std;
int n, cur = 1;
int a[200005], pos_zero[200005];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] == 0) pos_zero[cur++] = i;
  }
  pos_zero[0] = -1e9 - 5;
  pos_zero[cur] = 1e9 + 5;
  for (int i = 1, nxt = 0; i <= n; i++) {
    if (i >= pos_zero[nxt] && i <= pos_zero[nxt + 1])
      ;
    else
      nxt++;
    printf("%d ", min(abs(i - pos_zero[nxt]), abs(i - pos_zero[nxt + 1])));
  }
  return 0;
}
