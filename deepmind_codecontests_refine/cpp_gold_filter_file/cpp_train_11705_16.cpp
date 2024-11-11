#include <bits/stdc++.h>
using namespace std;
int maxi(int x, int y) { return (x > y) ? x : y; }
int mini(int x, int y) { return (x > y) ? y : x; }
long long int power(long long int a, long long int b) {
  int temp = 1;
  if (b == 0) return 1;
  while (b > 0) {
    if (b % 2 != 0) {
      temp = temp * a;
      b = b - 1;
    } else {
      a = a * a;
      b = b / 2;
    }
  }
  return temp;
}
int main() {
  double a, b;
  cin >> a >> b;
  for (int i = 1; i < a; i++) {
    double temp = sqrt(a * a - i * i);
    if (ceil(temp) == floor(temp)) {
      for (int j = -1; j > -b; j--) {
        double temp2 = sqrt(b * b - j * j);
        if (ceil(temp2) == floor(temp2)) {
          if (i != abs(j) && (power(i - abs(j), 2) + power(temp + temp2, 2)) ==
                                 (a * a + b * b)) {
            printf("YES\n");
            printf("0 0\n");
            cout << i << " " << temp << endl;
            cout << abs(j) << " " << -temp2 << endl;
            return 0;
          }
        }
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
