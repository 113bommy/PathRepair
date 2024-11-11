#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
char str1[MAXN], str2[MAXN];
int n1, n2;
int main() {
  int i, j, n;
  bool flag = true;
  scanf("%d %d", &n1, &n2);
  n = max(n1, n2);
  scanf("%s%s", str1, str2);
  for (i = 0; i < n; i++) {
    if (str1[i] == '*') {
      break;
    }
    if (str1[i] != str2[i] || i >= n1 || i >= n2) {
      flag = false;
      break;
    }
  }
  if (flag && i != n)
    for (j = 1; j <= n; j++) {
      if (str1[n1 - j] == '*') {
        break;
      }
      if (str1[n1 - j] != str2[n2 - j] || n2 - j < i || j >= n1 || j >= n2) {
        flag = false;
        break;
      }
    }
  printf("%s\n", flag ? "YES" : "NO");
}
