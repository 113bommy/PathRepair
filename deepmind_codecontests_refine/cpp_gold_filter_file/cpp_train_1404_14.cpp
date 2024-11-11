#include <bits/stdc++.h>
int main(void) {
  int i, days;
  while (std::cin >> i >> days) {
    std::multimap<int, int> lol;
    for (int j = 0; j < i; j++) {
      int temp;
      std::cin >> temp;
      lol.insert(std::make_pair(temp, j));
    }
    int total = 0, count = 0;
    bool used[i];
    for (int j = 0; j < i; j++) used[j] = false;
    for (std::map<int, int>::iterator iter = lol.begin(); iter != lol.end();
         iter++) {
      if (total + iter->first <= days) {
        count++;
        total = total + iter->first;
        used[iter->second] = true;
      } else
        break;
    }
    std::cout << count << '\n';
    if (count != 0) {
      bool first = false;
      for (int j = 0; j < i; j++) {
        if (used[j] == false) continue;
        if (first == false)
          first = true;
        else
          std::cout << ' ';
        std::cout << j + 1;
      }
      std::cout << '\n';
    }
  }
}
