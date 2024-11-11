#include <bits/stdc++.h>
int main() {
  int t = 0;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    int len = 0;
    scanf("%d", &len);
    char number[len + 1];
    scanf("%d", number);
    number[len] = '\0';
    int spotted = 0;
    char result1[len + 1];
    char result2[len + 1];
    for (int j = 0; j < len; j++) {
      if (spotted == 1) {
        if (number[j] == '0') {
          result1[j] = '0';
          result2[j] = '0';
        } else if (number[j] == '1') {
          result1[j] = '0';
          result2[j] = '1';
        } else {
          result1[j] = '0';
          result2[j] = '2';
        }
      } else {
        if (number[j] == '0') {
          result1[j] = '0';
          result2[j] = '0';
        } else if (number[j] == '1') {
          spotted = 1;
          result1[j] = '1';
          result2[j] = '0';
        } else {
          result1[j] = '1';
          result2[j] = '1';
        }
      }
    }
    result1[len] = '\0';
    result2[len] = '\0';
    printf("%s\n%s\n", result1, result2);
  }
}
