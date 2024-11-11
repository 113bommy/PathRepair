#include <bits/stdc++.h>
using namespace std;
int n;
long long ans = 0;
int main() {
  scanf("%d", &n);
  getchar();
  for (int i = 0; i < n; i++) {
    char c;
    scanf("%c", &c);
    if (c == 'B') ans += (1 << i);
  }
  printf("%lld\n", ans);
  return 0;
}
