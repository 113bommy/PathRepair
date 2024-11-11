#include <bits/stdc++.h>
int main() {
  int i = 0, j = 0, counter = 0, no_input, new_size;
  scanf("%d", &no_input);
  int input[no_input];
  for (i = 0; i < no_input; i++) {
    scanf("%d", &input[i]);
  }
  for (i = no_input; i > -1; i--) {
    for (j = i - 1; j > -1; j--) {
      if (input[i] == input[j] && input[j] != -1) {
        counter++;
        input[j] = -1;
      }
    }
  }
  new_size = no_input - counter;
  int new_input[new_size];
  printf("%d\n", counter);
  for (i = 0; i < no_input; i++) {
    if (input[i] != -1) {
      new_input[j] = input[i];
      printf("%d ", new_input[j]);
      j++;
    }
  }
  return 0;
}
