#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  char str[3000];
  scanf("%d %s", &n, str);
  int i, sum = 0, len = strlen(str);
  for (i = n - 1; i < len; i += n)
    if (str[i - 2] == str[i - 1] && str[i - 2] == str[i - 3]) ++sum;
  printf("%d\n", sum);
  return 0;
}
