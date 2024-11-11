#include <bits/stdc++.h>
using namespace std;
int m, n, ro, num, li[100010];
long long dp[100010][110][2];
string s1, s2, s3;
struct Info {
  int so[10], fi, ro;
} t[100010];
void add(int &nu, int no, int r) {
  if (!nu) nu = ++num;
  if (no > r)
    t[nu].ro = 1;
  else
    add(t[nu].so[s1[no] - '0'], no + 1, r);
}
void init() {
  for (int i = 0; i + (m / 2) - 1 < n; i++) add(ro, i, i + (m / 2 - 1));
  int l = 1, r = 1;
  li[l] = 1;
  while (l <= r) {
    for (int i = 0; i < 10; i++) {
      int x = t[li[l]].so[i];
      if (x) {
        li[++r] = x;
        if (l == 1)
          t[x].fi = 1;
        else {
          int y = t[li[l]].fi;
          while (y != 1 && t[y].so[i] == 0) y = t[y].fi;
          if (t[y].so[i])
            t[x].fi = t[y].so[i];
          else
            t[x].fi = 1;
        }
      }
    }
    l++;
  }
  for (int i = 0; i < 10; i++)
    if (t[1].so[i] == 0) t[1].so[i] = 1;
  t[1].fi = 1;
  for (int i = 2; i <= num; i++) {
    int x = li[i];
    if (t[x].ro)
      for (int j = 0; j < 10; j++) t[x].so[j] = x;
    else
      for (int j = 0; j < 10; j++)
        if (t[x].so[j] == 0) t[x].so[j] = t[t[x].fi].so[j];
  }
}
void add(long long &x, long long y) { x = (x + y) % 1000000007; }
long long que(string s) {
  memset(dp, 0, sizeof(dp));
  dp[0][1][1] = 1;
  for (int i = 0; i < m; i++) {
    for (int j = 1; j <= num; j++) {
      for (int ne = 0; ne < 10; ne++) {
        add(dp[i + 1][t[j].so[ne]][0], dp[i][j][0]);
        if (ne < s[i] - '0') add(dp[i + 1][t[j].so[ne]][0], dp[i][j][1]);
        if (ne == s[i] - '0') add(dp[i + 1][t[j].so[ne]][1], dp[i][j][1]);
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= num; i++)
    if (t[i].ro) add(ans, dp[m][i][0] + dp[m][i][1]);
  return ans;
}
void dec(string &s) {
  for (int i = m - 1; i >= 0; i--) {
    if (s[i] == '0')
      s[i] = '9';
    else {
      s[i]--;
      return;
    }
  }
}
int main() {
  cin >> s1 >> s2 >> s3;
  n = s1.length(), m = s2.length();
  dec(s2);
  init();
  cout << (que(s3) - que(s2) + 1000000007) % 1000000007 << endl;
  return 0;
}
