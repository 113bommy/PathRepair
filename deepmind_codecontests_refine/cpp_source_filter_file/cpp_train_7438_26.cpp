#include <bits/stdc++.h>
using namespace std;
using namespace std;
const int mod = (int)1e9 + 7;
const long long INF = (long long)(1e18);
const int N = 100005;
int n, r;
pair<int, int> x[3005];
int sz = 0;
bool cmp(pair<int, int> x, pair<int, int> y) {
  return (x.first * x.first + x.second * x.second >
          y.first * y.first + y.second * y.second);
}
vector<pair<int, int> > now, out;
int res = 0;
void rec(int v) {
  if ((int)now.size() == n) {
    long long x = 0;
    for (int(i) = 0; (i) < ((int)now.size()); ++(i))
      for (int(j) = 0; (j) < (i); ++(j)) {
        x += (now[i].first - now[j].first) * (now[i].first - now[j].first) +
             (now[i].second - now[j].second) * (now[i].second - now[j].second);
      }
    if (x > res) {
      res = x;
      out = now;
    }
    return;
  }
  if (v == sz) {
    return;
  }
  now.push_back(x[v]);
  rec(v);
  now.pop_back();
  rec(v + 1);
}
int main() {
  scanf("%d %d", &n, &r);
  for (int i = -100; i <= 100; ++i) {
    for (int j = -100; j <= 100; ++j) {
      int val = i * i + j * j;
      if (val <= r * r) {
        x[sz++] = make_pair(i, j);
      }
    }
  }
  sort(x, x + sz, cmp);
  sz = min(sz, 15);
  rec(0);
  cout << res << "\n";
  for (int(i) = 0; (i) < ((int)out.size()); ++(i)) {
    printf("%d %d\n", out[i].first, out[i].second);
  }
  return 0;
}
