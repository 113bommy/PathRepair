#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[100], b[100], c[100];
  scanf("%s%s", a, b);
  int j = 0;
  for (int i = strlen(b) - 1; i >= 0; i--) {
    c[j++] = b[i];
  }
  int flag = 0;
  for (j = 0; j < strlen(a); j++) {
    if (a[j] != c[j]) {
      flag = 1;
      break;
    }
  }
  if (flag == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
