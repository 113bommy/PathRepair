#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  std::string s; std::cin >> s;
  int da[4], db[4];
  da[0] = db[0] = da[3] = -1;
  da[1] = db[1] = db[3] = 1;
  int a = 0, b = 0, m = 0, M = 0;
  int c0 = a-b, c1 = c0 + 1, c2 = c0 + 1, c3 = c0 + 2;
  for(auto c: s) {
    a += da[c&3]; if(a < 0) { a += 1; m ^= 1; }
    b += db[c&3]; if(b > 0) { b -= 1; M ^= 1; }
    c0 = std::max(c0, a-b+m+M);
    c1 = std::max(c1, a-b+m+(M^1));
    c2 = std::max(c2, a-b+(m^1)+M);
    c3 = std::max(c3, a-b+(m^1)+(M^1));
  }
  fin(std::min(std::min(c0, c1), std::min(c2, c3)));
  return 0;
}
