#include <bits/stdc++.h>
using namespace std;
bool isprm(long long n) {
  if (n == 1) return 0;
  long long i;
  for (i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return 0;
  return 1;
}
int main() {
  long long n, i, j, k;
  cin >> n;
  if (n == 2) {
    cout << 1 << ' ' << 1;
    return 0;
  }
  if ((n * (n + 1) / 2) % 2 == 0) {
    for (i = 2;; i++)
      if (isprm(i) && isprm(n * (n + 1) / 2 - i)) break;
    long long mas[n];
    for (j = 0; j < n; j++) mas[j] = 0;
    for (j = n - 1; i > 0; j--)
      if ((j + 1) <= i) {
        mas[j] = 1;
        i -= (j + 1);
      }
    for (i = 0; i < n; i++) cout << 2 - mas[i] << ' ';
  } else {
    if (isprm(n * (n + 1) / 2 - 2)) {
      for (i = 0; i < n; i++)
        if (i != 1)
          cout << 1 << ' ';
        else
          cout << 2 << ' ';
    } else {
      for (i = 2;; i++)
        if (isprm(i) && isprm(n * (n + 1) / 2 - i - 3)) break;
      int mas[n];
      for (j = 0; j < n; j++) mas[j] = 0;
      mas[2] = 1;
      for (j = n - 1; i > 0; j--)
        if (j != 2 && (j + 1) <= i) {
          i -= (j + 1);
          mas[j] = 2;
        }
      for (i = 0; i < n; i++) cout << 3 - mas[i] << ' ';
    }
  }
  return 0;
}
