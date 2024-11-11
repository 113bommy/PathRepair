#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000 + 23;
string s, ss;
int word[maxn], ans, a[maxn], last, l, r, len, html[maxn], type[maxn],
    dad[maxn], x, size, n, m, node;
map<string, int> M;
char c;
vector<int> G[maxn];
void init(int k) {
  while (x < n) {
    x++;
    if (type[x] == 1) return;
    if (type[x] == 2) G[k].push_back(++size), word[size] = html[x];
    if (type[x] == 0) {
      G[k].push_back(++size), word[size] = html[x];
      init(size);
    }
  }
}
void search(int k, int x) {
  for (int j = 0; j <= (int)(G[k].size()) - 1; j++) {
    int v = G[k][j];
    if (word[v] == a[x + 1]) {
      if (x == size - 1)
        ans++, search(v, x);
      else
        search(v, x + 1);
    } else
      search(v, x);
  }
}
int main() {
  cin >> s;
  len = s.length(), last = 0, n = 0, node = 0;
  while (last < (len - 1)) {
    l = last + 1, r = l, n++;
    while (s[r + 1] != '>') r++;
    type[n] = 0;
    ss = s.substr(l, r - l + 1);
    if (ss[0] == '/') type[n] = 1, ss = ss.substr(1, ss.length() - 1);
    if (ss[ss.length() - 1] == '/')
      type[n] = 2, ss = ss.substr(0, ss.length() - 1);
    if (M.count(ss) == 0) M[ss] = ++node;
    html[n] = M[ss], last = r + 2;
  }
  x = 0, size = 0;
  init(0);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    size = 0, ans = 0;
    while (true) {
      cin >> s;
      a[++size] = M[s];
      if ((c = getchar()) != ' ') break;
    }
    search(0, 0);
    printf("%d\n", ans);
  }
  return 0;
}
