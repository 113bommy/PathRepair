#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
  }
  long long ans = 1LL * cnt[0] * (cnt[0] - 1) / 2;
  cnt[0] = 0;
  for (int i = 0; i < n; i++) {
    if (!a[i]) continue;
    ans += cnt[a[i] * -1];
    cnt[a[i]]--;
  }
  printf("%I64d", ans);
  return 0;
}
