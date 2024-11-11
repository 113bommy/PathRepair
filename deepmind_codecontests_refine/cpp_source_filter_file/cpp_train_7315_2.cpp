#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
int a[N], n;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    int flag = 0;
    for (int i = 1; i <= n; i++)
      if (a[i] >= a[i - 1]) flag = 1;
    if (flag)
      printf("YES\n");
    else
      printf("NO\n");
  }
}
