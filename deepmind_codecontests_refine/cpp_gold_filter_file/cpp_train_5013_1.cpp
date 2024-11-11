#include <bits/stdc++.h>
using namespace std;
bool compare(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first == b.first)
    return a.second < b.second;
  else
    return a.first > b.first;
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    bool flag = true, cond = true;
    long long n, i, j, x, y = 0, ind, k, m, dif, mn = INT_MAX, p = 0, mx = 0,
                          count = 0, diff, y1;
    string s;
    cin >> s;
    n = s.size();
    long long a[26] = {0};
    if (n == 1) {
      cout << s << "\n";
      continue;
    }
    for (i = 0; i < 26; i++) a[i] = 0;
    for (i = 0; i < n; i++) a[s[i] - 'a']++;
    bool visited[26] = {false};
    string res = "";
    char curr = 'a';
    while (1) {
      for (i = 0; i < a[curr - 'a']; i++) res += curr;
      visited[curr - 'a'] = true;
      ind = curr - 'a';
      a[ind] = 0;
      cond = false;
      for (i = 0; i < 26; i++) {
        if (a[i] > 0 && abs(ind - i) != 1) {
          cond = true;
          curr = 'a' + i;
          break;
        }
      }
      if (cond == false) break;
    }
    string s1 = "";
    bool cond1 = false;
    for (i = 0; i < 26; i++) {
      if (a[i] > 0) {
        cond1 = true;
        for (j = 0; j < a[i]; j++) s1 += ('a' + i);
        a[i] = 0;
      }
    }
    if (cond1) {
      res = s1 + res;
    }
    cond = true;
    for (i = 0; i < n; i++) {
      if (i == 0) {
        if (abs(res[i] - res[i + 1]) == 1) cond = false;
      } else if (abs(res[i] - res[i - 1]) == 1)
        cond = false;
    }
    if (cond == false)
      cout << "No answer"
           << "\n";
    else
      cout << res << "\n";
  }
  return 0;
}
