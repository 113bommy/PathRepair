#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
string s;
vector<int> Z[10];
void zalgo(int x) {
  Z[x].resize(s.size());
  int L = 0, R = 0;
  for (int i = 1; i < s.size(); i++) {
    if (i > R) {
      L = R = i;
      while (R < s.size() && s[R - L] == s[R]) R++;
      Z[x][i] = R - L;
      R--;
    } else {
      int k = i - L;
      if (Z[x][k] < R - i + 1)
        Z[x][i] = Z[x][k];
      else {
        L = i;
        while (R < s.size() && s[R - L] == s[R]) R++;
        Z[x][i] = R - L;
        R--;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string t;
  int N;
  cin >> t >> N;
  vector<string> ss(N);
  for (int i = 0; i < N; i++) cin >> ss[i];
  for (int i = 0; i < N; i++) {
    s = ss[i] + t;
    zalgo(i);
  }
  pair<int, int> res = {0, 0};
  for (int i = 0, j = 0; i < (int)t.size(); j = i) {
    int last = -1;
    while (j < (int)t.size()) {
      bool can = true;
      for (int i = 0; i < N; i++) {
        can &= Z[i][j + ss[i].size()] < ss[i].size();
        if (Z[i][j + ss[i].size()] >= ss[i].size()) last = i;
      }
      if (can)
        j++;
      else
        break;
    }
    if (j == t.size()) {
      res = max(res, {j - i, i});
      break;
    }
    int en = j + ss[last].size() - 1;
    for (int k = j; k < j + ss[last].size(); k++) {
      for (int i = 0; i < N; i++) {
        if (i == last) continue;
        if (Z[i][k + ss[i].size()] < ss[i].size()) continue;
        en = min(en, k + (int)ss[i].size() - 1);
      }
    }
    res = max(res, {en - i, i});
    i = j + 1;
  }
  cout << res.first << ' ' << res.second << '\n';
  return 0;
}
