#include <bits/stdc++.h>
using namespace std;
vector<pair<pair<int, int>, int> > v;
pair<int, int> ans[100005];
int main() {
  int n, m, a, b;
  scanf("%d", &n);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d", &a);
    scanf("%d", &b);
    b = 1 - b;
    v.push_back(make_pair(make_pair(a, b), i));
  }
  sort(v.begin(), v.end());
  int start = 2;
  int end = 3;
  int temp = 1;
  int mst = 2;
  int i;
  for (i = 0; i < m; i++) {
    if (v[i].first.second == 0) {
      ans[v[i].second] = (make_pair(temp, mst));
      mst++;
    } else {
      if (start >= mst) {
        printf("-1\n");
        return 0;
      } else {
        ans[v[i].second] = (make_pair(start, end));
        start++;
        if (start == end) {
          start = 2;
          end++;
        }
      }
    }
  }
  for (i = 1; i <= m; i++) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}
