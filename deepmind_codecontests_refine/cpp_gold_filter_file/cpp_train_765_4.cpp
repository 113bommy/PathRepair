#include <bits/stdc++.h>
using namespace std;
const double PI = 2.0 * acos(0.0);
const double EPS = 1e-6;
char dict[55][25];
int n;
bool check(char str[]) {
  int len = strlen(str);
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < strlen(dict[i]) - len + 1; k++)
      if (strncmp(&dict[i][k], str, len) == 0) return false;
  }
  return true;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%s", dict[i]);
  char str[25];
  str[0] = 'a' - 1;
  int ptr = 1;
  str[ptr] = NULL;
  while (true) {
    int k = ptr - 1;
    for (; k >= 0; k--) {
      str[k]++;
      if (str[k] > 'z')
        str[k] = 'a';
      else
        break;
    }
    if (k < 0) {
      str[ptr++] = 'a';
      str[ptr] = NULL;
    }
    if (check(str)) {
      puts(str);
      break;
    }
  }
  return 0;
}
