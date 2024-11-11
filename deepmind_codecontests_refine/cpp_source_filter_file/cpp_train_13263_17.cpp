#include <bits/stdc++.h>
using namespace std;
int main() {
  bool page[1001];
  char input[1001];
  while (gets(input)) {
    int i, digit = 0;
    memset(page, false, sizeof(page));
    for (i = 0; input[i]; i++) {
      if (input[i] == ',') {
        page[digit] = true;
        digit = 0;
        continue;
      }
      digit = digit * 10 + (input[i] - '0');
    }
    page[digit] = true;
    bool first = true;
    for (i = 0; i < 1001; i++) {
      if (page[i]) {
        if (!first) {
          printf(",");
        } else
          first = false;
        if (page[i + 1] == false) {
          printf("%d", i);
        } else {
          printf("%d-", i);
          for (i++; i < 1001; i++) {
            if (page[i] == false) break;
          }
          printf("%d", i - 1);
        }
      }
    }
    printf("\n");
  }
  return 0;
}
