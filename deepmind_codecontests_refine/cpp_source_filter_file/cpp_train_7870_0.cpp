#include <bits/stdc++.h>
using namespace std;
long long c2(long long x) { return x * (x - 1) / 2; }
vector<int> fen;
void add(int i) {
  for (; i < fen.size(); i |= i + 1) fen[i]++;
}
int sum(int i) {
  int s = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) s += fen[i];
  return s;
}
void solve(vector<pair<int, int>> x, vector<array<int, 3>> q,
           vector<long long>& res) {
  sort(x.begin(), x.end());
  sort(q.begin(), q.end());
  fen.assign(x.size(), 0);
  int it = 0;
  for (int i = 0; i < q.size(); ++i) {
    while (it < x.size() && x[it].first < q[i][0]) {
      add(x[it].second);
      ++it;
    }
    res[q[i][2]] += c2(sum(q[i][1] - 1));
  }
}
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  vector<int> p(n);
  vector<pair<int, int>> x(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
    --p[i];
    x[i] = pair<int, int>(p[i], i);
  }
  vector<array<int, 3>> w[4];
  vector<long long> res(q, c2(n));
  for (int i = 0; i < q; ++i) {
    int lx, rx, ly, ry;
    scanf("%d%d%d%d", &lx, &ly, &rx, &ry);
    --lx;
    --rx;
    --ly;
    --ry;
    res[i] -= c2(lx) + c2(ly) + c2(n - rx - 1) + c2(n - ry - 1);
    w[0].push_back({lx, ly, i});
    w[1].push_back({lx, n - ry - 1, i});
    w[2].push_back({n - rx - 1, ly, i});
    w[3].push_back({n - rx - 1, n - ry - 1, i});
  }
  for (int t = 0; t < 4; ++t) {
    if (t >= 2) {
      for (int i = 0; i < x.size(); ++i) x[i].first = n - x[i].first - 1;
    }
    if (t % 2) {
      for (int i = 0; i < x.size(); ++i) x[i].second = n - x[i].second - 1;
    }
    solve(x, w[t], res);
    if (t >= 2) {
      for (int i = 0; i < x.size(); ++i) x[i].first = n - x[i].first - 1;
    }
    if (t % 2) {
      for (int i = 0; i < x.size(); ++i) x[i].second = n - x[i].second - 1;
    }
  }
  for (int i = 0; i < res.size(); ++i) {
    printf("%lld\n", res[i]);
  }
  return 0;
}
