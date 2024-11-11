#include <bits/stdc++.h>
using namespace std;
const int MN = 210;
const int INF = (1 << 30);
int n;
char s[MN];
int main() {
  scanf("%d %s", &n, s);
  for (int k = 1; k < n; k++) {
    for (int i = 0; i < n; i++) {
      bool flag = false;
      for (int j = 0; j < 5; j++) {
        if (i + k * j > n || s[i + k * j] == '.') {
          flag = true;
        }
      }
      if (!flag) {
        printf("yes\n");
        return 0;
      }
    }
  }
  printf("no\n");
  return 0;
}
