#include <bits/stdc++.h>
long int* a = new long int[30];
void bin_cout(long int b_1, long int b_2) {
  for (int i = 29; i > -1; i--) {
    std::cout << (bool)(b_1 & a[i]);
  }
  std::cout << " ";
  for (int i = 29; i > -1; i--) {
    std::cout << (bool)(b_2 & a[i]);
  }
  std::cout << std::endl;
};
int main() {
  for (int i = -1; i <= 28; i++) {
    a[i + 1] = pow(2, i + 1);
  }
  long int c, d, l = pow(2, 30) - 1;
  long int s_a = 0, s_b = 0;
  int answ1, answ2, answ3 = -2;
  for (int i = 29; i >= 0; i--) {
    std::cout << "? " << a[i] + s_a << " " << s_b << std::endl;
    fflush(stdout);
    std::cin >> answ1;
    std::cout << "? " << s_a << " " << a[i] + s_b << std::endl;
    fflush(stdout);
    std::cin >> answ2;
    if (answ1 != answ2) {
      if (answ1 < answ2) {
        s_a += a[i];
        s_b += a[i];
      }
    } else {
      if (answ3 = -2) {
        std::cout << "? " << (l & s_a) << " " << (l & s_b) << std::endl;
        fflush(stdout);
        std::cin >> answ3;
      }
      switch (answ3) {
        case (1):
          s_a += a[i];
          answ3 = answ1;
          break;
        case (-1):
          s_b += a[i];
          answ3 = answ1;
          break;
      }
    }
  }
  std::cout << "! " << s_a << " " << s_b << std::endl;
  return 0;
}
