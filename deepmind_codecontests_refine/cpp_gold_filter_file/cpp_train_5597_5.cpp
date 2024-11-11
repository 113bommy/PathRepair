#include <bits/stdc++.h>
using namespace std;
char a[1000], b[10];
int k = 0, x, y;
int main() {
  while (a[k - 1] != '.') {
    scanf("%c", &a[k]);
    k++;
  }
  a[k - 1] = '\0';
  for (int j = 0; j < 1; j++) scanf("%c", &b[j]);
  sscanf(a, "%d", &x);
  y = atoi(b);
  if (a[k - 2] == '9')
    printf("GOTO Vasilisa.");
  else if (y < 5) {
    for (int i = 0; i < k - 2; i++) printf("%c", a[i]);
    printf("%c", int(a[k - 2]));
  } else if (y > 4) {
    for (int i = 0; i < k - 2; i++) printf("%c", a[i]);
    printf("%c", int(a[k - 2]) + 1);
  }
}
