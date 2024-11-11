#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
const long long LINF = 2e18;
void inv(bool e);
template <typename T>
T sign(T a);
template <typename T>
void die(T& a);
template <typename T>
void umax(T& a, T b);
template <typename T>
void umin(T& a, T b);
bool brute, alter;
int cnt_tests = 1;
template <typename T>
struct Segment_tree {
  vector<T> data, orig;
  T net;
  T (*f)(T a, T b);
  void add(int pos, T val, int l, int r, int v) {
    if (pos > r || pos < l) return;
    if (l == r && l == pos) {
      orig[l] += val;
      data[v] += val;
      return;
    }
    int ls = v + v + 1, rs = v + v + 2, m = (l + r) / 2;
    add(pos, val, l, m, ls);
    add(pos, val, m + 1, r, rs);
    data[v] = (*f)(data[ls], data[rs]);
  }
  void add(int pos, T val) { add(pos, val, 0, ((int)(orig).size()) - 1, 0); }
  T get(int ql, int qr, int l, int r, int v) {
    if (ql > r || qr < l) return net;
    if (ql == l && r == qr) return data[v];
    int ls = v + v + 1, rs = v + v + 2, m = (l + r) / 2;
    T resL, resR;
    resL = get(ql, min(qr, m), l, m, ls);
    resR = get(max(ql, m + 1), qr, m + 1, r, rs);
    return (*f)(resL, resR);
  }
  T get(int ql, int qr) { return get(ql, qr, 0, ((int)(orig).size()) - 1, 0); }
  void build(int l, int r, int v) {
    if (l > r) return;
    if (l == r) {
      data[v] = orig[l];
      return;
    }
    int ls = v + v + 1, rs = v + v + 2, m = (l + r) / 2;
    build(l, m, ls);
    build(m + 1, r, rs);
    data[v] = (*f)(data[ls], data[rs]);
  }
  Segment_tree() {}
  Segment_tree(vector<T>& prot, T (*pf)(T a, T b), T nt) {
    f = pf;
    net = nt;
    orig = prot;
    data.resize(4 * ((int)(orig).size()) + 1, net);
    build(0, ((int)(orig).size()) - 1, 0);
  }
};
int n;
vector<int> arr[2];
void inp() {
  cin >> n;
  int x;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      cin >> x;
      arr[i].push_back(x);
    }
  }
}
const int N = 2e5 + 25;
long long summ[N];
void normalize() {
  for (int i = n - 2; i >= 1; i--) {
    int mx = n - i - 1;
    if (summ[i] > mx) {
      summ[i - 1]++;
      summ[i] -= mx + 1;
    }
  }
  summ[0] %= n;
}
void solve() {
  vector<long long> base(n, 0);
  for (int i = 0; i < 2; i++) {
    Segment_tree<long long> tree(
        base, [](long long a, long long b) { return a + b; }, 0);
    for (int j = 0; j < n; j++) {
      summ[j] += arr[i][j] - tree.get(0, arr[i][j]);
      tree.add(arr[i][j], 1);
    }
  }
  normalize();
  Segment_tree<long long> tree(
      base, [](long long a, long long b) { return a + b; }, 0);
  for (int i = 0; i < n; i++) {
    int l = 0, r = n - 1, m;
    while (r - l > 0) {
      m = (l + r) / 2;
      if (m - tree.get(0, m) >= summ[i]) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    cout << l << ' ';
    tree.add(l, 1);
  }
}
void stress() {}
void naive() {}
void run();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (0) {
    freopen("stack.in", "r", stdin);
    freopen("stack.out", "w", stdout);
  }
  brute = false;
  for (int i = 0; (i < cnt_tests); i++) {
    run();
  }
  cerr << '\n' << "Time: " << clock() / 1000.0 << " ms";
  return 0;
}
void run() {
  if (!brute) {
    inp();
  } else {
    stress();
  }
  solve();
}
template <typename T>
void die(T& a) {
  cout << a;
  exit(0);
}
template <typename T>
T sign(T a) {
  if (a == 0) return 0;
  if (a < 0) return -1;
  return 1;
}
template <typename T>
void umax(T& a, T b) {
  if (b > a) a = b;
}
template <typename T>
void umin(T& a, T b) {
  if (b < a) a = b;
}
void inv(bool e) {
  if (!e) {
    vector<int> a;
    a[-1] += 1;
  }
}
