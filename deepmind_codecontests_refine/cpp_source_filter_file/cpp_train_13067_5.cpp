#include <bits/stdc++.h>
using namespace std;
const int MAXM = 2e5 + 7;
int d, n, m;
int x[MAXM], p[MAXM], id[MAXM];
priority_queue<pair<int, int>, vector<pair<int, int> >,
               greater<pair<int, int> > >
    f;
priority_queue<pair<int, int>, vector<pair<int, int> >,
               greater<pair<int, int> > >
    dis;
bool cmp(int a, int b) { return x[a] < x[b]; }
int main() {
  scanf("%d%d%d", &d, &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x[i], &p[i]);
    id[i] = i;
  }
  sort(id + 1, id + 1 + m, cmp);
  for (int i = 1; i <= m; i++) {
    int ii = id[i];
    dis.push(make_pair(x[ii], ii));
  }
  dis.push(make_pair(4, 0));
  dis.push(make_pair(d, 0));
  f.push(make_pair(0, 0));
  int gx = 0;
  long long gc = 0;
  while (!dis.empty()) {
    pair<int, int> td = dis.top();
    dis.pop();
    int tx = td.first;
    int tid = td.second;
    while (!f.empty() && tx > x[f.top().second] + n) {
      f.pop();
    }
    if (f.empty()) {
      printf("-1");
      return 0;
    }
    gc += ((long long)(tx - gx)) * ((long long)(f.top().first));
    if (tx == d) {
      break;
    }
    gx = tx;
    if (tid) {
      dis.push(make_pair(x[tid] + n, 0));
      f.push(make_pair(p[tid], tid));
    }
  }
  printf("%lld", gc);
  return 0;
}
