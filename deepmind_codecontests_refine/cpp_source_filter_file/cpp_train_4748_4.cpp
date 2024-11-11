#include <bits/stdc++.h>
int main() {
  int n, a, b;
  std::cin >> n >> a >> b;
  int tmp;
  int denied = 0;
  int halves = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> tmp;
    switch (tmp) {
      case 2:
        if (b == 0)
          denied++;
        else
          b--;
        break;
      case 1:
        if (a == 0 && b == 0 && halves == 0)
          denied++;
        else if (a == 0 && b == 0)
          halves--;
        else if (a == 0) {
          halves++;
          b--;
        } else
          a--;
        break;
    }
  }
  std::cout << denied << "\n";
  return 0;
}
