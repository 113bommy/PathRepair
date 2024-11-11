#include <bits/stdc++.h>
using namespace std;
int main() {
  int a1, a2, a3, a4;
  cin >> a1 >> a2 >> a3 >> a4;
  int s[a1 + a2];
  for (int i = 0; i < a1 + a2; i++) s[i] = 0;
  if ((a3 > a4) || (a3 == a4 && a2 <= a1)) {
    s[0] = 4;
    a1--;
    int i = 1;
    while (a3 != 0 || a4 != 0) {
      if (a3 != 0 && s[i - 1] == 4)
        s[i] = 7, a3--, a2--;
      else {
        if (a4 != 0 && s[i - 1] == 7) {
          s[i] = 4;
          a4--;
          a1--;
        } else {
          cout << -1;
          return 0;
        }
      }
      i++;
    }
    if (a2 < 0 || a1 < 0) {
      cout << -1;
      return 0;
    }
    if (i == 1 && a2 != 0) {
      cout << -1;
      return 0;
    }
    for (int j = 0; j < i; j++) {
      cout << s[j];
      while ((s[j] == 4 && a1 != 0)) {
        cout << 4;
        a1--;
      }
      while ((s[j] == 7 && a2 != 0) && (j + 2 >= i)) {
        cout << 7;
        a2--;
      }
    }
  } else {
    s[0] = 7;
    a2--;
    int i = 1;
    while (a3 != 0 || a4 != 0) {
      if (a3 != 0 && s[i - 1] == 4)
        s[i] = 7, a3--, a2--;
      else {
        if (a4 != 0 && s[i - 1] == 7) {
          s[i] = 4;
          a4--;
          a1--;
        } else {
          cout << -1;
          return 0;
        }
      }
      i++;
    }
    if (a2 < 0 || a1 < 0) {
      cout << -1;
      return 0;
    }
    if (i == 1 && a1 != 0) {
      cout << -1;
      return 0;
    }
    for (int j = 0; j < i; j++) {
      cout << s[j];
      while ((s[j] == 4 && a1 != 0)) {
        cout << 4;
        a1--;
      }
      while ((s[j] == 7 && a2 != 0) && (j + 2 >= i)) {
        cout << 7;
        a2--;
      }
    }
  }
}
