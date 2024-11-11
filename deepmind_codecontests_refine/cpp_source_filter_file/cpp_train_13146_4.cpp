#include <bits/stdc++.h>
using namespace std;
int mas[3];
int main() {
  long long min = 0x7fffffffffffffff;
  long long max = 0;
  int n;
  cin >> n;
  for (long long a = 1; a * a * a <= n; ++a) {
    if (n % a == 0) {
      for (long long b = a; b * b <= n / a; ++b)
        if ((n / a) % b == 0) {
          long long c = n / a / b;
          mas[0] = a;
          mas[1] = b;
          mas[2] = c;
          sort(mas, mas + 3);
          do {
            if ((mas[0] + 1) * (mas[1] + 2) * (mas[2] + 2) < min) {
              min = (mas[0] + 1) * (mas[1] + 2) * (mas[2] + 2);
            }
            if ((mas[0] + 1) * (mas[1] + 2) * (mas[2] + 2) > max) {
              max = (mas[0] + 1) * (mas[1] + 2) * (mas[2] + 2);
            }
          } while (next_permutation(mas, mas + 3));
        }
    }
  }
  cout << min - n << " " << max - n;
  return 0;
}
