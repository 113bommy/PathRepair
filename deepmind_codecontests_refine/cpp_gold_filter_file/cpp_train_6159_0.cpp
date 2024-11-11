#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
long long int n, m, q;
string c, s, t;
long long int dp[1010][55][55], indS[55][50], indT[55][50];
long long int maxSuffs, maxSufft;
vector<long long int> zf(string s) {
  long long int n = (long long int)s.size();
  vector<long long int> ans(n);
  long long int l = 0, r = 0;
  for (long long int i = 1; i < n; i++) {
    if (i <= r) {
      ans[i] = min(r - i + 1, ans[i - l]);
    }
    while (i + ans[i] < n && s[ans[i]] == s[i + ans[i]]) {
      ans[i] += 1;
    }
    if (i + ans[i] - 1 > r) {
      l = i;
      r = i + ans[i] - 1;
    }
  }
  return ans;
}
void upd(long long int i, long long int j, long long int k, char ch) {
  long long int inda = j, indb = k, summ = 0;
  if (s[j + 1] == ch) {
    if (inda + 1 == m - 1) {
      summ++;
      inda = maxSuffs;
    } else
      inda++;
  } else {
    if (ch != '#')
      inda = indS[j][ch - 'a'];
    else
      inda = 0;
  }
  if (t[k + 1] == ch) {
    if (indb + 1 == q - 1) {
      summ--;
      indb = maxSufft;
    } else
      indb++;
  } else {
    if (ch != '#')
      indb = indT[k][ch - 'a'];
    else
      indb = 0;
  }
  dp[i + 1][inda][indb] = max(dp[i + 1][inda][indb], dp[i][j][k] + summ);
}
void calcInd() {
  for (long long int j = 0; j < s.size(); j++) {
    for (char ch = 'a'; ch <= 'z'; ch++) {
      string l = s.substr(1, j + 1);
      string r = s.substr(1, j) + ch;
      string mask = l + "#" + r;
      vector<long long int> z = zf(mask);
      long long int ans = 0;
      for (long long int w = l.size() + 1; w < z.size(); w++) {
        if (w + z[w] == z.size()) {
          ans = z[w];
          break;
        }
      }
      indS[j][ch - 'a'] = ans;
    }
  }
  for (long long int j = 0; j < t.size(); j++) {
    for (char ch = 'a'; ch <= 'z'; ch++) {
      string l = t.substr(1, j + 1);
      string r = t.substr(1, j) + ch;
      string mask = l + "#" + r;
      vector<long long int> z = zf(mask);
      long long int ans = 0;
      for (long long int w = l.size() + 1; w < z.size(); w++) {
        if (w + z[w] == z.size()) {
          ans = z[w];
          break;
        }
      }
      indT[j][ch - 'a'] = ans;
    }
  }
}
void calcSuff() {
  string mask1 = s + "#" + s;
  string mask2 = t + "#" + t;
  vector<long long int> z1 = zf(mask1);
  vector<long long int> z2 = zf(mask2);
  maxSuffs = 0;
  maxSufft = 0;
  for (long long int i = s.size() + 2; i < z1.size(); i++) {
    if (i + z1[i] == mask1.size()) {
      maxSuffs = z1[i];
      break;
    }
  }
  for (long long int i = t.size() + 2; i < z2.size(); i++) {
    if (i + z2[i] == mask2.size()) {
      maxSufft = z2[i];
      break;
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> c >> s >> t;
  calcSuff();
  s = "#" + s;
  t = "#" + t;
  calcInd();
  n = c.size();
  m = s.size();
  q = t.size();
  for (long long int i = 0; i < n + 1; i++) {
    for (long long int j = 0; j < m; j++) {
      for (long long int w = 0; w < q; w++) dp[i][j][w] = -1e15;
    }
  }
  dp[0][0][0] = 0;
  if (c[0] == '*') {
    upd(0, 0, 0, '#');
    upd(0, 0, 0, s[1]);
    upd(0, 0, 0, t[1]);
  } else
    upd(0, 0, 0, c[0]);
  for (long long int i = 1; i < n; i++) {
    for (long long int j = 0; j < m - 1; j++) {
      for (long long int k = 0; k < q - 1; k++) {
        if (c[i] == '*') {
          upd(i, j, k, '#');
          upd(i, j, k, s[j + 1]);
          upd(i, j, k, t[k + 1]);
        } else
          upd(i, j, k, c[i]);
      }
    }
  }
  long long int ans = -1e15;
  for (long long int i = 0; i < m - 1; i++) {
    for (long long int j = 0; j < q - 1; j++) {
      ans = max(ans, dp[n][i][j]);
    }
  }
  cout << ans << "\n";
  return 0;
}
