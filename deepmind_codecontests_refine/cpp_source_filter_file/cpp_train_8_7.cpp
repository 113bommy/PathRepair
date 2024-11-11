#include <bits/stdc++.h>
using namespace std;
int n, cnt;
char str[110];
int main() {
  scanf("%d %s", &n, str + 1);
  for (int i = 1; i <= n; i++)
    if (str[i] == '8') cnt++;
  for (int i = cnt; i >= 1; i++)
    if ((n - i) / 10 >= i) return !printf("%d\n", i);
  puts("0");
  return 0;
}
