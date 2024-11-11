#include <bits/stdc++.h>
using namespace std;
ostream cnull(NULL);
template <class TH>
void _dbg(const char *sdbg, TH h) {
  cnull << sdbg << "=" << h << "\n";
}
template <class TH, class... TA>
void _dbg(const char *sdbg, TH h, TA... a) {
  while (*sdbg != ',') cnull << *sdbg++;
  cnull << "=" << h << ",";
  _dbg(sdbg + 1, a...);
}
const int MX = 100007, D = 17, BLEP = 1 << D;
vector<pair<int, int> > in, ska;
map<pair<int, int>, int> mapa;
vector<int> pyt[MX];
vector<tuple<int, int, int> > queries[BLEP << 1];
stack<tuple<int, int, int, int, int> > rollback;
pair<int, int> kraw[MX];
bool odp[MX], F;
struct dsu {
  int rep[MX], roz[MX], dis[MX];
  void init() {
    for (int i = (0); i <= ((int)(MX)-1); ++i) rep[i] = i, roz[i] = 1;
  }
  int Find(int x, int &d) {
    d += dis[x];
    if (x != rep[x]) return Find(rep[x], d);
    return x;
  }
  bool Union(int a, int b) {
    int dA = 0, dB = 0;
    if ((a = Find(a, dA)) == (b = Find(b, dB))) {
      if ((dA + dB) % 2 == 0) F = 1;
      return 0;
    }
    if (roz[a] < roz[b]) swap(a, b);
    rollback.push({a, roz[a], b, dis[b], rep[b]});
    rep[b] = a;
    roz[a] += roz[b];
    dis[b] = dA + dB + 1;
    return 1;
  }
} FU;
void dnc(int v, int l, int r) {
  int m = (l + r) / 2;
  int ops = 0;
  bool cykl = F;
  for (auto q : queries[v]) {
    int a = get<0>(q), b = get<1>(q), nrk = get<2>(q);
    if (l >= a && r <= b) {
      int x = kraw[nrk].first, y = kraw[nrk].second;
      ops += FU.Union(x, y);
    } else if (l < r) {
      if (a <= m) queries[2 * v].push_back(q);
      if (b > m) queries[2 * v + 1].push_back(q);
    }
  }
  if (l == r && l < MX)
    odp[l] = F;
  else if (l < r) {
    dnc(2 * v, l, m);
    dnc(2 * v + 1, m + 1, r);
  }
  for (int i = (0); i <= ((int)(ops)-1); ++i) {
    int a = get<0>(rollback.top()), rozA = get<1>(rollback.top()),
        b = get<2>(rollback.top()), kolB = get<3>(rollback.top()),
        repB = get<4>(rollback.top());
    FU.rep[b] = repB;
    FU.roz[a] = rozA;
    FU.dis[b] = kolB;
    rollback.pop();
  }
  F = cykl;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = (1); i <= (q); ++i) {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    in.push_back({a, b});
  }
  ska = in;
  sort((ska).begin(), (ska).end());
  ska.resize(distance(ska.begin(), unique((ska).begin(), (ska).end())));
  for (int i = (0); i <= ((int)(((int)(ska).size())) - 1); ++i) {
    mapa[ska[i]] = i + 1;
    kraw[i + 1] = ska[i];
  }
  for (int i = (0); i <= ((int)(q)-1); ++i) pyt[mapa[in[i]]].push_back(i + 1);
  int m = ((int)(ska).size());
  for (int i = (1); i <= (m); ++i) {
    if (((int)(pyt[i]).size()) % 2 == 1) pyt[i].push_back(q + 1);
    for (int j = (0); j <= ((int)(((int)(pyt[i]).size())) - 1); ++j)
      if (j % 2 == 0) queries[1].push_back({pyt[i][j], pyt[i][j + 1] - 1, i});
  }
  FU.init();
  dnc(1, 0, BLEP - 1);
  for (int i = (1); i <= (q); ++i) cout << (odp[i] ? "NO" : "YES") << '\n';
}
