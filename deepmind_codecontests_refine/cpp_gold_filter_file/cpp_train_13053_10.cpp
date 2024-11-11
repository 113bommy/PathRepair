#include <bits/stdc++.h>
using namespace std;
vector<int> prefixFunc(string s) {
  int m = (int)s.size();
  vector<int> ret = vector<int>(m);
  for (int i = 1, k = 0; i < m; i++) {
    while (k > 0 && s[k] != s[i]) k = ret[k - 1];
    if (s[k] == s[i])
      ret[i] = ++k;
    else
      ret[i] = k;
  }
  return ret;
}
vector<int> pal_array(string s) {
  int f = s.size();
  s = "@" + s + "$";
  vector<int> len(f + 1);
  int l = 1, r = 1;
  for (int i = 1; i <= f; i++) {
    len[i] = min(r - i, len[l + (r - i)]);
    while (s[i - len[i]] == s[i + len[i]]) len[i]++;
    if (i + len[i] > r) {
      l = i - len[i];
      r = i + len[i];
    }
  }
  len.erase(len.begin());
  return len;
}
string a;
int n;
int dp[200005];
int path[200005];
int main() {
  cin >> a;
  n = a.size();
  vector<int> palArray = pal_array(a);
  string b = a;
  reverse(b.begin(), b.end());
  vector<int> failure = prefixFunc(b + "#" + a);
  for (int i = n + 1, j = 0; i <= 2 * n; i++, j++) {
    if (j && dp[j - 1] > failure[i]) {
      dp[j] = dp[j - 1], path[j] = path[j - 1];
    } else {
      dp[j] = failure[i], path[j] = j - dp[j] + 1;
    }
  }
  int len = 0;
  vector<pair<int, int> > ans;
  for (int i = 0; i < n; i++) {
    int mid = palArray[i];
    int best = (i - mid >= 0) ? dp[i - mid] : 0;
    if (i + mid < n - best + 1 && i - mid + 1 > best - 1 &&
        best * 2 + (mid * 2 - 1) > len) {
      ans.clear();
      len = best * 2 + (mid * 2 - 1);
      if (best == 0) {
        ans.push_back(make_pair(i - mid + 1, mid * 2 - 1));
      } else {
        ans.push_back(make_pair(path[i - mid], best));
        ans.push_back(make_pair(i - mid + 1, mid * 2 - 1));
        ans.push_back(make_pair(n - best, best));
      }
    }
  }
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].first + 1 << " " << ans[i].second << "\n";
  }
  return 0;
}
