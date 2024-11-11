#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:640000000")
using namespace std;
const double eps = 1e-9;
const double pi = acos(-1.0);
const int mod = (int)1e9 + 7;
string x, y;
int fre = 1;
int to[25000][10];
int go[25000][10];
int link[25000];
int dp[55][2][2][2][25000];
bool good[25000];
int d;
void add(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
void add_string(string s) {
  int cur = 0;
  for (int i = 0; i < (int)(s).size(); i++) {
    if (to[cur][s[i]] == -1) {
      to[cur][s[i]] = fre++;
    }
    cur = to[cur][s[i]];
  }
  good[cur] = true;
}
void build() {
  int cur = 0;
  queue<int> q;
  q.push(cur);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int i = 0; i < 10; i++)
      if (to[v][i] != -1) {
        int u = to[v][i];
        q.push(u);
        if (v == 0) continue;
        int c = link[v];
        while (c && to[c][i] == -1) c = link[c];
        if (to[c][i] != -1) c = to[c][i];
        link[u] = c;
      }
    for (int i = 0; i < 10; i++) {
      if (to[v][i] != -1) {
        go[v][i] = to[v][i];
      } else {
        go[v][i] = v == 0 ? 0 : go[link[v]][i];
      }
    }
  }
}
int get(int pos, int lo, int hi, int goo, int state) {
  if (pos == d) return goo;
  int &res = dp[pos][lo][hi][goo][state];
  if (res != -1) return res;
  res = 0;
  for (int i = 0; i < 10; i++) {
    if (lo == 0 && y[pos] < i) continue;
    if (hi == 0 && x[pos] > i) continue;
    int nxt = go[state][i];
    add(res, get(pos + 1, lo | (y[pos] > i), hi | (x[pos] < i), goo | good[nxt],
                 nxt));
  }
  return res;
}
int main() {
  string s;
  cin >> s;
  int n = (int)(s).size();
  for (int i = 0; i < n; i++) {
    s[i] -= '0';
  }
  cin >> x >> y;
  d = (int)(x).size();
  for (int i = 0; i < d; i++) {
    x[i] -= '0';
    y[i] -= '0';
  }
  if (n < d / 2) {
    cout << 0 << endl;
    return 0;
  }
  memset(to, -1, sizeof(to));
  for (int i = 0; i < n - d / 2 + 1; i++) {
    add_string(s.substr(i, d / 2));
  }
  build();
  memset(dp, -1, sizeof(dp));
  cout << get(0, 0, 0, 0, 0) << endl;
  return 0;
}
