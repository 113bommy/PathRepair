#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int r, g, b, result = 0;
  cin >> r >> g >> b;
  if (r == g && g == b) {
    printf("%lld", g);
  } else {
    long long int result = 0;
    if (r % 3 == 0 && r != 0) {
      result += (r / 3) - 1;
      r = 3;
    } else {
      result += (r / 3);
      r = r % 3;
    }
    if (g % 3 == 0 && g != 0) {
      result += (g / 3) - 1;
      g = 3;
    } else {
      result += (g / 3);
      g = g % 3;
    }
    if (b % 3 == 0 && b != 0) {
      result += (b / 3) - 1;
      b = 3;
    } else {
      result += (b / 3);
      b = b % 3;
    }
    if (r >= 0 && r < 3 && b % 3 == 0 && g % 3 == 0) {
      result += (b / 3) + (g / 3);
      printf("%lld", result);
    } else if (b < 3 && b >= 0 && r % 3 == 0 && g % 3 == 0) {
      result += (r / 3) + (g / 3);
      printf("%lld", result);
    } else if (g >= 0 && g < 3 && r % 3 == 0 && b % 3 == 0) {
      result += (r / 3) + (b / 3);
      printf("%lld", result);
    } else {
      long long int temp;
      temp = min(r, g);
      temp = min(temp, b);
      result += temp;
      printf("%lld", result);
    }
  }
}
