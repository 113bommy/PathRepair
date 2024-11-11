#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, num = 0;
    cin >> a >> b;
    int k[a + b + 10];
    memset(k, 0, sizeof k);
    if (a % 2 == b % 2) {
      int k1 = min(a, b);
      for (int i = 0; i <= k1; i++) {
        int a1 = (a - i) / 2, b1 = (b - i) / 2;
        if (k[i * 2 + a1 + b1] == 0) k[i * 2 + a1 + b1] = 1, num++;
        if (k[a1 + b1] == 0) k[a1 + b1] = 1, num++;
      }
    } else {
      int ad, x, y, k1;
      x = a - 1, y = b, ad = 0;
      k1 = min(x, y);
      for (int i = 0; i <= k1; i++) {
        int a1 = (a - i) / 2, b1 = (b - i) / 2;
        if (k[i * 2 + a1 + b1] == 0) k[i * 2 + a1 + b1] = 1, num++;
        if (k[a1 + b1] == 0) k[a1 + b1] = 1, num++;
      }
      x = a, y = b - 1, ad = 1;
      k1 = min(x, y);
      for (int i = 0; i <= k1; i++) {
        int a1 = (a - i) / 2, b1 = (b - i) / 2;
        if (k[i * 2 + a1 + b1 + 1] == 0) k[i * 2 + a1 + b1 + 1] = 1, num++;
        if (k[a1 + b1 + 1] == 0) k[a1 + b1 + 1] = 1, num++;
      }
      x = a, y = b - 1, ad = 0;
      k1 = min(x, y);
      for (int i = 0; i <= k1; i++) {
        int a1 = (a - i) / 2, b1 = (b - i) / 2;
        if (k[i * 2 + a1 + b1] == 0) k[i * 2 + a1 + b1] = 1, num++;
        if (k[a1 + b1] == 0) k[a1 + b1] = 1, num++;
      }
      x = a - 1, y = b, ad = 1;
      k1 = min(x, y);
      for (int i = 0; i <= k1; i++) {
        int a1 = (a - i) / 2, b1 = (b - i) / 2;
        if (k[i * 2 + a1 + b1 + 1] == 0) k[i * 2 + a1 + b1 + 1] = 1, num++;
        if (k[a1 + b1 + 1] == 0) k[a1 + b1 + 1] = 1, num++;
      }
    }
    printf("%d\n", num);
    int num1 = 0;
    for (int i = 0; i <= a + b; i++) {
      if (k[i]) {
        num1++;
        if (num1 < num)
          printf("%d ", i);
        else
          cout << i;
      }
    }
    puts("");
  }
}
