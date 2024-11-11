#include <bits/stdc++.h>
using namespace std;
int a[200005];
vector<int> ans;
set<int> exist;
vector<int> check;
int main() {
  int pw = 1;
  for (int i = 0; i < 31; i++) {
    check.push_back(pw);
    pw *= 2;
  }
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    exist.insert(a[i]);
  }
  sort(a + 1, a + 1 + n);
  ans.push_back(a[1]);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < check.size(); j++) {
      int val = check[j];
      vector<int> tmp;
      tmp.push_back(a[i]);
      if (exist.find(a[i] - val) != exist.end()) tmp.push_back(a[i] - val);
      if (exist.find(a[i] + val) != exist.end()) tmp.push_back(a[i] + val);
      if (tmp.size() > ans.size()) ans = tmp;
      tmp.clear();
      tmp.push_back(a[i]);
      if (exist.find(a[i] - val) != exist.end()) tmp.push_back(a[i] - val);
      if (exist.find(a[i] - 2 * val) != exist.end())
        tmp.push_back(a[i] - 2 * val);
      if (tmp.size() > ans.size()) ans = tmp;
      tmp.clear();
      tmp.push_back(a[i]);
      if (exist.find(a[i] + val) != exist.end()) tmp.push_back(a[i] + val);
      if (exist.find(a[i] + 2 * val) != exist.end())
        tmp.push_back(a[i] + 2 * val);
      if (tmp.size() > ans.size()) ans = tmp;
    }
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++) printf("%lld ", ans[i]);
}
