#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 9;
const unsigned long long INF = 1e9 + 7;
const int base = 2e5 + 1;
const long long MAX = 1e15 + 1;
const double EPS = 1e-9;
const double PI = acos(-1.);
const int MAXN = 2 * 1e6 + 47;
struct vertex {
  int next[26];
  int d;
  bool win, lose, leaf;
  vertex() {
    d = 0;
    for (int i = (0); i < (26); ++i) next[i] = 0;
    leaf = 0;
    win = 0;
    lose = 0;
  }
} t[MAXN];
int sz = 0;
void add(string s) {
  int v = 0;
  for (int i = (0); i < ((int)s.size()); ++i) {
    int c = s[i] - 'a';
    if (!t[v].next[c]) {
      t[v].next[c] = sz++;
    }
    v = t[v].next[c];
  }
}
void dfs(int v) {
  int cnt = 0;
  for (int i = (0); i < (26); ++i) {
    if (t[v].next[i]) {
      int u = t[v].next[i];
      dfs(u);
      t[v].win |= !t[u].win;
      t[v].lose |= !t[u].lose;
      cnt++;
    }
  }
  if (cnt == 0) {
    t[v].win = 0;
    t[v].lose = 1;
  }
}
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = (0); i < (n); ++i) {
    string s;
    cin >> s;
    add(s);
  }
  dfs(0);
  if (!t[0].win) {
    cout << "Second";
  } else {
    if (t[0].lose) {
      cout << "First";
    } else {
      cout << (k % 2 ? "First" : "Second");
    }
  }
  return 0;
}
