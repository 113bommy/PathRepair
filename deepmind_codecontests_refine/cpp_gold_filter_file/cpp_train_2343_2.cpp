#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, temp;
  int cnt[2000000 + 10];
  memset(cnt, 0, sizeof cnt);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &temp);
    cnt[temp]++;
  }
  int ans = 0;
  for (int i = 0; i < 2000000 + 10 - 1; i++) {
    cnt[i + 1] += cnt[i] / 2;
    ans += cnt[i] % 2;
  }
  cout << ans << endl;
}
