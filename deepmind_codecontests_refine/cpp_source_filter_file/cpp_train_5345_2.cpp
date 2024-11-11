#include <bits/stdc++.h>
using namespace std;
char a[100009], b[100009];
int x[2], j = 0;
int main() {
  scanf("%s", a);
  scanf("%s", b);
  if (strlen(a) != strlen(b)) {
    printf("NO");
    return 0;
  }
  for (int i = 0; i < strlen(a); i++) {
    if (a[i] != b[i]) {
      x[j] = i;
      j++;
      if (j > 2) {
        printf("NO");
        return 0;
      }
    }
  }
  if (j == 1) printf("NO");
  if (int(a[x[0]]) == int(b[x[1]]) && int(a[x[1]]) == int(b[x[0]]))
    printf("YES");
  else
    printf("NO");
  return 0;
}
