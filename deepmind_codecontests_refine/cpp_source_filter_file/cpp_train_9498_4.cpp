#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned short last = 0;
  unsigned short x, y;
  char data[101];
  fgets(data, 101, stdin);
  data[strlen(data) - 1] = '\0';
  for (int i = 0; i <= strlen(data); i++) {
    if (i) {
      last = (data[i - 1] & 0b10000000) >> 7 | (data[i - 1] & 0b1000000) >> 5 |
             (data[i - 1] & 0b100000) >> 3 | (data[i - 1] & 0b10000) >> 1 |
             (data[i - 1] & 0b1000) << 1 | (data[i - 1] & 0b100) << 3 |
             (data[i - 1] & 0b10) << 5 | (data[i - 1] & 0b1) << 7;
      ;
    } else
      last = 0;
    x = 0;
    y = (unsigned short)data[i];
    x = (y & 0b10000000) >> 7 | (y & 0b1000000) >> 5 | (y & 0b100000) >> 3 |
        (y & 0b10000) >> 1 | (y & 0b1000) << 1 | (y & 0b100) << 3 |
        (y & 0b10) << 5 | (y & 0b1) << 7;
    ;
    printf("%hu\n", (unsigned short)(last - x) % 256);
  }
}
