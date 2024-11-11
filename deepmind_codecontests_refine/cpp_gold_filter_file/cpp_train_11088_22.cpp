#include <bits/stdc++.h>
using namespace std;
int n;
char s[100004];
int main() {
  scanf("%d%s", &n, s + 1);
  int a = 3;
  for (int i = 2; i <= n; i++) a += (s[i] != s[i - 1]);
  printf("%d\n", (a > n) ? n : a);
  return 0;
}
