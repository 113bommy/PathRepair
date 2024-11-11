#include <bits/stdc++.h>
using namespace std;
int64_t table[360];
int idx;
void init() {
  int i = 0;
  int64_t limit = 1;
  for (i = 0; i < 18; i++) {
    limit *= 10;
  }
  table[1] = 2;
  table[2] = 3;
  for (i = 3; i < 360; i++) {
    int64_t tmp = table[i - 2] + table[i - 1];
    table[i] = tmp;
    if (tmp > limit) {
      idx = i;
      break;
    }
  }
}
int main() {
  init();
  int64_t n;
  cin >> n;
  int i = 0;
  for (i = 2; i < idx; i++) {
    if (n >= table[i] && n < table[i + 1]) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}
