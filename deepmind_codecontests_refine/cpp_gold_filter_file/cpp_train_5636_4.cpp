#include <bits/stdc++.h>
using namespace std;
int n;
long long num[15];
void init() {
  memset(num, 0, sizeof(num));
  for (int i = 1; i <= n; i++) {
    int tmp = i % 9 != 0 ? i % 9 : 9;
    num[tmp]++;
  }
}
int main() {
  while (scanf("%d", &n) != EOF) {
    init();
    long long ans = 0;
    for (int i = 1; i <= n; i++) ans -= n / i;
    for (int i = 1; i <= 9; i++) {
      for (int j = 1; j <= 9; j++) {
        int tmp = i * j;
        tmp %= 9;
        if (!tmp) tmp = 9;
        if (num[tmp]) ans += num[i] * num[j] * num[tmp];
      }
    }
    cout << ans << endl;
  }
  return 0;
}
