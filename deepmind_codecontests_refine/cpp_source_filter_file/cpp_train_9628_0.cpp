#include <bits/stdc++.h>
char arr[500][500];
int main() {
  int a, b, c;
  scanf("%d%d", &a, &b);
  int flag = 0;
  int cnt = 0;
  for (int w = 0; w < a; w++) {
    char foo = 'S';
    if (w != 0) {
      if (arr[w - 1][0] == 'S')
        foo = 'L';
      else
        foo = 'S';
    }
    for (int i = 0; i < a; i++) {
      if (cnt < b) {
        arr[w][i] = foo;
        if (arr[w][i] == 'S') cnt++;
      } else
        arr[w][i] = 'L';
      if (foo == 'S')
        foo = 'L';
      else
        foo = 'S';
    }
  }
  if (cnt == b) {
    printf("YES\n");
    for (int w = 0; w < a; w++) {
      puts(arr[w]);
    }
  } else
    printf("NO");
}
