#include <bits/stdc++.h>
int a[100010], mm[100010], mmm[100010];
void MAIN() {
  int n, m, k;
  std::cin >> n >> m >> k;
  for (int i = 0, tmp; i < n; ++i) {
    std::cin >> tmp;
    mm[tmp] = i;
    mmm[i] = tmp;
  }
  int ans = 0;
  while (m--) {
    int now;
    std::cin >> now;
    int pos = mm[now];
    ans += pos / k + 1;
    if (pos != 0) {
      int pre = mmm[pos - 1];
      mmm[pos - 1] = now, mmm[pos] = pre;
      mm[now] = pos - 1, mm[pre] = pos;
    }
  }
  std::cout << ans << std::endl;
}
int main() {
  MAIN();
  return 0;
}
