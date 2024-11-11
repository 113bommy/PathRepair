#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, T, low, mid, high, a[200005], t[200005];
  vector<int> ans;
  scanf("%d%d", &n, &T);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i], &t[i]);
  }
  low = 0;
  high = n;
  while (low <= high) {
    mid = (low + high) / 2;
    vector<pair<int, int> > v;
    int cnt = 0, tot_t = 0, idx = -1;
    for (int i = 1; i <= n; i++) {
      if (a[i] >= mid) v.push_back(make_pair(t[i], i));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
      if (tot_t + v[i].first > T) break;
      cnt++;
      tot_t += v[i].first;
      if (cnt == mid) {
        idx = i;
        break;
      }
    }
    if (cnt == mid) {
      ans.clear();
      for (int i = 0; i <= idx; i++) ans.push_back(v[i].second);
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  printf("%d\n%d\n", ans.size(), ans.size());
  for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
