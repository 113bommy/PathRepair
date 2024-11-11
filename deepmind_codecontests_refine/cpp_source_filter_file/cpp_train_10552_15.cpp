#include <bits/stdc++.h>
using namespace std;
char input[105];
int main() {
  scanf("%s", &input);
  for (int len = strlen(input) - 1; len >= 2; len--) {
    for (int i = 0; i <= strlen(input) - len; i++) {
      int right = i + len - 1;
      string a = "";
      for (int j = i; j <= right; j++) {
        a += input[j];
      }
      for (int j = i + 1; j <= strlen(input) - len; j++) {
        string b = "";
        for (int k = j; k < j + len; k++) {
          b += input[k];
        }
        if (a == b) {
          printf("%d\n", len);
          return 0;
        }
      }
    }
  }
  printf("0\n");
  return 0;
}
