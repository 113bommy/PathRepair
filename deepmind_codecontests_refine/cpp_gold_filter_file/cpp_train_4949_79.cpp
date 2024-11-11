#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int x, fg = 0;
  char a[110], b[110];
  scanf("%s %s", &a, &b);
  if (strlen(a) == strlen(b)) {
    fg = 1;
    for (int i = 0; i < strlen(a); i++) {
      if (a[i] != b[i]) {
        fg = 0;
        break;
      }
    }
  } else
    fg = 0;
  if (fg == 1) {
    cout << a << endl;
  } else
    cout << "1\n";
  return 0;
}
