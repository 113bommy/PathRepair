#include <bits/stdc++.h>
using namespace std;
void openFile() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
const int maxN = 1e5 + 5;
const int maxM = 3e5 + 5;
const long long INF = 1e9 + 7;
int N, M;
int a[maxN], id[maxN], pos[maxN];
vector<pair<int, int> > q[maxN];
int ans[maxM];
vector<int> V;
void enter() {
  cin >> N;
  for (int i = 1, _b = N; i <= _b; ++i) {
    cin >> a[i];
    V.push_back(a[i]);
    id[i] = i;
  }
  cin >> M;
  for (int i = 1, _b = M; i <= _b; ++i) {
    int l, r;
    cin >> l >> r;
    q[r].push_back({l, i});
    ans[i] = INF;
  }
}
struct node {
  int maxId, rmin;
  friend void combine(node &p, const node &a, const node &b) {
    p.maxId = max(a.maxId, b.maxId);
  }
};
class segmentTree {
 public:
  node it[maxN * 4];
  int L[maxN * 4], R[maxN * 4], leaf[maxN];
  int RET;
  void buildTree(int x, int low, int high) {
    L[x] = low;
    R[x] = high;
    it[x] = {0, INF};
    if (low == high) {
      leaf[low] = x;
      return;
    }
    int mid = (low + high) / 2;
    buildTree((x * 2), low, mid);
    buildTree((x * 2 + 1), mid + 1, high);
    combine(it[x], it[(x * 2)], it[(x * 2 + 1)]);
  }
  template <typename LF>
  void process(int x, int low, int high, LF f) {
    if (L[x] > high || R[x] < low) return;
    if (low <= L[x] && R[x] <= high) {
      f(it[x]);
      return;
    }
    process((x * 2), low, high, f);
    process((x * 2 + 1), low, high, f);
    combine(it[x], it[(x * 2)], it[(x * 2 + 1)]);
  }
  void updateMin(int low, int high, int val) {
    RET = val;
    process(1, low, high, [this](node &x) { x.rmin = min(x.rmin, RET); });
  }
  void setId(int u, int val) {
    int x = leaf[u];
    it[x].maxId = val;
    while (x > 1) {
      x >>= 1;
      combine(it[x], it[(x * 2)], it[(x * 2 + 1)]);
    }
  }
  int rightMost(int j, int r) {
    int kv = a[j] + a[r];
    kv = kv / 2 - (kv > 0 ? (kv % 2 == 0) : 1);
    int lo = lower_bound(V.begin(), V.end(), a[r]) - V.begin() + 1;
    int hi = upper_bound(V.begin(), V.end(), kv) - V.begin();
    RET = 0;
    process(1, lo, hi, [this](node &x) { RET = max(RET, x.maxId); });
    return RET;
  }
  int query(int x, int u) {
    if (L[x] == R[x]) return it[x].rmin;
    if (R[(x * 2)] >= u) {
      return min(it[x].rmin, query((x * 2), u));
    } else {
      return min(it[x].rmin, query((x * 2 + 1), u));
    }
  }
} T;
void solve() {
  sort(V.begin(), V.end());
  sort(id + 1, id + N + 1, [](int i, int j) { return a[i] < a[j]; });
  for (int i = 1, _b = N; i <= _b; ++i) {
    pos[id[i]] = i;
  }
  stack<int> st;
  T.buildTree(1, 1, N);
  for (int r = 1, _b = N; r <= _b; ++r) {
    while (!st.empty() && a[st.top()] < a[r]) st.pop();
    if (!st.empty()) {
      int j = st.top();
      T.updateMin(1, j, a[j] - a[r]);
      while (int jj = T.rightMost(j, r)) {
        T.updateMin(1, jj, a[jj] - a[r]);
        j = jj;
      }
    }
    st.push(r);
    T.setId(pos[r], r);
    for (auto pt : q[r]) {
      ans[pt.second] = min(ans[pt.second], T.query(1, pt.first));
    }
  }
}
void Reverse() {
  for (int i = 0, _a = N; i < _a; ++i) V[i] = -V[i];
  for (int i = 1, _b = N; i <= _b; ++i) {
    a[i] = -a[i];
  }
}
void printRes() {
  for (int i = 1, _b = M; i <= _b; ++i) {
    printf("%d\n", ans[i]);
  }
}
int main() {
  openFile();
  enter();
  solve();
  Reverse();
  solve();
  printRes();
  return 0;
}
