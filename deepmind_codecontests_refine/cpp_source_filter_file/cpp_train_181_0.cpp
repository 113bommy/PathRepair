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
  da[0] = db[0] = da[3] = -1
  da[1] = db[1] = db[3] = 1;
  int a0 = 0, a1 = 1, b0 = 0, b1 = -1;
  int c0 = a0-b0, c1 = a0-b1, c2 = a1-b0, c3 = a1-b1;
  for(auto c: s) {
    a0 += da[c&3]; if(a0 < 0) a0 += 2;
    a1 += da[c&3]; if(a1 < 0) a1 += 2;
    b0 += db[c&3]; if(b0 > 0) b0 -= 2;
    b1 += db[c&3]; if(b1 > 0) b1 -= 2;
    c0 = std::max(c0, a0-b0);
    c1 = std::max(c1, a0-b1);
    c2 = std::max(c2, a1-b0);
    c3 = std::max(c3, a1-b1);
  }
  fin(std::min(std::min(c0, c1), std::min(c2, c3)));
  return 0;
}
