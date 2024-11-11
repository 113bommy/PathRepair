#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
struct oper {
  pair<int, int> from, to;
  oper(const pair<int, int> &f, const pair<int, int> &t) : from(f), to(t) {}
};
ostream &operator<<(ostream &os, const pair<int, int> &p) {
  return os << p.first << " " << p.second;
}
ostream &operator<<(ostream &os, const oper &op) {
  return os << op.from << " " << op.to << "\n";
}
int n, m;
vector<pair<int, int> > S;
vector<oper> OP[2];
int vis[100][100];
int cnt;
void movex(int i, int x) {
  int dir = S[i].first < x ? 1 : -1;
  while (S[i].first != x) {
    pair<int, int> next = S[i];
    next.first += dir;
    if (vis[next.first][next.second]) break;
    vis[next.first][next.second] = 1;
    vis[S[i].first][S[i].second] = 0;
    OP[cnt].emplace_back(S[i], next);
    S[i] = next;
  }
}
void movey(int i, int y) {
  int dir = S[i].second < y ? 1 : -1;
  while (S[i].second != y) {
    pair<int, int> next = S[i];
    next.second += dir;
    if (vis[next.first][next.second]) break;
    vis[next.first][next.second] = 1;
    vis[S[i].first][S[i].second] = 0;
    OP[cnt].push_back(oper(S[i], next));
    S[i] = next;
  }
}
void f() {
  memset(vis, 0, sizeof vis);
  for (int i = 0; i < (m); ++i) {
    cin >> S[i].first >> S[i].second;
    vis[S[i].first][S[i].second] = 1;
  }
  vector<int> V(m);
  for (int i = 0; i < (m); ++i) V[i] = i;
  sort(V.begin(), V.end(), [&](int x, int y) { return S[x] < S[y]; });
  for (int i = 0; i < (m); ++i) {
    for (int j = 0; j < (m); ++j) movex(V[j], j + 1);
  }
  for (int i = 0; i < (m); ++i) movey(i, i + 1);
  for (int i = 0; i < (m); ++i) movex(i, i + 1);
  ++cnt;
}
void solve() {
  cin >> n >> m;
  S.resize(m);
  for (int i = 0; i < (2); ++i) f();
  cout << OP[0].size() + OP[1].size() << "\n";
  for (auto x : OP[0]) cout << x.from << " " << x.to << "\n";
  for (int i = 0; i < (OP[1].size()); ++i) {
    auto &op = OP[1][OP[1].size() - 1 - i];
    cout << op.to << " " << op.from << "\n";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
