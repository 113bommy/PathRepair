#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;
const long long Inf = 1e10;
const int P = 1e9 + 7;
const int N = 100005;
const int M = 1000005;
inline long long IN() {
  long long x = 0;
  int ch = 0, f = 0;
  for (ch = getchar(); ch != -1 && (ch < 48 || ch > 57); ch = getchar())
    f = (ch == '-');
  for (; ch >= 48 && ch <= 57; ch = getchar())
    x = (x << 1) + (x << 3) + ch - '0';
  return f ? (-x) : x;
}
template <typename T>
inline int chkmin(T &a, const T &b) {
  if (b < a) return a = b, 1;
  return 0;
}
template <typename T>
inline int chkmax(T &a, const T &b) {
  if (b > a) return a = b, 1;
  return 0;
}
void renew(int &x, const int &y) {
  x += y;
  if (x >= P) x -= P;
  if (x < 0) x += P;
}
int Pow(int x, int y, int p) {
  int a = 1;
  for (; y; y >>= 1, x = (long long)x * x % p)
    if (y & 1) a = (long long)a * x % p;
  return a;
}
vector<pair<int, int> > in[M], ou[M];
int n, m, K;
int cov[M << 2], sum[M << 2], len[M << 2];
int ql, qr, qv, qans;
void Cov(int x, int y) {
  cov[x] = y;
  sum[x] = 1LL * len[x] * y % P;
}
void sep(int x) {
  if (cov[x] == -1) return;
  Cov(x << 1, cov[x]);
  Cov(x + x + 1, cov[x]);
  cov[x] = -1;
}
void A(int x, int L, int R) {
  if (ql <= L && R <= qr) {
    Cov(x, qv);
    return;
  }
  sep(x);
  int md = (L + R) >> 1;
  if (ql <= md) A(x << 1, L, md);
  if (md < qr) A(x + x + 1, md + 1, R);
  sum[x] = sum[x + x + 1];
  renew(sum[x], sum[x << 1]);
}
void Add(int l, int r, int v) {
  if (l > r) return;
  ql = l;
  qr = r;
  qv = v;
  A(1, 1, m);
}
void Q(int x, int L, int R) {
  if (ql <= L && R <= qr) {
    renew(qans, sum[x]);
    return;
  }
  sep(x);
  int md = (L + R) >> 1;
  if (ql <= md) Q(x << 1, L, md);
  if (md < qr) Q(x + x + 1, md + 1, R);
}
int Ask(int l, int r) {
  if (l > r) return 0;
  ql = l;
  qr = r;
  qans = 0;
  Q(1, 1, m);
  return qans;
}
void B(int x, int L, int R) {
  len[x] = R - L + 1;
  if (L == R) return;
  int md = (L + R) / 2;
  B(x << 1, L, md);
  B(x + x + 1, md + 1, R);
}
set<pair<int, int> > st;
int main() {
  scanf("%d%d%d", &n, &m, &K);
  for (int i = (int)(1); i <= (int)(K); i++) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    in[x1].push_back(make_pair(y1, y2));
    ou[x2 + 1].push_back(make_pair(y1, y2));
  }
  B(1, 1, m);
  Add(1, 1, 1);
  for (auto v : in[1]) {
    st.insert(v);
    Add(v.first, v.second, 0);
  }
  for (int i = (int)(2); i <= (int)(n); i++) {
    static int tot, vx[N], vc[N];
    tot = 0;
    for (auto v : in[i]) {
      if (v.second + 1 > m) continue;
      auto w = st.lower_bound(make_pair(v.second + 1, 0));
      int Low = 0;
      if (w != st.begin()) {
        --w;
        Low = w->second;
      }
      ++tot;
      vc[tot] = Ask(Low + 1, v.second + 1);
      vx[tot] = v.second + 1;
    }
    for (int j = (int)(1); j <= (int)(tot); j++) Add(vx[j], vx[j], vc[j]);
    for (auto v : ou[i]) st.erase(v);
    for (auto v : in[i]) {
      st.insert(v);
      Add(v.first, v.second, 0);
    }
  }
  int Low = (st.empty()) ? (0) : ((--st.end())->second);
  cout << Ask(Low + 1, m) << endl;
  return 0;
}
