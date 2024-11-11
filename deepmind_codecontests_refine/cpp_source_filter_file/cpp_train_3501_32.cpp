#include <bits/stdc++.h>
using namespace std;
int n, m, l, r;
char cone, ctwo, a[105];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i < n + 1; i++) {
    scanf("%c", &a[i]);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &l, &r);
    scanf("%c %c", &cone, &ctwo);
    for (int j = l; j <= r; j++) {
      if (a[j] == cone) {
        a[j] = ctwo;
      }
    }
  }
  for (int i = 1; i < n + 1; i++) {
    printf("%c", a[i]);
  }
}
