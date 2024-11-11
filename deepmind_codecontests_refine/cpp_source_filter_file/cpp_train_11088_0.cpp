#include <bits/stdc++.h>
using namespace std;
char haha[100005];
int main() {
  int n;
  scanf("%d%s", &n, haha);
  int ans = 0;
  for (int i = 1; i < n; i++) ans += (haha[i - 1] != haha[i]);
  printf("%d\n", min(ans + 2, n));
  return 0;
}
