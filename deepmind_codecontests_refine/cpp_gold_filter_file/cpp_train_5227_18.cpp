#include <bits/stdc++.h>
using namespace std;
char s[2005];
int main() {
  int T;
  scanf("%d", &T);
  int n, k;
  while (T--) {
    scanf("%d%d %s", &n, &k, s);
    int i = 0;
    vector<pair<int, int>> ans;
    while (k > 1) {
      k--;
      if (s[i] == ')') {
        int j = i;
        while (s[j] == ')') j++;
        ans.emplace_back(i + 1, j + 1);
        for (int l = i, o = j; l < o; l++, o--) swap(s[l], s[o]);
      }
      i++;
      if (s[i] == '(') {
        int j = i;
        while (s[j] == '(') j++;
        ans.emplace_back(i + 1, j + 1);
        for (int l = i, o = j; l < o; l++, o--) swap(s[l], s[o]);
      }
      i++;
    }
    while (s[i]) {
      if (s[i] == ')') {
        int j = i;
        while (s[j] && s[j] == ')') j++;
        if (!s[j]) break;
        ans.emplace_back(i + 1, j + 1);
        for (int l = i, o = j; l < o; l++, o--) swap(s[l], s[o]);
      }
      i++;
    }
    printf("%d\n", (int)ans.size());
    for (auto x : ans) printf("%d %d\n", x.first, x.second);
  }
  return 0;
}
