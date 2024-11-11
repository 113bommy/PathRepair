#include <bits/stdc++.h>
int main() {
  int n;
  char arr[200005];
  int hash[26];
  memset(hash, 0, sizeof(hash));
  scanf("%d", &n);
  scanf("%s", arr);
  int i;
  int count;
  for (i = 1; i < n; i++) {
    if (arr[2 * i - 1] != arr[2 * i - 2] - 'a' + 'A') {
      if (hash[arr[2 * i - 1] - 'A'] == 0)
        count++;
      else
        hash[arr[2 * i - 1] - 'A']--;
      hash[arr[2 * i - 2] - 'a']++;
    }
  }
  printf("%d\n", count);
  return 0;
}
