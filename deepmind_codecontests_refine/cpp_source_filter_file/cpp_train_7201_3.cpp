#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef vector<pair<int, pair<int, int>>> vpip;
const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const long long INF = 1e18;
struct EDGE {
  int id;
  double len, spd;
  bool operator<(EDGE other) const { return spd < other.spd; }
};
int N, L;
EDGE walkways[200007 * 2];
int Nseg[2];
struct SEGNODE {
  double es;
  double lzVal;
  bool LazyPushedDown;
};
SEGNODE seg[200007 * 2 * 4];
void pullUp(int v, int l, int m, int r) {
  if (l == r) return;
  seg[v].es = min(seg[2 * v].es, seg[2 * v + 1].es);
}
void pushDown(int v, int l, int m, int r) {
  if (l == r) {
    seg[v].LazyPushedDown = true;
    return;
  }
  if (seg[v].LazyPushedDown) return;
  seg[2 * v].es += seg[v].lzVal;
  seg[2 * v].lzVal += seg[v].lzVal;
  seg[2 * v].LazyPushedDown = false;
  seg[2 * v + 1].es += seg[v].lzVal;
  seg[2 * v + 1].lzVal += seg[v].lzVal;
  ;
  seg[2 * v + 1].LazyPushedDown = false;
  seg[v].LazyPushedDown = true;
  seg[v].lzVal = 0;
}
void buildSeg(int v = 1, int l = Nseg[0], int r = Nseg[1]) {
  if (l == r) {
    seg[v].es = 0;
    seg[v].lzVal = 0;
    seg[v].LazyPushedDown = true;
    return;
  }
  int mid = (l + r) / 2;
  buildSeg(2 * v, l, mid);
  buildSeg(2 * v + 1, mid + 1, r);
  pullUp(v, l, mid, r);
}
void initSeg() {
  Nseg[0] = 0;
  Nseg[1] = N;
  buildSeg();
}
double querySeg(int qle, int qri, int v = 1, int l = Nseg[0], int r = Nseg[1]) {
  if (r < qle || l > qri) return INF;
  if (qle <= l && r <= qri) {
    return seg[v].es;
  }
  int mid = (l + r) / 2;
  pushDown(v, l, mid, r);
  double ret = min(querySeg(qle, qri, 2 * v, l, mid),
                   querySeg(qle, qri, 2 * v + 1, mid + 1, r));
  pullUp(v, l, mid, r);
  return ret;
}
void updateSeg(int ule, int uri, double val, int v = 1, int l = Nseg[0],
               int r = Nseg[1]) {
  if (r < ule || l > uri) return;
  int mid = (l + r) / 2;
  if (ule <= l && r <= uri) {
    pushDown(v, l, mid, r);
    seg[v].es += val;
    seg[v].lzVal += val;
    seg[v].LazyPushedDown = false;
    return;
  }
  pushDown(v, l, mid, r);
  updateSeg(ule, uri, val, 2 * v, l, mid);
  updateSeg(ule, uri, val, 2 * v + 1, mid + 1, r);
  pullUp(v, l, mid, r);
}
bool debug;
int main() {
  debug = false;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> L;
  int pre_x = 0;
  int ct = 0;
  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    double s;
    cin >> s;
    if (x - pre_x > 0) {
      walkways[ct].id = ct;
      walkways[ct].len = x - pre_x;
      walkways[ct].spd = 0;
      ct++;
    }
    if (y - x > 0) {
      walkways[ct].id = ct;
      walkways[ct].len = y - x;
      walkways[ct].spd = s;
      ct++;
    }
    pre_x = y;
  }
  if (L - pre_x > 0) {
    walkways[ct].id = ct;
    walkways[ct].len = L - pre_x;
    walkways[ct].spd = 0.0;
  } else {
    ct--;
  }
  if (debug) cout << "# of segment = " << ct << endl;
  N = ct;
  initSeg();
  for (int i = 0; i <= N; i++) {
    if (walkways[i].spd == 0) continue;
    updateSeg(i, N, walkways[i].len / walkways[i].spd);
  }
  double ans = 0;
  sort(walkways, walkways + N);
  for (int i = 0; i <= N; i++) {
    double opt1 = walkways[i].len / (walkways[i].spd + 2);
    if (walkways[i].spd > 0) opt1 += walkways[i].len / walkways[i].spd;
    double opt2 = querySeg(walkways[i].id, N);
    double best_opt = min(opt1, opt2);
    double energy_saved = 0;
    if (walkways[i].spd > 0) energy_saved = walkways[i].len / walkways[i].spd;
    energy_saved -= best_opt;
    ans += (walkways[i].len + energy_saved) / (walkways[i].spd + 1);
    if (debug)
      cout << ans << ": " << walkways[i].len << " " << walkways[i].spd << " @ "
           << walkways[i].id << endl;
    updateSeg(walkways[i].id, N, -best_opt);
  }
  cout << setprecision(14) << ans << endl;
  if (debug) cout << endl << "EOL" << endl;
}
