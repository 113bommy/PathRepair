#include <bits/stdc++.h>
using namespace std;
int a[6];
int n;
char s[1010];
unordered_map<string, int> m;
string ans[101010];
string rev[] = {"S", "M", "L", "XL", "XXL", "XXXL"};
int main() {
  m["S"] = 0;
  m["M"] = 1;
  m["L"] = 2;
  m["XL"] = 3;
  m["XXL"] = 4;
  m["XXXL"] = 5;
  for (int i = 0; i < 6; ++i) {
    scanf("%d", a + i);
  }
  vector<pair<int, pair<int, int> > > v;
  bool can = true;
  scanf("%d", &n);
  for (int i = 0; can && i < n; ++i) {
    scanf("%s", s);
    string tmp = "";
    bool comma = false;
    for (int j = 0; s[j]; ++j) {
      if (s[j] == ',') {
        v.push_back({m[tmp], {0, i}});
        tmp = "";
        comma = true;
      } else
        tmp = tmp + s[j];
    }
    if (comma) {
      if (--a[m[tmp]] < 0)
        can = false;
      else {
        ans[i] = tmp;
      }
    } else {
      v.push_back({m[tmp], {1, i}});
    }
  }
  sort(v.begin(), v.end());
  for (int i = 0; can && i < v.size(); ++i) {
    if (a[v[i].first] > 0 && ans[v[i].second.second] == "") {
      ans[v[i].second.second] = rev[v[i].first];
      --a[v[i].first];
    }
  }
  for (int i = 0; can && i < n; ++i) {
    if (ans[i] == "") {
      can = false;
    }
  }
  if (!can)
    printf("NO\n");
  else {
    printf("YES\n");
    for (int i = 0; i < n; ++i) {
      printf("%s\n", ans[i].c_str());
    }
  }
  return 0;
}
