#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  char b[110];
  while (~scanf("%d", &a)) {
    getchar();
    int ans = 0;
    gets(b);
    for (int i = 1; i < a; i++) {
      if (b[i] != b[i - 1]) {
        ans++;
        i++;
      }
    }
    printf("%d\n", a - ans);
  }
  return 0;
}
