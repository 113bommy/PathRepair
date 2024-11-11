#include <iostream>

int main() {
  int a,b,c,tmp;
  std::cin >> a >> b >> c;
  tmp=b*2+c;
  std::cout << ((tmp%4==0) ? "YES" : "NO") << '\n';
  return 0;
}
