#include <bits/stdc++.h>
using namespace std;
char c[5000000];
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", c);
  int cs = strlen(c);
  int ans = 0;
  for (int i = n; i < cs; i += n)
    if (c[i - 1] == c[i - 2] && c[i - 2] == c[i - 3]) ans++;
  printf("%d\n", ans);
}
