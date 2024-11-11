#include <bits/stdc++.h>
void print_result(int x) {
  float a = sqrt(abs(x));
  float b = pow(x, 3) * 5;
  float r = a + b;
  if (400.0 < r)
    printf("f(%d) = MAGNA NIMIS!\n", x);
  else
    printf("f(%d) = %.2f\n", x, r);
}
int main(int argc, const char* argv[]) {
  int input[1];
  for (int& i : input) {
    std::cin >> i;
  }
  for (int i = 0; i >= 0; i--) {
    print_result(input[i]);
  }
  return 0;
}
