#include <bits/stdc++.h>
using namespace std;
int main() {
  int w = 0, b = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      char c;
      scanf(" %c", &c);
      if (c == 'p') b += 1;
      if (c == 'P') w += 1;
      if (c == 'r') b += 5;
      if (c == 'R') w += 5;
      if (c == 'b') b += 3;
      if (c == 'B') w += 3;
      if (c == 'k') b += 3;
      if (c == 'K') w += 3;
      if (c == 'q') b += 9;
      if (c == 'Q') w += 9;
    }
  }
  if (w > b) {
    printf("White\n");
  } else if (b > w)
    printf("Black\n");
  else
    printf("Draw\n");
  return 0;
}
