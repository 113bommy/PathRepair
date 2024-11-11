#include <bits/stdc++.h>
using namespace std;
const int MAXN = 150010;
int cnt[MAXN];
int n;
int main() {
  scanf("%d", &n);
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; ++i) {
    int num;
    scanf("%d", &num);
    cnt[num]++;
  }
  int ans = 0;
  for (int i = 1; i <= 150000; ++i) {
    if (cnt[i] >= 1) {
      --cnt[i];
      ++ans;
      if (cnt[i] >= 1) {
        --cnt[i];
        ++cnt[i + 1];
      }
    } else {
      if (cnt[i + 1] >= 1) {
        --cnt[i + 1];
        ++ans;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
