#include <bits/stdc++.h>
using namespace std;
map<string, int> q;
string s[5005];
int p1[5005], p2[5005], n, m, val[5005], p3[5005];
string ans1, ans2;
int solve(int x, int w) {
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (p3[i] == 0)
      val[i] = s[i][x] - '0';
    else {
      int w1 = 0, w2 = 0;
      if (p1[i] == -1 && p2[i] == -1)
        w1 = w, w2 = w;
      else if (p1[i] == -1)
        w1 = w, w2 = val[p2[i]];
      else
        w1 = val[p1[i]], w2 = val[p2[i]];
      if (p3[i] == 1)
        val[i] = w1 ^ w2;
      else if (p3[i] == 2)
        val[i] = w1 & w2;
      else
        val[i] = w1 | w2;
    }
    ans += val[i];
  }
  return ans;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    string a;
    cin >> a;
    q[a] = i;
    cin >> s[i];
    cin >> s[i];
    if (s[i][0] >= '0' && s[i][0] <= '1') continue;
    if (s[i][0] == '?')
      p1[i] = -1;
    else
      p1[i] = q[s[i]];
    cin >> s[i];
    if (s[i][0] == 'X')
      p3[i] = 1;
    else if (s[i][0] == 'A')
      p3[i] = 2;
    else
      p3[i] = 3;
    cin >> s[i];
    if (s[i][0] == '?')
      p2[i] = -1;
    else
      p2[i] = q[s[i]];
  }
  for (int i = 1; i <= n; ++i)
    if (p2[i] == -1) swap(p1[i], p2[i]);
  for (int i = 0; i < m; ++i) {
    int w1 = solve(i, 0), w2 = solve(i, 1);
    if (w1 <= w2)
      ans1 += '0';
    else
      ans1 += '1';
    if (w1 >= w2)
      ans2 += '0';
    else
      ans2 += '1';
  }
  cout << ans1 << endl << ans2;
}
