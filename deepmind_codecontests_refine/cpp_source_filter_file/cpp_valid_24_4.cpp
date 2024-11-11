#include <bits/stdc++.h>
using namespace std;
class ColoredDebugCout {
 private:
  string color_code;

 public:
  ColoredDebugCout(string color_code) { this->color_code = color_code; }
  template <class T>
  void operator<<(T str) {
    cout << "\033[1;" << this->color_code << "m" << str << "\033[0m";
  }
};
auto& mcout{cout};
auto& ycout{cout};
long long s(long long x) {
  long long digit_sum{0};
  while (x > 0) {
    digit_sum += x % 10;
    x /= 10;
  }
  return digit_sum;
}
void answer1() {
  long long n;
  cin >> n;
  ycout << n / 10;
}
void answer2() {}
void answer3() {}
void answer4() {}
void answer5() {}
void answer6() {}
void answer7() {}
void answer8() {}
void answer9() {}
int main() {
  long long t;
  cin >> t;
  for (long long test{0}; test < t; ++test) {
    answer1();
    ycout << '\n';
  }
}
