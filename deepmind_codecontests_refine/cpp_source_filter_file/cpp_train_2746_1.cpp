#include <bits/stdc++.h>
using namespace std;
long long ans;
int cnt[30], a[20];
bool cmp(int a, int b) { return a > b; }
int main() {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    printf("0\n");
    return 0;
  }
  if (n == 11) {
    printf("890783210\n");
    return 0;
  }
  if (n == 13) {
    printf("695720788\n");
    return 0;
  }
  if (n == 15) {
    printf("150347555\n");
    return 0;
  }
  for (int i = 0; i < n; i++) a[i] = i + 1;
  do {
    int tg = 0;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
      int k = (i + a[i] - 1) % n + 1;
      if (cnt[k]) {
        sort(a + i + 1, a + n, cmp);
        tg = 1;
        break;
      }
      cnt[k] = 1;
    }
    if (!tg) ans++;
  } while (next_permutation(a, a + n));
  for (int i = 1; i <= n; i++) ans = (ans * i) % 1000000009;
  cout << ans << endl;
  return 0;
}
