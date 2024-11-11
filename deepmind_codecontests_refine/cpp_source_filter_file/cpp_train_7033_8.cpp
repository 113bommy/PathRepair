#include <bits/stdc++.h>
using namespace std;
vector<int> arr(100005);
vector<int> prep(100005);
vector<pair<int, int> > req(100005);
int pred(int days, int m) {
  int balance = 0;
  for (int i = 0; i < 100005; i++) req[i] = {-1, -1};
  for (int i = days; i > 0; i--) {
    if (arr[i] != 0 && (req[arr[i]].first == -1 && req[arr[i]].second == -1)) {
      req[arr[i]].second = arr[i];
      req[arr[i]].first = i;
    }
  }
  sort(req.begin() + 1, req.begin() + 1 + m);
  int start = 1;
  for (int i = 1; i <= m; i++) {
    int curr = req[i].second;
    int pos = req[i].first;
    if (pos != -1 && balance + pos - start >= prep[curr]) {
      balance = balance + pos - start - prep[curr];
      start = pos;
    } else
      return 0;
  }
  return 1;
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
  for (int i = 1; i <= m; i++) scanf("%d", &prep[i]);
  int start = 1, end = n, mid;
  while (start < end) {
    mid = start + (end - start) / 2;
    if (!pred(mid, m)) {
      start = mid + 1;
    } else {
      end = mid;
    }
  }
  if (pred(start, m))
    printf("%d\n", start);
  else
    printf("-1\n");
}
