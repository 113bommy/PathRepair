#include <bits/stdc++.h>
using namespace std;
void Debug() { cout << '\n'; }
template <class FIRST, class... REST>
void Debug(FIRST arg, REST... rest) {
  cout << arg << " ";
  Debug(rest...);
}
template <class T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  out << "[";
  if (!v.empty()) {
    for (int i = int(0); i < int((int)(v).size() - 1); i++) out << v[i] << ", ";
    out << v.back();
  }
  out << "]";
  return out;
}
template <class S, class T>
ostream& operator<<(ostream& out, const pair<S, T>& v) {
  out << "(" << v.first << ", " << v.second << ")";
  return out;
}
const int MAX_N = 300010;
const int MAX_V = 100010;
const double eps = 1e-6;
const long long mod = 1000000007;
const int inf = 1 << 30;
const long long linf = 1LL << 60;
const double PI = 3.14159265358979323846;
struct BIT {
  int n;
  vector<long long> bit0, bit1;
  void init(int mx) {
    n = mx;
    bit0 = vector<long long>(n + 1, 0);
    bit1 = vector<long long>(n + 1, 0);
  }
  BIT(int mx = 0) { init(mx); }
  long long ga(vector<long long>& bit, int i) {
    long long s = 0;
    while (i > 0) {
      s += bit[i];
      i -= i & -i;
    }
    return s;
  }
  void app(vector<long long>& bit, int i, long long x) {
    while (i <= n) {
      bit[i] += x;
      i += i & -i;
    }
  }
  void update(int a, int b, long long x) {
    a++;
    app(bit0, a, -x * (a - 1));
    app(bit1, a, x);
    app(bit0, b + 1, x * b);
    app(bit1, b + 1, -x);
  }
  long long get(int a, int b) {
    a++;
    return (ga(bit1, b) * b + ga(bit0, b)) -
           (ga(bit1, a - 1) * (a - 1) + ga(bit0, a - 1));
  }
};
int N, M;
long long P[MAX_N], S[MAX_N], B[MAX_N];
long long DX[MAX_N], DY[MAX_N];
long long DD[MAX_N];
long long PX[MAX_N], PY[MAX_N];
vector<long long> vx, vy, vd;
int sumd[MAX_N];
int ans[MAX_N];
vector<pair<long long, long long> > Q[MAX_N];
BIT bit;
int fd(const vector<long long>& vec, long long a) {
  return lower_bound((vec).begin(), (vec).end(), a) - vec.begin();
}
void solve() {
  cin >> N >> M;
  for (int i = int(0); i < int(N); i++) cin >> P[i];
  for (int i = int(0); i < int(N); i++) cin >> S[i];
  for (int i = int(0); i < int(N); i++) cin >> B[i];
  for (int i = int(0); i < int(M); i++) cin >> PX[i];
  for (int i = int(0); i < int(M); i++) cin >> PY[i];
  for (int i = int(0); i < int(N); i++) {
    long long p = P[i], s = S[i], b = B[i];
    DD[i] = 2 * s + 1;
    DX[i] = p - b;
    DY[i] = b + p;
    vd.push_back(DD[i]);
    vx.push_back(DX[i]);
    vy.push_back(DY[i]);
  }
  for (int i = int(0); i < int(M); i++) {
    long long x = PX[i], y = PY[i];
    PX[i] = x - y;
    PY[i] = y + x;
    vx.push_back(PX[i]);
    vy.push_back(PY[i]);
    vd.push_back(PX[i] + PY[i]);
  }
  sort((vx).begin(), (vx).end());
  vx.erase(unique((vx).begin(), (vx).end()), vx.end());
  sort((vy).begin(), (vy).end());
  vy.erase(unique((vy).begin(), (vy).end()), vy.end());
  sort((vd).begin(), (vd).end());
  vd.erase(unique((vd).begin(), (vd).end()), vd.end());
  for (int i = int(0); i < int(N); i++) {
    int at = fd(vd, DD[i]);
    sumd[at]++;
  }
  for (int i = int(0); i < int((int)(vd).size()); i++) sumd[i + 1] += sumd[i];
  for (int i = int(0); i < int(N); i++) {
    int xat = fd(vx, DX[i]), yat = fd(vy, DY[i]);
    Q[xat].push_back(pair<int, int>(yat, -1));
  }
  for (int i = int(0); i < int(M); i++) {
    int xat = fd(vx, PX[i]), yat = fd(vy, PY[i]);
    Q[xat].push_back(pair<int, int>(yat, i));
  }
  bit.init((int)(vy).size());
  for (int i = int(0); i < int((int)(vx).size()); i++) {
    for (int j = int(0); j < int((int)(Q[i]).size()); j++) {
      pair<int, int> p = Q[i][j];
      if (p.second == -1)
        bit.update(p.first, (int)(vy).size(), 1);
      else {
        ans[p.second] += bit.get(p.first, p.first + 1);
      }
    }
  }
  for (int q = int(0); q < int(2); q++) {
    for (int i = int(0); i < int((int)(vx).size()); i++) Q[i].clear();
    vx.clear();
    for (int i = int(0); i < int(N); i++) {
      vx.push_back(DX[i] - 1);
    }
    for (int i = int(0); i < int(M); i++) {
      vx.push_back(PX[i]);
    }
    sort((vx).begin(), (vx).end());
    vx.erase(unique((vx).begin(), (vx).end()), vx.end());
    for (int i = int(0); i < int(N); i++) {
      int xat = fd(vx, DX[i] - 1), dat = fd(vd, DD[i]);
      Q[xat].push_back(pair<int, int>(dat, -1));
    }
    for (int i = int(0); i < int(M); i++) {
      int xat = fd(vx, PX[i]), dat = fd(vd, PX[i] + PY[i]);
      Q[xat].push_back(pair<int, int>(dat, i));
    }
    bit.init((int)(vd).size());
    for (int i = int((int)(vx).size()) - 1; i >= int(0); i--) {
      for (int j = int(0); j < int((int)(Q[i]).size()); j++) {
        pair<int, int> p = Q[i][j];
        if (p.second == -1)
          bit.update(p.first, (int)(vd).size(), 1);
        else {
          ans[p.second] += bit.get(p.first, p.first + 1);
        }
      }
    }
    for (int i = int(0); i < int(N); i++) swap(DX[i], DY[i]);
    for (int i = int(0); i < int(M); i++) swap(PX[i], PY[i]);
  }
  for (int i = int(0); i < int(M); i++) {
    int at = fd(vd, PX[i] + PY[i]);
    cout << ans[i] - sumd[at] << (i == M - 1 ? '\n' : ' ');
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed;
  cout.precision(20);
  srand((unsigned int)time(NULL));
  solve();
  return 0;
}
