#include <bits/stdc++.h>
using namespace std;
int ans[10];
int main() {
  int n;
  scanf("%d", &n);
  char s[200];
  while (n--) {
    scanf("%s", s);
    for (int i = 0; i < 7; ++i) {
      ans[i] += s[i] - '0';
    }
  }
  printf("%lld\n", *max_element(ans, ans + 7));
  return 0;
}
