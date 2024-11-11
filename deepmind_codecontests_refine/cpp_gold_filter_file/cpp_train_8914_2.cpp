#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > v;
int arr[100005];
int ans[100005];
int main() {
  int i, j, k;
  int n, l, r, mid;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &arr[i]);
  v.push_back(make_pair(n, arr[n]));
  ans[n] = -1;
  j = 0;
  for (i = n - 1; i >= 1; i--) {
    if (arr[i] <= v[j].second) {
      v.push_back(make_pair(i, arr[i]));
      j++;
      ans[i] = -1;
    } else {
      l = 0;
      r = j;
      while (l <= r) {
        mid = (l + r) / 2;
        if (v[mid].second < arr[i] &&
            (mid == 0 || v[mid - 1].second >= arr[i])) {
          ans[i] = abs(v[mid].first - i) - 1;
          break;
        } else if (v[mid].second < arr[i]) {
          r = mid - 1;
        } else
          l = mid + 1;
      }
    }
  }
  for (i = 1; i <= n; i++) printf("%d ", ans[i]);
  return 0;
}
