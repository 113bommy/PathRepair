#include <bits/stdc++.h>
using namespace std;
bool Check(int four, int two, int one, int tmp) {
  while (tmp >= 4 && four) tmp -= 4, --four;
  while (tmp >= 2 && two) tmp -= 2, --two;
  while (tmp >= 1 && one) tmp -= 1, --one;
  return tmp == 0;
}
int main() {
  int x;
  cin >> x;
  if (x == 1) return puts("1"), 0;
  for (register int i = 3; 666; i += 2) {
    int tmp = (i + 1) / 2;
    if (tmp & 1) {
      if (Check((tmp - 1) * (tmp - 1) / 2, (tmp - 1) * 2 / 2, 1, x))
        return cout << i << endl, 0;
    } else {
      if (Check((tmp - 1) * (tmp - 1) / 2 + 1, (tmp - 1) / 2 * 2, 1, x) ||
          Check((tmp - 1) * (tmp - 1) / 2, ((tmp - 1) / 2 + 1) * 2, 0, x))
        return cout << i << endl, 0;
    }
  }
  return 0;
}
