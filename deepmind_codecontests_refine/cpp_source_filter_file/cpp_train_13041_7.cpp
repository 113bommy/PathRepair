#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
int dp[MAXN];
char nxt[MAXN];
string soln[MAXN];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  s += '#';
  vector<pair<char, int> > v;
  v.emplace_back(s[n], 1);
  nxt[n] = '#';
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] != v.back().first) v.emplace_back(s[i], 0);
    v.back().second++;
    int j = i + v.back().second;
    if (dp[j] == 0) {
      if ((j - i) % 2) {
        dp[i] = 1;
        soln[i] += s[i];
      } else {
        dp[i] = 0;
      }
      nxt[i] = '#';
    } else {
      if (s[i] < soln[j][0]) {
        dp[i] = dp[j] + j - i;
        soln[i] += string(min(j - i, 5), s[i]);
        soln[i] += soln[j];
        nxt[i] = soln[j][0];
      } else if (s[i] > soln[j][0]) {
        if ((j - i) % 2) {
          dp[i] = dp[j] + 1;
          soln[i] += s[i];
          soln[i] += soln[j];
          nxt[i] = soln[j][0];
        } else {
          dp[i] = dp[j];
          soln[i] = soln[j];
          nxt[i] = nxt[j];
        }
      } else {
        if (s[i] < nxt[j]) {
          dp[i] = dp[j] + j - i;
          soln[i] += string(min(j - i, 5), s[i]);
          soln[i] += soln[j];
        } else if (s[i] > nxt[j]) {
          if ((j - i) % 2) {
            dp[i] = dp[j] + 1;
            soln[i] += s[i];
            soln[i] += soln[j];
          } else {
            dp[i] = dp[j];
            soln[i] = soln[j];
          }
        } else {
          assert(false);
        }
        nxt[i] = nxt[j];
      }
    }
    if (soln[i].size() > 10) {
      soln[i] =
          soln[i].substr(0, 5) + "..." + soln[i].substr(soln[i].size() - 2);
    }
  }
  for (int i = 0; i < n; i++) {
    cout << dp[i] << " " << soln[i] << "\n";
  }
  return 0;
}
