#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 100000;
  scanf("%d", &n);
  getchar();
  for (int p = 0; p < n; ++p) {
    for (int i = 0; i < 4; ++i) getchar();
    int ar[9];
    int l = 0;
    char c;
    unsigned long long int ans = 1989;
    long long int chis = 0;
    while ((c = getchar()) != '\n') {
      ar[l++] = c - '0';
      chis = chis * 10 + c - '0';
    }
    if (l == 1 && chis == 9) {
      cout << ans << endl;
      continue;
    }
    if (l == 1 && chis < 10) {
      cout << ans + 1 + chis << endl;
      continue;
    }
    if (l == 2 && chis == 99) {
      cout << 1999 << endl;
      continue;
    }
    if (l == 3 && !ar[0] && chis != 99) ans += 1000;
    if (l == 4) {
      if (chis < 3099) cout << "1";
      for (int i = 0; i < l; ++i) {
        cout << ar[i];
      }
      cout << endl;
      continue;
    }
    if (l == 5) {
      if (chis < 13099) cout << "1";
      for (int i = 0; i < l; ++i) {
        cout << ar[i];
      }
      cout << endl;
      continue;
    }
    if (l == 6) {
      if (chis < 113099) cout << "1";
      for (int i = 0; i < l; ++i) {
        cout << ar[i];
      }
      cout << endl;
      continue;
    }
    if (l == 7) {
      if (chis < 1113099) cout << "1";
      for (int i = 0; i < l; ++i) {
        cout << ar[i];
      }
      cout << endl;
      continue;
    }
    if (l == 8) {
      if (chis < 113099) cout << "1";
      for (int i = 0; i < l; ++i) {
        cout << ar[i];
      }
      cout << endl;
      continue;
    }
    if (l == 9) {
      if (chis < 113099) cout << "1";
      for (int i = 0; i < l; ++i) {
        cout << ar[i];
      }
      cout << endl;
      continue;
    }
    if (l == 2 || l == 3) {
      long long int po = 1;
      for (int i = l - 1; i >= 0; --i) {
        ans += po * (1 + ar[i]);
        po *= 10;
      }
      if (l == 3) ans -= 100;
      cout << ans << endl;
      continue;
    }
  }
}
