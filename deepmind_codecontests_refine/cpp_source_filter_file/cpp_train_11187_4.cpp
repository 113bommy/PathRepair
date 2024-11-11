#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<int, int> > mn, mx;
int n, k;
int a[1005];
vector<pair<int, int> > ans;
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    mx.push(make_pair(a[i], i));
    mn.push(make_pair(-a[i], i));
  }
  for (int i = 0; i < k; i++) {
    int cmn = mn.top().second;
    int cmx = mx.top().second;
    mn.pop();
    mx.pop();
    if (cmn == cmx)
      break;
    else {
      ans.push_back(make_pair(cmn + 1, cmx + 1));
      a[cmn]++;
      a[cmx]--;
      mn.push(make_pair(-a[cmn], cmn));
      mn.push(make_pair(-a[cmx], cmx));
      mx.push(make_pair(a[cmn], cmn));
      mx.push(make_pair(a[cmx], cmx));
    }
  }
  printf("%d %d\n", mx.top().first + mn.top().first, ans.size());
  for (int i = 0; i < ans.size(); i++) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}
