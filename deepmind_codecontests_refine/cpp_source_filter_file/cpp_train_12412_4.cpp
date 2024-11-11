#include <bits/stdc++.h>
using namespace std;
int X, Y, Z;
struct State {
  int defenders;
  char last_attack;
  vector<State> next_states() {
    if (defenders == 0) return {};
    vector<State> res;
    res.push_back({max(defenders - X, 0), 0});
    if (last_attack != 1) res.push_back({max(defenders - Y, 0), 1});
    if (last_attack != 2) res.push_back({max(defenders - Z, 0), 2});
    return res;
  }
  bool operator<(const State& s) const {
    if (defenders != s.defenders) return defenders < s.defenders;
    return last_attack < s.last_attack;
  }
};
const int MAXA = 1000;
int memo[3][MAXA];
int grundyNumber(State cur) {
  int& res = memo[int(cur.last_attack)][cur.defenders];
  if (res >= 0) return res;
  set<int> S;
  for (State nxt : cur.next_states()) {
    S.insert(grundyNumber(nxt));
  }
  res = 0;
  while (S.count(res) > 0) ++res;
  return res;
}
vector<vector<int> > G;
int find_period() {
  for (int p = 1;; ++p) {
    bool ok = true;
    for (int i = int((G[0]).size()) - 1; i >= 100 && i >= p; --i) {
      if (G[0][i] != G[0][i - p] || G[1][i] != G[1][i - p] ||
          G[2][i] != G[2][i - p]) {
        ok = false;
        break;
      }
    }
    if (ok) return p;
  }
  return -1;
}
int find_grundy_number(int period, long long a, int k) {
  if (a < 0) return 0;
  if (a < int((G[k]).size())) return G[k][a];
  int aa = (a - int((G[k]).size())) % period;
  return G[k][int((G[k]).size()) - period + aa];
}
int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int TC;
  cin >> TC;
  for (int tc = (1), _b = (TC); tc <= _b; ++tc) {
    int N;
    cin >> N >> X >> Y >> Z;
    vector<long long> A(N);
    for (int i = 0, _n = (N); i < _n; ++i) cin >> A[i];
    memset(memo, -1, sizeof(memo));
    G = vector<vector<int> >(3, vector<int>(MAXA + 1));
    for (int a = (0), _b = (MAXA); a <= _b; ++a) {
      for (int k = 0, _n = (3); k < _n; ++k)
        G[k][a] = grundyNumber({a, (char)k});
    }
    int period = find_period();
    int xsum = 0;
    for (long long a : A) xsum ^= find_grundy_number(period, a, 0);
    int res = 0;
    for (long long a : A) {
      int xxx = xsum ^ find_grundy_number(period, a, 0);
      int gX = find_grundy_number(period, a - X, 0);
      if ((xxx ^ gX) == 0) ++res;
      int gY = find_grundy_number(period, a - Y, 1);
      if ((xxx ^ gY) == 0) ++res;
      int gZ = find_grundy_number(period, a - Z, 2);
      if ((xxx ^ gZ) == 0) ++res;
    }
    cout << res << '\n';
  }
  return 0;
}
