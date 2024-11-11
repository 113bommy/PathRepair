#include <bits/stdc++.h>
using namespace std;
int a[1000005], b[1000005], v[1000005];
int check(int n, int l) {
  for (int i = (1); i <= (l - 1); i++) {
    int flag = 1;
    for (int j = (1); j <= (n); j++) v[a[j]] = 1;
    for (int j = (1); j <= (n); j++) {
      int t = (i + b[j]) % l;
      if (v[t])
        v[t] = 0;
      else {
        flag = 0;
        break;
      }
    }
    if (flag) return 1;
  }
  return 0;
}
int main() {
  int n, l;
  scanf("%d%d", &n, &l);
  for (int i = (1); i <= (n); i++) scanf("%d", &a[i]);
  for (int i = (1); i <= (n); i++) scanf("%d", &b[i]);
  if (check(n, l))
    printf("YES\n");
  else
    printf("NO\n");
}
