#include <bits/stdc++.h>
using namespace std;
struct P {
  int x, y;
};
P me;
P other;
bool white;
int N, M;
P operator+(P a, P b) { return {a.x + b.x, a.y + b.y}; }
P operator-(P a, P b) { return {a.x - b.x, a.y - b.y}; }
bool operator==(P a, P b) { return a.x == b.x && a.y == b.y; }
bool isItAStep(P a, P b) {
  a = a - b;
  int dx = abs(a.x);
  int dy = abs(a.y);
  return (dx == 1 && dy == 2) || (dx == 2 && dy == 1);
}
P winWhite, winBlack;
void step(P newP) {
  if (white && isItAStep(winWhite, me)) {
    cout << winWhite.x << " " << winWhite.y << endl << flush;
    exit(0);
  }
  if (!white && isItAStep(winBlack, me)) {
    cout << winBlack.x << " " << winBlack.y << endl << flush;
    exit(0);
  }
  if (isItAStep(other, me)) {
    cout << other.x << " " << other.y << endl << flush;
    exit(0);
  }
  me = newP;
  cout << me.x << " " << me.y << endl << flush;
  if (white && me.x == N / 2 && me.y == M / 2) exit(0);
  if (!white && me.x == N / 2 + 1 && me.y == M / 2) exit(0);
}
void getStep() {
  cin >> other.x >> other.y;
  if (other == me) exit(1);
  if (other.x == -1) exit(0);
}
const vector<P> ize = {
    {+1, +2}, {-1, +2}, {+1, -2}, {-1, -2},
    {+2, +1}, {-2, +1}, {+2, -1}, {-2, -1},
};
vector<P> dfs(P from, P to, int K) {
  if (from == to) return vector<P>(1, to);
  if (K == 0) return vector<P>();
  vector<P> best;
  for (const P& x : ize) {
    P to2 = to + x;
    if (to2.x < 1 || to2.y < 1) continue;
    if (to2.x > N || to2.y > M) continue;
    vector<P> c = dfs(from, to2, K - 1);
    if (best.size() == 0 || (!c.empty() && c.size() < best.size())) best = c;
  }
  if (best.empty()) return best;
  best.push_back(to);
  return best;
}
vector<P> closestDistance_(P from, P to) {
  int dx = abs(to.x - from.x);
  int dy = abs(to.y - from.y);
  int ix = (to.x > from.x ? 1 : -1);
  int iy = (to.y > from.y ? 1 : -1);
  vector<P> S;
  while (dx > 5 || dy > 5) {
    int wx = 2, wy = 1;
    if (dx < dy) {
      wx = 1;
      wy = 2;
    }
    ix = (to.x > from.x ? 1 : -1);
    iy = (to.y > from.y ? 1 : -1);
    from.x += wx * ix;
    from.y += wy * iy;
    S.push_back(from);
    dx = abs(to.x - from.x);
    dy = abs(to.y - from.y);
  }
  vector<P> ize = dfs(from, to, 6);
  assert(!ize.empty());
  auto it = ize.begin(), end = ize.end();
  it++;
  while (it != end) {
    S.push_back(*it);
    it++;
  }
  return S;
}
void check(vector<P>& S, P from, P to) {
  if (S.empty()) return;
  P last = from;
  assert(to == S.back());
  for (const P& p : S) {
    assert(isItAStep(last, p));
    last = p;
  }
}
int main() {
  int xw, yw, xb, yb;
  cin >> N >> M;
  cin >> xw >> yw >> xb >> yb;
  winWhite = {N / 2, M / 2};
  winBlack = {N / 2 + 1, M / 2};
  P whitee = {xw, yw};
  P blackk = {xb, yb};
  vector<P> cdww = closestDistance_(whitee, winWhite);
  vector<P> cdbw = closestDistance_(blackk, winWhite);
  vector<P> cdwb = closestDistance_(whitee, winBlack);
  vector<P> cdbb = closestDistance_(blackk, winBlack);
  vector<P> cd;
  white = true;
  bool white_kerget = ((xw ^ xb ^ yw ^ yb) & 1) == 1;
  cerr << "W->w: " << cdww.size() << endl;
  cerr << "W->b: " << cdwb.size() << endl;
  cerr << "B->w: " << cdbw.size() << endl;
  cerr << "B->b: " << cdbb.size() << endl;
  cerr << (white_kerget ? "White kerget" : "Black kerget") << endl;
  if (white_kerget) {
    cerr << "white kerget" << endl;
    if (cdwb.size() <= cdbb.size() + 1) {
      cerr << "white bevarja" << endl;
      white = true;
      cd = move(cdwb);
    } else if (cdww.size() <= cdbb.size()) {
      cerr << "black megelozi" << endl;
      white = false;
      cd = move(cdww);
    } else {
      white = false;
      cd = move(cdbb);
    }
  } else {
    cerr << "black kerget" << endl;
    if (cdbw.size() <= cdww.size()) {
      cerr << "black bevarja" << endl;
      white = false;
      cd = move(cdbw);
    } else if (cdbb.size() < cdww.size()) {
      cerr << "black megelozi" << endl;
      white = false;
      cd = move(cdbb);
    } else {
      white = true;
      cd = move(cdww);
    }
  }
  cdww.clear();
  cdwb.clear();
  cdbw.clear();
  cdbb.clear();
  if (white) {
    me = whitee;
    other = blackk;
    cout << "WHITE" << endl;
  } else {
    me = blackk;
    other = whitee;
    cout << "BLACK" << endl;
    getStep();
  }
  if (!white) {
    cd.push_back(winWhite + P{2, 1});
    cd.push_back(winWhite + P{0, 2});
    cd.push_back(winWhite + P{1, 0});
  } else if (white) {
    cd.push_back(winBlack - P{2, 1});
    cd.push_back(winBlack - P{0, 2});
    cd.push_back(winBlack - P{1, 0});
  }
  int i = 0;
  while (i < cd.size()) {
    step(cd[i]);
    getStep();
    i++;
  }
  return 0;
}
