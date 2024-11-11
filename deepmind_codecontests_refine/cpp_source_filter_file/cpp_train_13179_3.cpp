#include <bits/stdc++.h>
using namespace std;
int ar[55][55];
int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &ar[i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (ar[i][j] != 1) {
        bool check = false;
        for (int k = 0; k < n; k++) {
          for (int l = 0; l < n; l++) {
            if (ar[i][k] + ar[j][l] == ar[i][j]) check = true;
          }
        }
        if (check == false) {
          printf("No\n");
          return 0;
        }
      }
    }
  }
  printf("Yes\n");
  return 0;
}
