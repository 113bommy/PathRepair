#include <bits/stdc++.h>
using namespace std;
int n, m;
char str[1010];
int main() {
  char ch[10];
  while (cin >> n >> m) {
    cin >> str;
    int s = m;
    if (s == 1) {
      for (int i = 0; i < n; ++i) {
        printf("PRINT ");
        printf("%c\n", str[i]);
        if (i != n - 1) printf("RIGHT\n");
      }
    } else if (s == n) {
      for (int i = n - 1; i >= 0; --i) {
        printf("PRINT ");
        printf("%c\n", str[i]);
        if (i != 0) printf("LEFT\n");
      }
    } else if (s <= n / 2) {
      for (int i = 1; i < s; ++i) {
        printf("LEFT\n");
      }
      for (int i = 0; i < n; ++i) {
        printf("PRINT ");
        printf("%c\n", str[i]);
        if (i != n - 1) printf("RIGHT\n");
      }
    } else {
      for (int i = s; i < n; ++i) {
        printf("RIGHT\n");
      }
      for (int i = n - 1; i >= 0; --i) {
        printf("PRINT ");
        printf("%c\n", str[i]);
        if (i != 0) printf("LEFT\n");
      }
    }
  }
}
