#include <bits/stdc++.h>
using namespace std;
string str;
int v[3] = {0, 4, 7};
bool dp[32][256];
bool vis[32][256];
vector<int> sol[32][256];
bool calc(int i, int h) {
  if (i == str.size()) return !h;
  if (!vis[i][h]) {
    vis[i][h] = true;
    sol[i][h].clear();
    dp[i][h] = false;
    for (int a = 0; a < 3; ++a)
      for (int b = 0; b < 3; ++b)
        for (int c = 0; c < 3; ++c)
          for (int d = 0; d < 3; ++d)
            for (int e = 0; e < 3; ++e)
              for (int f = 0; f < 3; ++f)
                if ((v[a] + v[b] + v[c] + v[d] + v[e] + v[f] + h) % 10 ==
                        str[i] - '0' &&
                    calc(i + 1,
                         (v[a] + v[b] + v[c] + v[d] + v[e] + v[f] + h) / 10)) {
                  sol[i][h].push_back(a);
                  sol[i][h].push_back(b);
                  sol[i][h].push_back(c);
                  sol[i][h].push_back(d);
                  sol[i][h].push_back(e);
                  sol[i][h].push_back(f);
                  return dp[i][h] = true;
                }
  }
  return dp[i][h];
}
string Sol[6];
void print(int i, int h) {
  if (i == str.size()) {
    return;
  }
  int x = h;
  for (int j = 0; j < sol[i][h].size(); ++j) {
    x += v[sol[i][h][j]];
    Sol[j] += v[sol[i][h][j]] + '0';
  }
  print(i + 1, x / 10);
}
long long tr(string &s) {
  long long r = 0;
  for (int i = 0; i < s.size(); ++i) r = r * 10 + s[i] - '0';
  return r;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> str;
    reverse(str.begin(), str.end());
    memset(vis, 0, sizeof(vis));
    if (calc(0, 0)) {
      print(0, 0);
      for (int i = 0; i < 6; ++i) {
        reverse(Sol[i].begin(), Sol[i].end());
        if (i) cout << " ";
        cout << tr(Sol[i]);
        Sol[i] = "";
      }
      cout << endl;
    } else
      cout << -1 << endl;
  }
  return 0;
}
