#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, a[N], b[N];
pair<int, int> p[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  for (int i = 1; i <= n; i++) p[i] = {-a[i], i};
  sort(p + 1, p + n + 1);
  vector<int> ans;
  ans.push_back(p[1].second);
  for (int i = 2; i <= n; i += 2) {
    if (i == n)
      ans.push_back(p[i].second);
    else {
      pair<int, int> p1 = {b[p[i].second], a[p[i].second]};
      pair<int, int> p2 = {b[p[i + 1].second], a[p[i + 1].second]};
      if (p1 < p2)
        ans.push_back(p[i + 1].second);
      else
        ans.push_back(p[i].second);
    }
  }
  printf("%d\n", (int)ans.size());
  for (auto x : ans) printf("%d ", x);
  return 0;
}
