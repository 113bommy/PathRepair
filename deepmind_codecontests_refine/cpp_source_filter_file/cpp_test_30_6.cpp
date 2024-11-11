#include <bits/stdc++.h>
using namespace std;
char A[100005];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, ans = 1e9;
    scanf("%d", &n);
    scanf("%s", A + 1);
    for (int i = 0; i <= 26; i++) {
      int l = 1, r = n, key = 0;
      bool f = 1;
      while (l < r) {
        int a1, a2;
        a1 = a2 = 0;
        while (A[l] == i + 'a' - 1 && l <= r) l++, a1++;
        while (A[r] == i + 'a' - 1 && l <= r) r--, a2++;
        if (l >= r) break;
        key += abs(a1 - a2);
        if (A[l] != A[r]) {
          f = 0;
          break;
        }
        l++, r--;
      }
      if (f) {
        ans = min(ans, key);
      }
    }
    if (ans == 1e9)
      puts("-1");
    else
      printf("%d\n", ans);
  }
  return 0;
}
