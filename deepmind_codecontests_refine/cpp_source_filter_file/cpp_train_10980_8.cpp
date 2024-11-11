#include <bits/stdc++.h>
int main() {
  char str[200000] = {0};
  int n, i = 0, value = 0, arr[27] = {0}, key = 0;
  scanf("%d", &n);
  scanf("%s", str);
  while (str[i] && i <= 100000) {
    arr[str[i * 2] - 'a']++;
    arr[str[i * 2 + 1] - 'A']--;
    if (arr[str[i * 2 + 1] - 'A'] < 0) {
      arr[str[i * 2 + 1] - 'A'] = 0;
      key++;
    }
    i++;
  }
  printf("%d", key);
}
