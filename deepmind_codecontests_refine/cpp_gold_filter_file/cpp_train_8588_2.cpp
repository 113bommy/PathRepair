#include <bits/stdc++.h>
using namespace std;
pair<int, int> interval[500000];
bool cmp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &interval[i].first, &interval[i].second);
  }
  sort(interval, interval + n, cmp);
  int ans = 0, cur = -1;
  for (int i = 0; i < n; ++i) {
    if (interval[i].first > cur) {
      ++ans;
      cur = interval[i].second;
    }
  }
  printf("%d\n", ans);
  return 0;
}
