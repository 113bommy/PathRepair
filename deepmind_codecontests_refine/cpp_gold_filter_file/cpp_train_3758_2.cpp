#include <bits/stdc++.h>
using namespace std;
int n, m;
int p[3055], c[3055];
vector<int> vec[3055];
int main() {
  cin >> n >> m;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &p[i], &c[i]);
    vec[p[i]].push_back(c[i]);
    if (p[i] == 1) cnt++;
  }
  for (int i = 2; i <= m; i++) {
    sort(vec[i].begin(), vec[i].end());
  }
  long long cur = 0;
  long long res = LLONG_MAX;
  for (int i = n; i >= 0; i--) {
    for (int j = 2; j <= m; j++) {
      if ((int)vec[j].size() > i) {
        cnt++;
        cur += *vec[j].begin();
        vec[j].erase(vec[j].begin());
      }
    }
    if (cnt > i) {
      res = min(res, cur);
    } else {
      int left = i + 1 - cnt;
      vector<int> temp;
      for (int j = 2; j <= m; j++) {
        for (auto u : vec[j]) {
          temp.push_back(u);
        }
      }
      sort(temp.begin(), temp.end());
      long long cost = cur;
      if (temp.size() < left) continue;
      for (int j = 0; j < left; j++) {
        cost += temp[j];
      }
      res = min(res, cost);
    }
  }
  cout << res;
  return 0;
}
