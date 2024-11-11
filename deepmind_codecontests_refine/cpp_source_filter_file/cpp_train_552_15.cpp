#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
bool cmp(pii a, pii b) {
  if (a.first > b.first) return true;
  if (a.first < b.first) return false;
  if (a.second < b.second) return true;
  return false;
}
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<pii> v(n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &v[i].first, &v[i].second);
  }
  sort(v.begin(), v.end(), cmp);
  int ans = 1;
  for (int i = k + 1; i < n; i++) {
    if (v[k] != v[i]) break;
    ans++;
  }
  for (int i = k - 1; i >= 0; i--) {
    if (v[k] != v[i]) break;
    ans++;
  }
  printf("%d\n", ans);
}
