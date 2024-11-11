#include <bits/stdc++.h>
const int N = 1e3 + 10;
const int M = 1e5 + 10;
using namespace std;
struct Operator {
  int opr;
  int i, j, k;
  Operator() {}
  Operator(int Opr, int x) {
    if (Opr == 3) opr = 3, i = x;
    if (Opr == 4) opr = 4, k = x;
  }
  Operator(int Opr, int x, int y) {
    opr = Opr;
    i = x;
    j = y;
  }
};
vector<pair<int, Operator> > tr[M];
int n, m, q;
int tot = 0;
int num[N];
bool sign[N];
bool vis[N][N];
int ans[M];
void init() {
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i <= q; i++) {
    int Opr, x, y, pre = i - 1;
    scanf("%d", &Opr);
    if (Opr == 1 || Opr == 2) {
      scanf("%d %d", &x, &y);
      tr[pre].push_back(make_pair(i, Operator(Opr, x, y)));
    } else {
      scanf("%d", &x);
      if (Opr == 4) pre = x;
      tr[pre].push_back(make_pair(i, Operator(Opr, x)));
    }
  }
}
void dfs(int x) {
  int pretot = tot;
  for (int j = 0; j < tr[x].size(); j++) {
    int nxt = tr[x][j].first;
    Operator op = tr[x][j].second;
    if (op.opr == 1) {
      if (!(sign[op.i] ^ vis[op.i][op.j])) {
        vis[op.i][op.j] = !vis[op.i][op.j];
        tot++;
        num[op.i]++;
        ans[nxt] = tot;
        dfs(nxt);
        tot--;
        num[op.i]--;
        vis[op.i][op.j] = !vis[op.i][op.j];
      } else {
        ans[nxt] = tot;
        dfs(nxt);
      }
    }
    if (op.opr == 2) {
      if ((sign[op.i] ^ vis[op.i][op.j])) {
        vis[op.i][op.j] = !vis[op.i][op.j];
        tot--;
        num[op.i]--;
        ans[nxt] = tot;
        dfs(nxt);
        tot++;
        num[op.i]++;
        vis[op.i][op.j] = !vis[op.i][op.j];
      } else {
        ans[nxt] = tot;
        dfs(nxt);
      }
    }
    if (op.opr == 3) {
      tot -= num[op.i];
      num[op.i] = m - num[op.i];
      tot += num[op.i];
      sign[op.i] = !sign[op.i];
      ans[nxt] = tot;
      dfs(nxt);
      tot = pretot;
      num[op.i] = m - num[op.i];
      sign[op.i] = !sign[op.i];
    }
    if (op.opr == 4) {
      ans[nxt] = tot;
      dfs(nxt);
    }
  }
}
void work() {
  dfs(0);
  for (int i = 1; i <= q; i++) {
    printf("%d\n", ans[i]);
  }
}
int main() {
  init();
  work();
  return 0;
}
