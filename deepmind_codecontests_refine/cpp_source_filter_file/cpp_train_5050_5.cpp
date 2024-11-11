#include <bits/stdc++.h>
int n, i, x, ind[210], o = 0, e = 0;
char a[200001], arr[200010];
int main() {
  scanf("%s", a);
  n = strlen(a);
  if (n == 1) {
    printf("%s\n", a);
    return 0;
  }
  for (int i = 0; i < n; i++) {
    ind[a[i]]++;
  }
  for (int i = 'a'; i <= 'z'; i++) {
    if (ind[i] > 0) {
      ind[i] % 2 == 0 ? e++ : o++;
    }
  }
  for (int i = 'z'; i >= 'a'; i--) {
    if (ind[i] % 2 != 0) {
      for (int x = 'a'; x < i; x++) {
        if (ind[x] % 2 != 0) {
          ind[x]++, ind[i]--;
          break;
        }
      }
    }
  }
  int j = 0;
  for (int i = 'a'; i <= 'z'; i++) {
    if (ind[i] > 0) {
      for (int x = 0; x < ind[i] / 2; x++) {
        printf("%c", i);
        arr[j++] = i;
      }
    }
  }
  if (n % 2 != 0) {
    for (int i = 'a'; i <= 'z'; i++) {
      if (ind[i] == 1) {
        printf("%c", i);
        break;
      }
    }
  }
  for (int i = j - 1; i >= 0; i--) {
    printf("%c", arr[i]);
  }
}
