#include <bits/stdc++.h>
using namespace std;
int n, cnt, cnto, cnte, cntA, fo, one[105000];
struct node {
  int u, v, uu, vv;
} edge[105000], ans[105000];
map<pair<int, int>, int> R;
void rev(int x, int y) {
  int z = R[make_pair(x, y)], K, k, fk;
  for (int i = 1; i <= cnte; i++) {
    if (edge[i].u == x) {
      if (R[make_pair(min(y, edge[i].v), max(y, edge[i].v))] &&
          edge[i].v != 1) {
        K = edge[i].v;
      }
    } else if (edge[i].v == x) {
      if (R[make_pair(min(y, edge[i].u), max(y, edge[i].u))] &&
          edge[i].u != 1) {
        K = edge[i].u;
      }
    }
  }
  fo++;
  cnt++;
  cntA++;
  one[fo + cnto] = edge[z].v = K;
  edge[z].u = 1;
  ans[cnt].u = x;
  ans[cnt].v = y;
  ans[cnt].uu = 1;
  ans[cnt].vv = K;
  R[make_pair(x, y)] = 0;
  R[make_pair(1, K)] = z;
}
void init() {
  int U, V;
  for (int i = 1; i <= n - 3; i++) {
    cin >> U >> V;
    if (U > V) swap(U, V);
    cnte++;
    if (U == 1) {
      cnto++;
      one[cnto] = V;
    }
    edge[cnte].u = U;
    edge[cnte].v = V;
    R[make_pair(U, V)] = cnte;
  }
}
void Re() {
  cnto = 2;
  fo = cnte = cntA = 0;
  R.clear();
  one[1] = 2;
  one[2] = n;
  for (int i = 1; i < n; i++) {
    cnte++;
    edge[cnte].u = i;
    edge[cnte].v = i + 1;
    R[make_pair(edge[cnte].u, edge[cnte].v)] = cnte;
  }
  cnte++;
  edge[cnte].u = 1;
  edge[cnte].v = n;
  R[make_pair(1, n)] = cnte;
}
void done() {
  Re();
  init();
  while (cnto < n - 1) {
    fo = 0;
    sort(one + 1, one + 1 + cnto);
    for (int i = 2; i <= cnto; i++) {
      if (one[i] - one[i - 1] > 1) {
        rev(one[i - 1], one[i]);
      }
    }
    cnto += fo;
  }
}
int main() {
  cin >> n;
  done();
  done();
  cout << cnt << endl;
  for (int i = 1; i <= cnt - cntA; i++) {
    cout << ans[i].u << ' ' << ans[i].v << endl;
  }
  for (int i = cnt; i >= cnt - cntA + 1; i--) {
    cout << ans[i].uu << ' ' << ans[i].vv << endl;
  }
  return 0;
}
