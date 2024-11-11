#include <bits/stdc++.h>
int main() {
  size_t childNumber, time;
  std::string queue;
  std::cin >> childNumber >> time;
  std::cin >> queue;
  for (size_t i = 0; i < time; i++) {
    for (size_t j = 0; j < childNumber - 1; j++) {
      if (queue[j] == 'B' && queue[j + 1] == 'G') {
        queue[j] = 'G';
        queue[j + 1] = 'B';
        j += 1;
      }
    }
  }
  std::cout << queue << std::endl;
  return 0;
}
