#include <bits/stdc++.h>
using namespace std;
int lcp[4201][2101];
int main() {
  string s1, s2, s3;
  cin >> s1 >> s2;
  s3 = s1;
  s3.push_back('$');
  reverse(s1.begin(), s1.end());
  s3.append(s1);
  int len1 = s3.size();
  int len2 = s2.size();
  int len3 = s1.size();
  for (int i = len1 - 1; i >= 0; i--) {
    for (int j = len2 - 1; j >= 0; j--) {
      if (s3[i] == s2[j]) lcp[i][j] = 1 + lcp[i + 1][j + 1];
    }
  }
  vector<pair<int, int>> ans;
  int size = 0;
  for (int idx = 0; idx < len2;) {
    int maxi = 0, maxpos;
    for (int i = 0; i < len1; i++) {
      if (maxi < lcp[i][idx]) {
        maxi = lcp[i][idx];
        maxpos = i;
      }
    }
    if (maxi == 0) {
      printf("-1\n");
      return 0;
    }
    if (maxpos < len3)
      ans.push_back(make_pair(maxpos + 1, maxpos + maxi));
    else
      ans.push_back(make_pair(len1 - maxpos, len1 - (maxpos + maxi) + 1));
    idx += maxi;
  }
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < ans.size(); i++) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}
