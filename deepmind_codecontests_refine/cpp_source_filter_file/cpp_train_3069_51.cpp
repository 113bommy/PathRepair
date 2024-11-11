#include <bits/stdc++.h>
int main() {
  std::string input;
  int white = 0;
  int black = 0;
  for (int i = 0; i < 8; i++) {
    std::cin >> input;
    for (int i = 0; i < 8; i++) {
      switch (input.at(i)) {
        case 'q':
          black += 9;
          break;
        case 'r':
          black += 5;
          break;
        case 'b':
          black += 3;
          break;
        case 'k':
          black += 3;
          break;
        case 'p':
          black += 1;
          break;
        case 'Q':
          white += 9;
          break;
        case 'R':
          white += 5;
          break;
        case 'B':
          white += 3;
          break;
        case 'K':
          white += 3;
          break;
        case 'P':
          white += 1;
          break;
        default:
          break;
      }
    }
  }
  if (white > black) {
    std::cout << "White";
  } else if (white == black) {
    std::cout << "Draw";
  } else {
    std::cout << "Black";
  }
  return 0;
}
