#include <bits/stdc++.h>
using namespace std;
bool p[20];
pair<int, int> a[20], b[20];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &a[i].first, &a[i].second);
    if (a[i].first > a[i].second) swap(a[i].first, a[i].second);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", &b[i].first, &b[i].second);
    if (b[i].first > b[i].second) swap(b[i].first, b[i].second);
  }
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    bool fl1 = 0, fl2 = 0;
    for (int j = 0; j < m; ++j) {
      if (a[i] == b[j] ||
          (a[i].first != b[j].first && a[i].first != b[j].second &&
           a[i].second != b[j].first && a[i].second != b[j].second))
        continue;
      if (a[i].first == b[j].first || a[i].first == b[j].second) fl1 = 1;
      if (a[i].second == b[j].first || a[i].second == b[j].second) fl2 = 1;
    }
    if (fl1 && fl2) {
      puts("-1");
      return 0;
    }
    if (fl1 && !p[a[i].first]) {
      ans.push_back(a[i].first);
      p[a[i].first] = 1;
    }
    if (fl2 && !p[a[i].second]) {
      ans.push_back(a[i].second);
      p[a[i].second] = 1;
    }
  }
  for (int i = 0; i < m; ++i) {
    bool fl1 = 0, fl2 = 0;
    for (int j = 0; j < n; ++j) {
      if (b[i] == a[j] ||
          (a[j].first != b[i].first && a[j].first != b[i].second &&
           a[j].second != b[i].first && a[j].second != b[i].second))
        continue;
      if (b[i].first == a[j].first || b[i].first == a[j].second) fl1 = 1;
      if (b[i].second == a[j].first || b[i].second == a[j].second) fl2 = 1;
    }
    if (fl1 && fl2) {
      puts("-1");
      return 0;
    }
    if (fl1 && !p[b[i].first]) {
      ans.push_back(b[i].first);
      p[b[i].first] = 1;
    }
    if (fl2 && !p[b[i].second]) {
      ans.push_back(b[i].second);
      p[b[i].second] = 1;
    }
  }
  if ((int)ans.size() > 1)
    puts("0");
  else
    printf("%d", ans[0]);
  return 0;
}
