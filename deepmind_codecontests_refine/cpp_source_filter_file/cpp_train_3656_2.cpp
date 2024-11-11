#include <bits/stdc++.h>
using namespace std;
bool vis[5050][500];
const int maxn = 1000050;
int pre[maxn];
char c[maxn];
struct node {
  int s, d, idx;
};
int main() {
  int d, s;
  scanf("%d%d", &d, &s);
  queue<node> q;
  int tot = 0;
  for (int i = 1; i <= 9; ++i) {
    q.push({i, i % d, tot + 1}), ++tot, c[tot] = i + '0';
  }
  int Tail = -1;
  while (!q.empty()) {
    node u = q.front();
    q.pop();
    if (u.s == s && u.d == 0) {
      Tail = u.idx;
      break;
    }
    for (int i = 0; i <= 9; ++i) {
      int ns = u.s + i, nd = (u.d * 10 + i) % d;
      if (ns > s || vis[ns][nd]) continue;
      vis[ns][nd] = true;
      ++tot;
      c[tot] = i + '0';
      pre[tot] = u.idx;
      q.push({ns, nd, tot});
    }
  }
  if (Tail == -1) {
    puts("-1");
    return 0;
  }
  string ans;
  while (Tail) {
    ans = c[Tail] + ans;
    Tail = pre[Tail];
  }
  cout << ans << endl;
  return 0;
}
