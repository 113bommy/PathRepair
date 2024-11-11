#include <bits/stdc++.h>
using namespace std;
bool cf(const int &a, const int &b) { return a > b; }
int n, base;
bool tulis;
int angka[100005];
int temp, count_;
int main() {
  tulis = false;
  memset(angka, 0, sizeof(angka));
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", &angka[i]);
  sort(angka + 1, angka + 1 + n, cf);
  base = 1;
  while (base <= angka[1]) base = base * 2;
  base = base / 2;
  while (base > 0) {
    for (int j = 1; j <= n; j++)
      if ((angka[j] & base) != 0) {
        count_ = 1;
        temp = angka[j];
        for (int i = j + 1; i <= n; i++)
          if ((angka[i] & base) != 0) {
            temp = (temp & angka[i]);
            count_++;
          }
        if (temp % base) {
          tulis = true;
          cout << count_ << endl;
          cout << angka[j];
          for (int i = j + 1; i <= n; i++)
            if ((angka[i] & base) != 0) printf(" %d", angka[i]);
          printf("\n");
        }
        break;
      }
    base = base / 2;
    if (tulis) break;
  }
  if ((not tulis) && (n != 0)) cout << "-1" << endl;
  return 0;
}
