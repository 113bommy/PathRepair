#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int>> v1;
vector<pair<int, int>> v2;
int connect(int i, int j) {
  int ans = 0;
  if (v1[i].first == v2[j].first) {
    ans++;
  }
  if (v1[i].first == v2[j].second) {
    ans++;
  }
  if (v1[i].second == v2[j].first) {
    ans++;
  }
  if (v1[i].second == v2[j].second) {
    ans++;
  }
  return ans;
}
int main() {
  scanf("%d %d", &n, &m);
  v1.resize(n);
  v2.resize(m);
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &v1[i].first, &v1[i].second);
  }
  for (int j = 0; j < m; j++) {
    scanf("%d %d", &v2[j].first, &v2[j].second);
  }
  int possible1 = 0;
  for (int i = 0; i < n; i++) {
    int temp = 0;
    bool h1 = false;
    bool h2 = false;
    for (int j = 0; j < m; j++) {
      if (connect(i, j) == 2 || connect(i, j) == 0) continue;
      if (v1[i].first == v2[j].first || v1[i].first == v2[j].second)
        h1 = true;
      else
        h2 = true;
    }
    if (h1 && h2) {
      printf("-1");
      return 0;
    }
    if (h1) {
      ans.push_back(v1[i].first);
    } else if (h2)
      ans.push_back(v1[i].second);
  }
  for (int j = 0; j < m; j++) {
    int temp = 0;
    bool h1 = false, h2 = false;
    for (int i = 0; i < n; i++) {
      if (connect(i, j) == 2 || connect(i, j) == 0) continue;
      if (v2[j].first == v1[i].first || v2[j].first == v1[i].second)
        h1 = true;
      else
        h2 = true;
    }
    if (h1 && h2) {
      printf("-1");
      return 0;
    }
    if (h1) {
      ans.push_back(v2[j].first);
    } else if (h2)
      ans.push_back(v2[j].second);
  }
  for (int i = 1; i < ans.size(); i++) {
    if (ans[i] != ans[i - 1]) {
      printf("0");
      return 0;
    }
  }
  printf("%d", ans[0]);
  return 0;
}
