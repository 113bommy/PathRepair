#include <bits/stdc++.h>
int del[100010];
int main() {
  char ar[100010];
  scanf("%s", ar);
  int len = strlen(ar);
  for (int i = 0; i < len; i++) {
    if (ar[i] == '0') {
      del[i] = 1;
      break;
    }
    if (i == len) del[i] = 1;
  }
  for (int i = 0; i < len; i++)
    if (del[i] != 1) printf("%c", ar[i]);
}
