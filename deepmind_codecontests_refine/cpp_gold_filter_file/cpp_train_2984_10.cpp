#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, ans = 100005 - 1;
int si[100005], ata[100005], dp[100005], tut[100005];
int bul(int node) {
  if (node == ata[node]) return node;
  return ata[node] = bul(ata[node]);
}
bool lucky(int val) {
  while (val) {
    int rem = val % 10;
    if (rem != 4 && rem != 7) return false;
    val /= 10;
  }
  return true;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    si[i] = 1;
    ata[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &x, &y);
    int atax = bul(x);
    int atay = bul(y);
    if (atax != atay) {
      ata[atax] = atay;
      si[atay] += si[atax];
    }
  }
  for (int i = 1; i <= n; i++) {
    if (bul(i) == i) {
      tut[si[i]]++;
    }
  }
  for (int i = 1; i < 100005; i++) {
    dp[i] = 100005;
  }
  for (int i = 1; i <= n; i++) {
    int count = 0;
    while (tut[i]) {
      int dec = 1 << count;
      dec = min(dec, tut[i]);
      tut[i] -= dec;
      for (int j = n - dec * i; j >= 0; j--) {
        dp[j + i * dec] = min(dp[j + i * dec], dp[j] + dec);
      }
      count++;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (lucky(i)) {
      ans = min(ans, dp[i] - 1);
    }
  }
  if (ans == 100005 - 1) ans = -1;
  printf("%d", ans);
}
