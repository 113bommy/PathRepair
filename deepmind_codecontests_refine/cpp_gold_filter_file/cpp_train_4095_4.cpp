#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
const int N = 100010;
const int MAXN = 201, MOD = 1e9 + 7, sigma = 26;
int term[MAXN], len[MAXN], to[MAXN][sigma], link[MAXN], sz = 1;
void add_str(string s) {
  int cur = 0;
  for (auto c : s) {
    if (!to[cur][c - 'a']) {
      to[cur][c - 'a'] = sz++;
      len[to[cur][c - 'a']] = len[cur] + 1;
    }
    cur = to[cur][c - 'a'];
  }
  term[cur] = cur;
}
void push_links() {
  int que[sz];
  int st = 0, fi = 1;
  que[0] = 0;
  while (st < fi) {
    int V = que[st++];
    int U = link[V];
    if (!term[V]) term[V] = term[U];
    for (int c = 0; c < sigma; c++)
      if (to[V][c]) {
        link[to[V][c]] = V ? to[U][c] : 0;
        que[fi++] = to[V][c];
      } else {
        to[V][c] = to[U][c];
      }
  }
}
string str;
int k;
string s;
long long pd[N][200];
long long func(int pos, int x) {
  if (x && term[x]) return 0x3F3F3F3F3F3F3F3FLL;
  if (pos == str.size()) return 0LL;
  if (pd[pos][x] != -1) return pd[pos][x];
  return pd[pos][x] =
             min(func(pos + 1, x) + 1, func(pos + 1, to[x][str[pos] - 'a']));
}
int main() {
  ios::sync_with_stdio(0);
  cin >> str;
  cin >> k;
  for (int i = 0; i < k; ++i) {
    cin >> s;
    add_str(s);
    reverse(s.begin(), s.end());
    add_str(s);
  }
  push_links();
  memset(pd, -1, sizeof pd);
  cout << func(0, 0) << endl;
  return 0;
}
