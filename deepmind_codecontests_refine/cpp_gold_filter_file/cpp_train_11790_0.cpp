#include <bits/stdc++.h>
using namespace std;
int data[100010];
int prince[100010];
int main() {
  int t;
  int a, b, c, flag = 0;
  cin >> t;
  int n;
  for (int i = 1; i <= t; i++) {
    scanf("%d", &n);
    for (int j = 0; j <= n; j++) {
      data[j] = 0;
      prince[j] = 0;
    }
    flag = 0;
    for (int j = 1; j <= n; j++) {
      scanf("%d", &a);
      c = 0;
      for (int k = 1; k <= a; k++) {
        scanf("%d", &b);
        if ((c == 0) && (data[b] == 0)) {
          data[b] = 1;
          c = 1;
        }
      }
      if (c == 0) {
        prince[j] = 1;
        if (!flag) flag = j;
      }
    }
    if (flag == 0) {
      printf("OPTIMAL\n");
    } else {
      printf("IMPROVE\n");
      printf("%d ", flag);
      for (int j = 1; j <= n; j++)
        if (data[j] == 0) {
          cout << j << endl;
          break;
        }
    }
  }
}
