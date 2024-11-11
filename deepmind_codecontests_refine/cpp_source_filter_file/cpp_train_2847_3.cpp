#include <bits/stdc++.h>
using namespace std;
const int MAXN = 250000 + 10;
const long long INF = 1e18;
class Node {
 public:
  long long value, idx;
  Node() {}
  Node(long long _value, long long _idx) {
    value = _value;
    idx = _idx;
  }
};
class SegmentTree {
 public:
  static const int N = 250000 + 10;
  Node init[N], st[N << 2];
  inline void Pull(int now) {
    st[now] = st[(now << 1)];
    if (st[(now << 1)].value > st[((now << 1) + 1)].value)
      st[now] = st[((now << 1) + 1)];
  }
  void Build(int now = 1, int l = 0, int r = N - 1) {
    if (l == r) {
      st[now] = init[l];
      return;
    }
    Build((now << 1), l, ((l + r) >> 1));
    Build(((now << 1) + 1), ((l + r) >> 1) + 1, r);
    Pull(now);
  }
  void Update(long long value, long long pos, int now = 1, int l = 0,
              int r = N - 1) {
    assert(l <= pos and pos <= r);
    if (l == pos and pos == r) {
      st[now].value = value;
      return;
    }
    if (pos <= ((l + r) >> 1))
      Update(value, pos, (now << 1), l, ((l + r) >> 1));
    else
      Update(value, pos, ((now << 1) + 1), ((l + r) >> 1) + 1, r);
    Pull(now);
  }
  Node Query(int ql, int qr, int now = 1, int l = 0, int r = N - 1) {
    if (ql > qr or qr < l or ql > r) return Node(INF, -1);
    if (l == ql and r == qr) return st[now];
    if (qr <= ((l + r) >> 1))
      return Query(ql, qr, (now << 1), l, ((l + r) >> 1));
    else if (((l + r) >> 1) < ql)
      return Query(ql, qr, ((now << 1) + 1), ((l + r) >> 1) + 1, r);
    else {
      Node lchild = Query(ql, ((l + r) >> 1), (now << 1), l, ((l + r) >> 1));
      Node rchild = Query(((l + r) >> 1) + 1, qr, ((now << 1) + 1),
                          ((l + r) >> 1) + 1, r);
      if (lchild.value < rchild.value) return lchild;
      return rchild;
    }
  }
};
long long X, Y, P, R, N, ans;
long long x[MAXN], y[MAXN], m[MAXN], p[MAXN], r[MAXN], d[MAXN];
long long mp[MAXN];
SegmentTree st;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios::fixed);
  cout.precision(20);
  cin >> X >> Y >> P >> R >> N;
  R *= R;
  for (int i = 0; i < N; ++i) {
    cin >> x[i] >> y[i] >> m[i] >> p[i] >> r[i];
    x[i] -= X;
    y[i] -= Y;
    d[i] = x[i] * x[i] + y[i] * y[i];
    r[i] *= r[i];
  }
  vector<pair<long long, long long> > dist;
  for (int i = 0; i < N; ++i) dist.push_back({d[i], i});
  sort(dist.begin(), dist.end());
  for (int i = 0; i < (int)dist.size(); ++i) {
    st.init[i] = Node(m[dist[i].second], i);
    mp[i] = dist[i].second;
  }
  st.Build();
  queue<pair<long long, long long> > q;
  q.push({P, R});
  while (!q.empty()) {
    long long now_p = q.front().first;
    long long now_r = q.front().second;
    q.pop();
    int pos = upper_bound(dist.begin(), dist.end(), make_pair(now_r, INF)) -
              dist.begin() - 1;
    if (pos == -1) break;
    while (1) {
      Node now = st.Query(0, pos);
      if (now.value > now_p) break;
      ++ans;
      st.Update(INF, now.idx);
      int real_pos = mp[now.idx];
      q.push({p[real_pos], r[real_pos]});
    }
  }
  cout << ans << '\n';
}
