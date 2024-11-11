#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[204], b[204], flag1[450], flag2[450];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    flag1[a[i]] = 1;
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", &b[i]);
    flag2[b[i]] = 1;
  }
  int flag = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (flag1[a[i] + b[j]] == 0 && flag2[a[i] + b[j]] == 0) {
        printf("%d %d\n", a[i], b[j]);
        flag = 1;
        break;
      }
    }
    if (flag) break;
  }
}
