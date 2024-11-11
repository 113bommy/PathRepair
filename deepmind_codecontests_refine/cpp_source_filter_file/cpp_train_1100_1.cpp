#include <bits/stdc++.h>
using namespace std;
const int nmax = 200009;
vector<int> g[nmax];
int len[nmax], answer, i, n, a, b, root, used[nmax], now[nmax];
bool solve(int act, int up) {
  int flag = 1, leave = 1, nr = 0, sum = 0;
  vector<int> now;
  for (int i = 0; i < g[act].size(); ++i) {
    int nxt = g[act][i];
    if (nxt == up) continue;
    if (!solve(nxt, act)) return 0;
    now.push_back(len[nxt]);
    leave = 0;
  }
  if (leave) {
    len[act] = 1;
    return 1;
  }
  for (int i = 0; i < now.size(); ++i) {
    if (used[now[i]]) continue;
    used[now[i]] = 1;
    nr++;
    sum += now[i];
  }
  for (int i = 0; i < now.size(); ++i) used[now[i]] = 0;
  if (act == root) {
    if (nr == 1) {
      len[act] = 1 + sum;
      return 1;
    } else {
      if (nr == 2) {
        len[act] = 1 + sum;
        return 1;
      } else
        return 0;
    }
  } else {
    if (nr == 1) {
      len[act] = 1 + sum;
      return 1;
    } else
      return 0;
  }
}
bool compare(int a, int b) { return g[a].size() < g[b].size(); }
int main() {
  scanf("%d", &n);
  for (i = 2; i <= n; ++i) {
    scanf("%d", &a);
    scanf("%d", &b);
    g[a].push_back(b);
    g[b].push_back(a);
  }
  answer = n + 1;
  for (i = 1; i <= n; ++i) now[i] = i;
  sort(now + 1, now + n + 1, compare);
  for (i = 1; i <= min(20, n); ++i) {
    root = now[i];
    if (solve(root, 0)) {
      int x = len[root];
      while (1 < x && x % 2 == 1) x = (1 + x) / 2;
      answer = min(answer, x);
    }
  }
  if (answer == n + 1) answer = 0;
  printf("%d\n", answer - 1);
  return 0;
}
