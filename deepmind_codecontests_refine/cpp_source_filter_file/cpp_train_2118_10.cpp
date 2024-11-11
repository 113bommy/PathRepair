#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
int b, d;
int check2(int d) {
  long long a = b;
  for (int res = 1; res <= 6; ++res) {
    if (a % d == 0) return res;
    a = a * b;
  }
  return 0;
}
bool check3(int d) { return (b - 1) % d == 0; }
bool check11(int d) { return (b + 1) % d == 0; }
bool isPrime(int n) {
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return n > 1;
}
bool check6() {
  for (int i = 2; i <= d; i++)
    if (isPrime(i))
      if (d % i == 0) {
        int need = i;
        while (b % (need * i) == 0) {
          need *= i;
        }
        if (!check2(need) && !check3(need) && !check11(need)) return false;
      }
  return true;
}
int main() {
  while (cin >> b >> d) {
    if (check2(d))
      printf("2-type\n%d\n", check2(d));
    else if (check3(d))
      puts("3-type");
    else if (check11(d))
      puts("11-type");
    else if (check6())
      puts("6-type");
    else
      puts("7-type");
  }
  return 0;
}
