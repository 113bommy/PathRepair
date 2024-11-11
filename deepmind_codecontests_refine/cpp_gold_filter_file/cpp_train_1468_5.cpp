#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  char b[10] = "aouien";
  int i, f = 1, f1, f2, j, len;
  cin >> a;
  len = a.length();
  for (i = 0; i < len - 1; i++) {
    f1 = 0;
    f2 = 0;
    for (j = 0; j < 6; j++) {
      if (a[i] == b[j]) f1 = 1;
    }
    if (!f1) {
      for (j = 0; j < 5; j++) {
        if (a[i + 1] == b[j]) f2 = 1;
      }
    } else
      continue;
    if (!f2) {
      f = 0;
      break;
    }
  }
  f1 = 0;
  for (i = 0; i < 6; i++) {
    if (a[len - 1] == b[i]) f1 = 1;
  }
  if (!f1) f = 0;
  if (f)
    printf("YES");
  else
    printf("NO");
}
