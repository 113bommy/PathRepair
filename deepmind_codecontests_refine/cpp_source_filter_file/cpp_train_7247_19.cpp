#include <bits/stdc++.h>
using namespace std;
const int A = 4;
const int MOD = (int)1e9 + 7;
int n, m, k;
vector<string> s;
vector<string> p;
vector<int> covers;
vector<vector<int> > g;
int mem[1010][12][110];
int rec(int i, int j, int u) {
  if (mem[i][j][u] != -1) return mem[i][j][u];
  if (i == n) return mem[i][j][u] = j == 0 ? 1 : 0;
  if (j >= 10) return mem[i][j][u] = 0;
  int ret = 0;
  for (int c = 0; c < A; c++) {
    int nextU = g[u][c];
    int nextJ = (covers[nextU] >= j + 1) ? 0 : j + 1;
    ret += rec(i + 1, nextJ, nextU);
    ret %= MOD;
  }
  return mem[i][j][u] = ret;
}
int main() {
  cin >> n >> m;
  p.push_back("");
  s.resize(m);
  for (int i = 0; i < m; i++) {
    cin >> s[i];
    for (int j = 1; j <= s[i].length(); j++) {
      p.push_back(s[i].substr(0, j));
    }
  }
  k = p.size();
  g.resize(k);
  covers.resize(k);
  for (int i = 0; i < k; i++)
    for (int j = p[i].length() - 1; j >= 0; j--)
      if (find(s.begin(), s.end(), p[i].substr(j)) != s.end())
        covers[i] = p[i].length() - j;
  for (int i = 0; i < k; i++)
    for (char c = 'A'; c <= 'Z'; c++) {
      if (c != 'A' && c != 'G' && c != 'C' && c != 'T') continue;
      string t = p[i] + c;
      int maxLen = -1, bestJ = -1;
      for (int j = 0; j < k; j++) {
        if (p[j].size() > t.size()) continue;
        bool b1 = p[j] == t.substr(t.size() - p[j].size());
        bool b2 = (int)p[j].length() > maxLen;
        if (b1 && b2) {
          maxLen = p[bestJ = j].length();
        }
      }
      g[i].push_back(bestJ);
    }
  memset(mem, -1, sizeof(mem));
  cout << rec(0, 0, 0) << '\n';
  return 0;
}
