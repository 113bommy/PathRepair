#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s, a[1005], b[1005];
  bool flag = false;
  scanf("%d %d", &n, &s);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
  if (a[s] + b[s] == 0 || a[1] == 0)
    flag = false;
  else if (a[s])
    flag = true;
  else {
    for (int i = 1; i <= n; ++i)
      if (a[i] + b[i] == 2) flag = true;
  }
  if (flag)
    printf("YES");
  else
    printf("NO");
}
