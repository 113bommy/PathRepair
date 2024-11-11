#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> numeros;
  string str4 = "2 * 3 = 6\n6 * 4 = 24\n24 * 1 = 24";
  string str5 = "3 - 1 = 2\n2 + 2 = 4\n4 * 5 = 20\n20 + 4 = 24";
  int n;
  scanf("%d", &n);
  if (n < 4)
    printf("NO");
  else {
    printf("YES\n");
    if (n % 2 != 0) {
      cout << str5;
      for (int i = 6; i <= n; i += 2) {
        printf("\n%d - %d = 1", (i + 1), i);
      }
      for (int i = 0; i < ((n - 5) / 2) - 1; i++) {
        printf("\n1 * 1 = 1");
      }
      if (n > 4) printf("\n24 * 1 = 24");
    } else if (n % 2 == 0) {
      cout << str4;
      for (int i = 5; i <= n; i += 2) {
        printf("\n%d - %d = 1", (i + 1), i);
      }
      for (int i = 0; i < ((n - 4) / 2) - 1; i++) {
        printf("\n1 * 1 = 1");
      }
      if (n > 4) printf("\n24 * 1 = 24");
    }
  }
  return 0;
}
