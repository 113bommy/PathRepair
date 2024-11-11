#include <bits/stdc++.h>
using namespace std;
int w[1001000];
int cnt[1010000];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &w[i]);
    cnt[w[i]]++;
  }
  sort(w, w + n);
  int ans = 0;
  for (int i = 0; i < 1000100; i++) {
    cnt[i + 1] += (cnt[i] >> 2);
    cnt[i] %= 2;
    if (cnt[i]) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
