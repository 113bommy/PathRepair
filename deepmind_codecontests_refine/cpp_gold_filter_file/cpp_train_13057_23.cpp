#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int ans = 0;
    char s[13];
    scanf("%s", s);
    int arr[6] = {12, 6, 4, 3, 2, 1};
    int check[6] = {0};
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < arr[i]; j++) {
        int k = j;
        while (k < 12) {
          if (s[k] != 'X') break;
          k += arr[i];
        }
        if (k >= 12) {
          ans++;
          check[i] = 1;
          break;
        }
      }
    }
    printf("%d ", ans);
    for (int i = 0; i < 6; i++) {
      if (check[i] == 1) printf("%dx%d ", 12 / arr[i], arr[i]);
    }
    printf("\n");
  }
  return 0;
}
