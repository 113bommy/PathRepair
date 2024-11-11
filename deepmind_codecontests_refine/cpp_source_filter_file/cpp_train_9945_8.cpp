#include <bits/stdc++.h>
const int INF = 1 << 29;
void cycle(std::string &s, bool dir) {
  int xpos = -1;
  for (int i = 0; i < 4; i++)
    if (s[i] == 'X') xpos = i;
  if (dir) {
    if (xpos == 0)
      std::swap(s[0], s[1]);
    else if (xpos == 1)
      std::swap(s[1], s[3]);
    else if (xpos == 3)
      std::swap(s[3], s[2]);
    else if (xpos == 2)
      std::swap(s[2], s[0]);
  } else {
    if (xpos == 0)
      std::swap(s[0], s[2]);
    else if (xpos == 1)
      std::swap(s[1], s[0]);
    else if (xpos == 3)
      std::swap(s[3], s[1]);
    else if (xpos == 2)
      std::swap(s[2], s[3]);
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  ;
  std::string r1, r2, r3, r4;
  std::cin >> r1 >> r2 >> r3 >> r4;
  std::string f = r1 + r2, s = r3 + r4;
  bool dir = true;
  for (int i = 0; i < 4; i++) {
    if (f == s) return std::cout << "YES", 0;
    cycle(f, true);
  }
  f = r1 + r2;
  dir = false;
  for (int i = 0; i < 4; i++) {
    if (f == s) return std::cout << "YES", 0;
    cycle(f, dir);
  }
  return std::cout << "NO", 0;
  return 0;
}
