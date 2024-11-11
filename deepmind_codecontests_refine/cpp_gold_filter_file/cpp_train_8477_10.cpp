#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e5 + 10;
const long long SQ = 340;
vector<int> e[MAXN];
vector<pair<long long, long long> > d[SQ];
int a[MAXN];
int b[MAXN];
int k[SQ][SQ];
int p[SQ];
int lazy[SQ];
void relax(long long id) {
  p[id] = 0;
  d[id].clear();
  d[id].push_back(make_pair(0, 0));
  k[id][0] += lazy[id];
  for (long long i = 1; i < SQ; i++) {
    k[id][i] += lazy[id];
    while (!d[id].empty()) {
      long long t =
          max(0LL, (long long)(ceil(((k[id][d[id].back().second] - k[id][i]) *
                                         (id * SQ + d[id].back().second) -
                                     k[id][i] * (i - d[id].back().second)) /
                                    (long double)(i - d[id].back().second))));
      if (d[id].back().first >= t) {
        d[id].pop_back();
      } else {
        break;
      }
    }
    if (d[id].empty()) {
      d[id].push_back(make_pair(0, i));
    } else {
      d[id].push_back(make_pair(
          max(0LL, (long long)(ceil(((k[id][d[id].back().second] - k[id][i]) *
                                         (id * SQ + d[id].back().second) -
                                     k[id][i] * (i - d[id].back().second)) /
                                    (long double)(i - d[id].back().second)))),
          i));
    }
  }
  lazy[id] = 0;
}
void update(int r) {
  for (int i = 0; (i + 1) * SQ - 1 < r; i++) {
    lazy[i]++;
    while (p[i] != (long long)(d[i].size()) - 1 &&
           d[i][p[i] + 1].first <= lazy[i]) {
      p[i]++;
    }
  }
  for (int i = (r / SQ) * SQ; i <= r; i++) {
    k[r / SQ][i - ((r / SQ) * SQ)]++;
  }
  relax(r / SQ);
  return;
}
pair<long long, long long> get_ans() {
  pair<long long, long long> res = make_pair(0, 0);
  for (long long i = 0; i < SQ; i++) {
    res = max(res, make_pair((d[i][p[i]].second + i * SQ) *
                                 (k[i][d[i][p[i]].second] + lazy[i]),
                             i * SQ + d[i][p[i]].second));
  }
  return res;
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  long long n, w;
  cin >> n >> w;
  for (int i = 0; i < SQ; i++) {
    p[i] = 0;
    d[i].push_back(make_pair(0, SQ - 1));
  }
  int z = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    e[b[i]].push_back(i);
    z = max(z, b[i]);
  }
  long long num = n;
  for (int i = 0; i <= z + 1; i++) {
    pair<long long, long long> res = get_ans();
    cout << res.first + num * i * w << " " << res.second << endl;
    for (int j = 0; j < e[i].size(); j++) {
      update(a[e[i][j]]);
      num--;
    }
  }
}
