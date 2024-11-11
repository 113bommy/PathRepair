#include <bits/stdc++.h>
using namespace std;
const int maxn = 1500 + 7;
map<int, vector<pair<int, int>>> mp;
int n, a[maxn];
int maxnum;
vector<pair<int, int>> ans;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    int sum = 0;
    for (int j = i; j >= 1; j--) {
      sum += a[j];
      mp[sum].push_back(make_pair(j, i));
    }
  }
  for (auto &u : mp) {
    vector<pair<int, int>> v = u.second;
    int ed = -1;
    int len = v.size();
    vector<pair<int, int>> now;
    int cnt = 0;
    for (int i = 0; i < len; i++) {
      int l = v[i].first;
      if (l > ed) {
        cnt++;
        ed = v[i].second;
        now.push_back(v[i]);
      }
    }
    if (cnt > maxnum) {
      maxnum = cnt;
      ans = now;
    }
  }
  printf("%d\n", maxnum);
  for (auto &u : ans) {
    printf("%d %d\n", u.first, u.second);
  }
  return 0;
}
