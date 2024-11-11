#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;
priority_queue<int, vector<int>, greater<int> > pq;
vector<int> v[300000];
int n, q, t;
int rotn[300000], dist[300000], mav[300000], pa[300000];
int ans[300000], pp[300000];
int pre(int o, int di) {
  dist[o] = di;
  pp[o] = o;
  int sum = 0;
  for (int i = 0; i < (int)(v[o]).size(); i++) {
    int t = pre(v[o][i], di + 1);
    mav[o] = max(mav[o], t);
    sum += t;
  }
  return rotn[o] = sum + 1;
}
void go(int o) {
  for (int i = 0; i < (int)(v[o]).size(); i++) {
    go(v[o][i]);
    if (dist[pp[o]] > dist[pa[pp[v[o][i]]]]) pp[o] = pa[pp[v[o][i]]];
  }
  int t = pp[o];
  while ((rotn[t] - rotn[o]) * 2 <= rotn[t]) {
    if (mav[o] * 2 <= rotn[t]) {
      ans[t] = o;
      pp[o] = t;
    }
    if (t == 0) break;
    t = pa[t];
  }
}
int main() {
  memset(ans, -1, sizeof(ans));
  scanf("%d %d", &n, &q);
  for (int i = 1; i < n; i++) {
    scanf("%d", &t);
    v[--t].push_back(i);
    pa[i] = t;
  }
  pre(0, 0);
  go(0);
  while (q--) {
    scanf("%d", &t);
    t--;
    printf("%d\n", ans[t] + 1);
  }
}
