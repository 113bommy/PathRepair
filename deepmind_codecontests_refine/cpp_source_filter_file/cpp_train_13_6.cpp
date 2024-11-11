#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int w = 1, s = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    s = s * 10 + ch - '0';
    ch = getchar();
  }
  return w * s;
}
int n, m, h[1001000], Sum[1010010], Sg[1010010], tag[1010010], du[1010010],
    Seq[1010000], cnt;
vector<int> vec[1010100];
queue<int> q;
inline void Top_Sort() {
  for (register int i = 1; i <= n; ++i)
    if (!du[i]) q.push(i), Seq[++cnt] = i;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto x : vec[u]) {
      du[x]--;
      if (!du[x]) q.push(x), Seq[++cnt] = x;
    }
  }
}
int main() {
  n = read(), m = read();
  for (register int i = 1; i <= n; ++i) h[i] = read();
  for (register int i = 1; i <= m; ++i) {
    int u = read(), v = read();
    vec[u].push_back(v);
    du[v]++;
  }
  Top_Sort();
  for (register int i = n; i >= 1; --i) {
    int u = Seq[i];
    for (auto x : vec[u]) {
      tag[Sg[x]] = i;
    }
    while (tag[Sg[u]] == i) Sg[u]++;
    Sum[Sg[u]] ^= h[u];
  }
  for (register int i = n; i >= 1; --i) {
    if (Sum[i]) {
      int xx = 0;
      for (register int j = 1; j <= n; ++j)
        if ((Sg[j] == i) && (h[j] > (h[j] ^ Sum[i]))) xx = j;
      h[xx] = h[xx] ^ Sum[i];
      for (auto x : vec[xx]) h[x] = Sum[Sg[x]] ^ h[x], Sum[Sg[x]] = 0;
      cout << "Win\n";
      for (register int i = 1; i <= n; ++i) cout << h[i] << " ";
      exit(0);
    }
  }
  cout << "Lose\n";
  return 0;
}
