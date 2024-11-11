#include <bits/stdc++.h>
using namespace std;
struct state {
  int g1, g2, s1, s2;
  state(int g1 = 0, int g2 = 0, int s1 = 0, int s2 = 0) {
    this->g1 = g1;
    this->g2 = g2;
    this->s1 = s1;
    this->s2 = s2;
  }
  state win1(int ns1, int ns2) { return state(g1 + 1, g2, s1 + ns1, s2 + ns2); }
  state win2(int ns1, int ns2) { return state(g1, g2 + 1, s1 + ns1, s2 + ns2); }
  bool illegal() {
    if (g1 > 3) return 1;
    if (g2 > 3) return 1;
    if (s1 > 200) return 1;
    if (s2 > 200) return 1;
    return 0;
  }
  bool finish() { return g1 == 3 || g2 == 3; }
};
int h[5][5][205][205];
pair<state, pair<int, int>> tr[5][5][205][205];
vector<pair<state, pair<int, int>>> transfer(state& a) {
  vector<pair<state, pair<int, int>>> res;
  if (a.finish()) return res;
  int wins = (a.g1 == 2 && a.g2 == 2) ? 15 : 25;
  for (int ns2 = 0; ns2 <= wins - 2; ns2++) {
    res.push_back(make_pair(a.win1(wins, ns2), pair<int, int>(wins, ns2)));
  }
  for (int ns1 = 0; ns1 <= wins - 2; ns1++) {
    res.push_back(make_pair(a.win2(ns1, wins), pair<int, int>(ns1, wins)));
  }
  for (int ex = wins + 1; ex <= 200; ex++) {
    res.push_back(make_pair(a.win1(ex, ex - 2), pair<int, int>(ex, ex - 2)));
    res.push_back(make_pair(a.win2(ex - 2, ex), pair<int, int>(ex - 2, ex)));
  }
  return res;
}
bool visit(queue<state>& q, pair<state, pair<int, int>> move, state& last) {
  state cur = move.first;
  if (!h[cur.g1][cur.g2][cur.s1][cur.s2]) {
    h[cur.g1][cur.g2][cur.s1][cur.s2] = 1;
    tr[cur.g1][cur.g2][cur.s1][cur.s2] = make_pair(last, move.second);
    q.push(cur);
    return 1;
  }
  return 0;
}
void prepare() {
  queue<state> q;
  q.push(state(0, 0, 0, 0));
  h[0][0][0][0] = 1;
  while (!q.empty()) {
    state cur = q.front();
    q.pop();
    for (auto move : transfer(cur))
      if (!move.first.illegal()) {
        visit(q, move, cur);
      }
  }
}
void trace(int f1, int f2, int s1, int s2) {
  vector<pair<int, int>> res;
  cout << f1 << ":" << f2 << '\n';
  state cur = state(f1, f2, s1, s2);
  while (cur.g1 || cur.g2) {
    res.push_back(tr[cur.g1][cur.g2][cur.s1][cur.s2].second);
    cur = tr[cur.g1][cur.g2][cur.s1][cur.s2].first;
  }
  reverse(res.begin(), res.end());
  for (auto i : res) cout << i.first << ":" << i.second << " ";
  cout << '\n';
}
void solve(int s1, int s2) {
  for (int diff = 3; diff > 0; diff--) {
    if (h[3][3 - diff][s1][s2]) {
      trace(3, 3 - diff, s1, s2);
      return;
    }
  }
  for (int diff = 1; diff < 3; diff++) {
    if (h[3 - diff][3][s1][s2]) {
      trace(3 - diff, 3, s1, s2);
      return;
    }
  }
  cout << "Impossible\n";
}
int main() {
  prepare();
  int test;
  cin >> test;
  while (test--) {
    int s1, s2;
    cin >> s1 >> s2;
    solve(s1, s2);
  }
}
