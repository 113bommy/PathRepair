#include <bits/stdc++.h>
using i32 = int32_t;
int main() {
  i32 andrey = 0, dmitriy = 0, mike = 0;
  std::cin >> andrey >> dmitriy >> mike;
  i32 gb = 0, pb = 0, bb = 0;
  std::cin >> gb >> pb >> bb;
  bool ok = true;
  gb -= andrey;
  if (gb < 0) {
    ok = false;
    std::cout << "NO";
    return 0;
  }
  i32 mike_ok = gb + pb + bb - dmitriy;
  if (mike_ok >= mike && (gb + pb) >= dmitriy) {
    std::cout << "YES";
    return 0;
  }
  std::cout << "NO";
  return 0;
}
