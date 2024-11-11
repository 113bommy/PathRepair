#include <bits/stdc++.h>
int main(int argc, const char* argv[]) {
  std::vector<std::string> items;
  for (int i = 0; i < 8; ++i) {
    std::string line;
    std::cin >> line;
    items.push_back(line);
  }
  int bAnswer = 10;
  int bMin = 10;
  bool bFound = false;
  for (int column = 0; column < 8; ++column) {
    for (int row = 0; row < 8; ++row) {
      if (items[row][column] == 'B') {
        bMin = std::min(bMin, 7 - row);
        bFound = true;
      } else if (items[row][column] == 'W' && bFound) {
        bMin = 10;
        bFound = false;
      }
    }
    if (bFound) {
      bAnswer = std::min(bAnswer, bMin);
    }
    bFound = false;
  }
  int aAnswer = 10;
  int aMin = 10;
  int aFound = false;
  for (int column = 0; column < 8; ++column) {
    for (int row = 7; row >= 0; --row) {
      if (items[row][column] == 'W') {
        aMin = std::min(aMin, row);
        aFound = true;
      } else if (items[row][column] == 'B' && aFound) {
        aMin = 10;
        aFound = false;
      }
    }
    if (aFound) {
      aAnswer = std::min(aAnswer, aMin);
    }
    aFound = false;
  }
  if (aAnswer <= bAnswer) {
    std::cout << "A" << std::endl;
  } else {
    std::cout << "B" << std::endl;
  }
  return 0;
}
