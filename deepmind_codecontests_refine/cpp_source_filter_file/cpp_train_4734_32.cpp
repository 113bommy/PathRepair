#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[110];
  int l, i;
  scanf("%[^\n]", a);
  l = strlen(a);
  for (i = l - 2; i >= 0; i--) {
    if ((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z')) {
      if (a[i] == 'A' || a[i] == 'a' || a[i] == 'E' || a[i] == 'e' ||
          a[i] == 'I' || a[i] == 'i' || a[i] == 'O' || a[i] == 'o' ||
          a[i] == 'U' || a[i] == 'u' || a[i] == 'Y' || a[i] == 'y') {
        cout << "Yes";
        return 0;
      } else {
        cout << "No";
        return 0;
      }
    }
  }
  return 0;
}
