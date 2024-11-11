#include <bits/stdc++.h>
void sort(char string[], int len);
int main() {
  int tc;
  scanf("%d", &tc);
  for (int i = 0; i < tc; i++) {
    int len;
    scanf("%d", &len);
    char string[len];
    scanf("%s", &string);
    char dup[len];
    int l = 0;
    while (l < len) {
      dup[l] = string[l];
      l++;
    }
    sort(string, len);
    int count = 0;
    for (int i = 0; i < len; i++) {
      if (dup[i] != string[i]) {
        count++;
      }
    }
    printf("%d\n", count);
  }
  return 0;
}
void sort(char string[], int len) {
  for (int i = 0; i < len - 1; i++) {
    for (int j = 0; j < len - 1 - i; j++) {
      if (string[j] > string[j + 1]) {
        int temp;
        temp = string[j];
        string[j] = string[j + 1];
        string[j + 1] = temp;
      }
    }
  }
}
