#include <bits/stdc++.h>
using namespace std;
int fun(int n, int m) {
  if (n == 0 && m == 0) {
    return 0;
  }
  for (int i = 1;; i++) {
    if ((i * i + i % 2) / 2 >= n && (i * i - i % 2) / 2 >= m) {
      return i;
    }
  }
  return 0;
}
int main() {
  int n = 0, hard = 0, soft = 0;
  char ch[100];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", ch);
    scanf("%s", ch);
    if (ch[0] == 'h') {
      hard++;
    } else {
      soft++;
    }
  }
  printf("%d", min(fun(soft, hard), fun(hard, soft)));
  return 0;
}
