#include <bits/stdc++.h>
using namespace std;
char c[210];
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    getchar();
    int a[210] = {0};
    int t = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%c", &c[i]);
      if (isupper(c[i]))
        ++a[t];
      else if (c[i] == ' ')
        ++t;
    }
    printf("%d\n", *(max_element(a, a + t)));
  }
  return 0;
}
