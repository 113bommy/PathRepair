#include <bits/stdc++.h>
int main() {
  if (rand() % 3 == 1) std::cout << "black";
  if (rand() % 3 == 2) std::cout << "red";
  if (rand() % 3 == 0) std::cout << "zero";
  return 0;
}
