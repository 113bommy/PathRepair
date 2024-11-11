#include <bits/stdc++.h>
using namespace std;
int a[110];
int main() {
  int n;
  scanf("%d", &n);
  int temp = 3, flag = 0, temp1 = 1, temp2 = 2;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == temp) {
      flag = 1;
      break;
    } else {
      if (a[i] == temp1) {
        int tt = temp;
        temp = temp2;
        temp2 = tt;
      } else {
        int tt = temp;
        temp = temp1;
        temp1 = flag;
      }
    }
  }
  if (flag == 0) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}
