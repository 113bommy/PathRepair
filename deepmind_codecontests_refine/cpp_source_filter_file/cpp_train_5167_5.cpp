#include <bits/stdc++.h>
int main() {
  char c;
  int i, n = 0, x, min = 100000, k_dom[26][2] = {0};
  while (scanf("%c", &c) && c != '\n' && ++n) {
    if ((x = n - k_dom[c - 'a'][1]) > k_dom[c - 'a'][0]) {
      k_dom[c - 'a'][0] = x;
    }
    k_dom[c - 'a'][1] = n;
  }
  for (i = 0; i < 26; i++) {
    if ((x = n - k_dom[i][1]) > k_dom[i][0]) k_dom[i][0] = x;
    if (k_dom[i][0] < min) min = k_dom[i][0];
  }
  printf("%d", min);
}
