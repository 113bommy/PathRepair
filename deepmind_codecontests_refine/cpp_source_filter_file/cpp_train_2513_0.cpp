#include <bits/stdc++.h>
using namespace std;
char s[100000];
long long ans;
int n;
int main() {
  scanf("%d", &n);
  scanf("%s", s);
  for (int i = 0; i < n; i++)
    if ((s[i] - '0') % 2 == 0) ans += n - i;
  printf("%I64d", ans);
}
