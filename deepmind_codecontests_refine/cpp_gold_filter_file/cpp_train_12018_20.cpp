#include <bits/stdc++.h>
using namespace std;
int so[100050];
int main() {
  int n, x, k;
  scanf("%d", &n);
  memset(so, -1, sizeof(so));
  bool flag = true;
  while (n--) {
    scanf("%d%d", &x, &k);
    if (x > 0 && so[k] + 1 < x) {
      flag = false;
    } else if (x == so[k] + 1)
      so[k] = x;
  }
  if (flag)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
