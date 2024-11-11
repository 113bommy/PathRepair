#include <bits/stdc++.h>
using namespace std;
const int N = 101000;
const long long inf = (1LL << 55);
int n, x[N], p[N];
long long dt[N][2];
long long d[N][3];
vector<int> v[N];
void calc(int nod) {
  vector<int>::iterator it;
  int i;
  if (!v[nod].size()) {
    d[nod][0] = x[nod];
    d[nod][1] = 0;
    d[nod][2] = -inf;
    return;
  }
  for (it = v[nod].begin(); it != v[nod].end(); ++it) calc(*it);
  dt[v[nod].size()][0] = 0;
  dt[v[nod].size()][1] = -inf;
  for (i = v[nod].size() - 1; i >= 0; --i) {
    int el = v[nod][i];
    long long aa = max(dt[i + 1][1] + d[el][2], dt[i + 1][1] + d[el][0]);
    dt[i][0] = max(dt[i + 1][0] + d[el][1], aa);
    aa = max(dt[i + 1][0] + d[el][2], dt[i + 1][0] + d[el][0]);
    dt[i][1] = max(dt[i + 1][1] + d[el][1], aa);
  }
  d[nod][0] = dt[0][0] + x[nod];
  d[nod][1] = dt[0][0];
  d[nod][2] = dt[0][1];
}
int main() {
  int i;
  cin >> n;
  for (i = 1; i <= n; ++i) {
    cin >> p[i] >> x[i];
    if (i != 1) v[p[i]].push_back(i);
  }
  calc(1);
  cout << max(d[1][0], max(d[1][1], d[1][2]));
  return 0;
}
