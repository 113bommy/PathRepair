#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  while (fgetc(stdin) != '\n') {
  }
  char previous_action = 0;
  int previous_index = -1;
  int amount_standing = 0;
  for (int i = 0; i < n; ++i) {
    char c = fgetc(stdin);
    switch (c) {
      case 'R':
        amount_standing += i - previous_index - 1;
        previous_index = i;
        previous_action = c;
        break;
      case 'L':
        if (previous_action == 'R') {
          if ((i - previous_index) % 2 == 1) {
            ++amount_standing;
          }
        }
        previous_index = i;
        previous_action = c;
        break;
      case '.':
        break;
    }
  }
  if (previous_action == 'L') {
    amount_standing += n - 1 - previous_index;
  } else if (previous_action == 0) {
    amount_standing = n;
  }
  printf("%d\n", amount_standing);
  return 0;
}
