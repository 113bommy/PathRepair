#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
int t, n;
char s[N];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    scanf("%s", s + 1);
    int ans = n;
    for (int i = 1; i <= n; i++) {
      if (s[i] == '1') {
        ans = max(ans, i * 2);
        ans = max(ans, (n - i + 1) * 2);
        ans = max(ans, n + 1);
      }
    }
    printf("%d\n", ans);
  }
}
