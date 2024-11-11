#include <bits/stdc++.h>
using namespace std;
int n, ans;
pair<int, int> p[2000];
map<pair<int, int>, int> cnt;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf(" %d%d", &p[i].first, &p[i].second);
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      int X = p[i].first - p[j].first;
      int Y = p[i].second - p[j].second;
      ans += cnt[{X, Y}];
      cnt[{X, Y}]++;
    }
  printf("%d", ans / 2);
}
