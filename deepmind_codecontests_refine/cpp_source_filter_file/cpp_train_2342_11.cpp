#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
pair<int, int> a[100001];
int ans1[100001], ans2[100001];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    a[i].second = i;
    scanf("%d", &a[i].first);
  }
  sort(a + 1, a + n + 1);
  ans1[a[1].second] = a[2].first - a[1].first;
  ans2[a[1].second] = a[n].first - a[1].first;
  ans1[a[n].second] = a[n].first - a[n - 1].first;
  ans2[a[n].second] = a[n].first - a[1].first;
  for (int i = 2; i < n; i++) {
    ans1[a[i].second] =
        min(a[i + 1].first - a[i].first, a[i].first - a[i - 1].first);
    ans2[a[i].second] = min(a[n].first - a[i].first, a[i].first - a[1].first);
  }
  for (int i = 1; i <= n; i++) printf("%d %d\n", ans1[i], ans2[i]);
  return 0;
}
