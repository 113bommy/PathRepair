#include <bits/stdc++.h>
using namespace std;
int n, l;
int x[1002], war[1002], skad[1002];
long double dp[1002];
bool dasie(long double k) {
  for (int i = 1; i <= n; i++) {
    dp[i] = sqrt(abs(l - x[i])) - k * war[i];
    skad[i] = 0;
    for (int j = 1; j < i; j++)
      if (dp[j] + sqrt(abs(l - x[i] + x[j])) - k * war[i] < dp[i]) {
        dp[i] = dp[j] + sqrt(abs(l + x[j] - x[i])) - k * war[i];
        skad[i] = j;
      }
  }
  if (dp[n] <= 0) return 1;
  return 0;
}
vector<int> roz;
int main() {
  int p = 0, k;
  scanf("%d%d", &n, &l);
  for (int i = 1; i <= n; i++) scanf("%d%d", x + i, war + i);
  k = x[n];
  while (p < k) {
    int s = (p + k) / 2;
    dasie(s) ? k = s : p = s + 1;
  }
  long double wynik = k;
  for (int i = 1; i <= 30; i++) {
    if (dasie(wynik - 1 / (long double)(1 << i)))
      wynik -= 1 / (long double)(1 << i);
  }
  dasie(wynik);
  roz.push_back(n);
  while (skad[roz.back()]) roz.push_back(skad[roz.back()]);
  for (int i = roz.size() - 1; i >= 0; i--) printf("%d ", roz[i]);
}
