#include <bits/stdc++.h>
using namespace std;
const int N = 100002;
int n;
pair<int, int> p[N];
int lv[N], cnt[N];
int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &p[i].first);
    p[i].second = i + 2;
  }
  sort(p, p + n - 1);
  lv[1] = 1, cnt[1] = 1;
  for (int i = 0; i < n - 1; i++) {
    lv[p[i].second] = lv[p[i].first] + 1;
    cnt[lv[p[i].second]]++;
  }
  int ans = 0;
  for (int i = 1; i <= 5; i++) {
    if (cnt[i] % 2 == 1) {
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
