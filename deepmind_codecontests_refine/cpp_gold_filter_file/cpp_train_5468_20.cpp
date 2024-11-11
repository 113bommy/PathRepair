#include <bits/stdc++.h>
using namespace std;
template <class T>
void chmin(T& a, const T& b) {
  if (a > b) a = b;
}
template <class T>
void chmax(T& a, const T& b) {
  if (a < b) a = b;
}
int n, m;
int a[200100];
pair<int, int> query[200100];
vector<pair<int, int> > qs;
int ans[200100], tmp[200100];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &query[i].first, &query[i].second);
  }
  int res = 0, rt = -1;
  for (int i = m - 1; i >= 0; i--) {
    if (query[i].second <= res) continue;
    qs.push_back(query[i]);
    res = query[i].second;
    rt = query[i].first;
  }
  reverse((qs).begin(), (qs).end());
  for (int i = 0; i < n; i++) {
    ans[i] = a[i];
    tmp[i] = a[i];
  }
  sort(tmp, tmp + res);
  int cnt = 0;
  int l = 0, r = res - 1, dir = qs[0].first;
  for (int i = res - 1; i >= 0; i--) {
    if (cnt < ((int)(qs).size()) && qs[cnt].second == i + 1) {
      dir = qs[cnt].first;
      cnt++;
    }
    if (dir == 1) {
      ans[i] = tmp[r];
      r--;
    } else {
      ans[i] = tmp[l];
      l++;
    }
  }
  for (int i = 0; i < n; i++) printf("%d%c", ans[i], (i == n - 1) ? '\n' : ' ');
  return 0;
}
