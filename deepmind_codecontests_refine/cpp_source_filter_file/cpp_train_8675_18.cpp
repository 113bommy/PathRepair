#include <bits/stdc++.h>
using namespace std;
char entrada[15];
int main() {
  int n;
  long long x = 1;
  long long y = 1;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", entrada);
    string s = entrada;
    if (s == "UL" || s == "DR") {
      x++;
    } else {
      if (s == "UR" || s == "DL") {
        y++;
      } else {
        x++;
        y++;
      }
    }
  }
  long long resultado = x * y;
  printf("%d\n", resultado);
  return 0;
}
