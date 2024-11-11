#include <bits/stdc++.h>
using namespace std;
char str[55], str2[55];
int main() {
  scanf("%s", str);
  int n;
  scanf("%d", &n);
  int len = strlen(str);
  for (int i = 0; i < len; ++i) {
    int aux = str[i];
    if (aux < n + 97) {
      str2[i] = toupper(aux);
    } else {
      str2[i] = tolower(aux);
    }
  }
  printf("%s\n", str2);
  return 0;
}
