#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> E[1010101];
vector<int> src, sink;
int in[1010101], out[1010101];
int reachable[1010101];
void solve() {
  int i, j, k, l, r, x, y;
  string s;
  cin >> N >> M;
  for (i = 0; i < (M); i++) {
    cin >> x >> y;
    E[y - 1].push_back(x - 1);
    in[y - 1]++;
    out[x - 1]++;
  }
  for (i = 0; i < (N); i++) {
    if (in[i] == 0) src.push_back(i);
    if (out[i] == 0) sink.push_back(i);
  }
  for (i = 0; i < (sink.size()); i++) {
    queue<int> Q;
    Q.push(sink[i]);
    reachable[sink[i]] |= 1 << i;
    while (Q.size()) {
      x = Q.front();
      Q.pop();
      for (auto& e : E[x])
        if ((reachable[e] & (1 << i)) == 0) {
          reachable[e] |= 1 << i;
          Q.push(e);
        }
    }
  }
  for (int mask = 0; mask < 1 << src.size(); mask++) {
    int tmask = 0;
    for (i = 0; i < (src.size()); i++)
      if (mask & (1 << i)) tmask |= reachable[src[i]];
    if (__builtin_popcount(mask) > __builtin_popcount(tmask))
      return (void)printf("NO\n");
  }
  return (void)printf("YES\n");
}
int main(int argc, char** argv) {
  string s;
  int i;
  if (argc == 1) ios::sync_with_stdio(false), cin.tie(0);
  for (i = 0; i < (argc - 1); i++) s += argv[i + 1], s += '\n';
  for (i = 0; i < (s.size()); i++) ungetc(s[s.size() - 1 - i], stdin);
  cout.tie(0);
  solve();
  return 0;
}
