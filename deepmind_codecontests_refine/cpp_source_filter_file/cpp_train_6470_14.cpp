#include <bits/stdc++.h>
using namespace std;
char a[500005];
int main() {
  int n, cnt = 0;
  cin >> n >> a;
  for (int i = 0; i < n; i++) {
    if (a[i] == '8')
      if (++cnt == (n - 11) / 2 + 1) {
        if (cnt > n - 11)
          return 0 * printf("NO\n");
        else
          return 0 * printf("YES\n");
      }
  }
  return 0 * printf("NO\n");
}
