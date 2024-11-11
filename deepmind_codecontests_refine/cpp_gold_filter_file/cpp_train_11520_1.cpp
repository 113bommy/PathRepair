#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const long long longinf = 1LL << 60;
const long long mod = 1e9 + 7;
const long long mod2 = 998244353;
const long double eps = 1e-10;
template <typename T1, typename T2>
inline void chmin(T1 &a, T2 b) {
  if (a > b) a = b;
}
template <typename T1, typename T2>
inline void chmax(T1 &a, T2 b) {
  if (a < b) a = b;
}
template <class Monoid>
struct SegTree {
  using Func = function<Monoid(Monoid, Monoid)>;
  const Func F;
  const Monoid UNITY;
  int SIZE_R;
  vector<Monoid> dat;
  SegTree(int n, const Func f, const Monoid &unity) : F(f), UNITY(unity) {
    init(n);
  }
  void init(int n) {
    SIZE_R = 1;
    while (SIZE_R < n) SIZE_R *= 2;
    dat.assign(SIZE_R * 2, UNITY);
  }
  void set(int a, const Monoid &v) { dat[a + SIZE_R] = v; }
  void build() {
    for (int k = SIZE_R - 1; k > 0; --k) dat[k] = F(dat[k * 2], dat[k * 2 + 1]);
  }
  void update(int a, const Monoid &v) {
    int k = a + SIZE_R;
    dat[k] = v;
    while (k >>= 1) dat[k] = F(dat[k * 2], dat[k * 2 + 1]);
  }
  Monoid get(int a, int b) {
    Monoid vleft = UNITY, vright = UNITY;
    for (int left = a + SIZE_R, right = b + SIZE_R; left < right;
         left >>= 1, right >>= 1) {
      if (left & 1) vleft = F(vleft, dat[left++]);
      if (right & 1) vright = F(dat[--right], vright);
    }
    return F(vleft, vright);
  }
  inline Monoid operator[](int a) { return dat[a + SIZE_R]; }
  void print() {
    for (int i = 0; i < SIZE_R; ++i) {
      cout << (*this)[i];
      if (i != SIZE_R - 1) cout << ",";
    }
    cout << endl;
  }
};
vector<int> LIS(const vector<long long> &a) {
  int N = (int)a.size();
  vector<long long> aval;
  for (int i = 0; i < N; ++i) aval.push_back(a[i]);
  sort(aval.begin(), aval.end());
  aval.erase(unique(aval.begin(), aval.end()), aval.end());
  SegTree<int> dp(
      N + 1, [](int a, int b) { return max(a, b); }, 0);
  vector<int> res(N);
  for (int i = 0; i < N; ++i) {
    int h = lower_bound(aval.begin(), aval.end(), a[i]) - aval.begin();
    ++h;
    int A = dp.get(0, h + 1);
    if (dp.get(h, h + 1) < A + 1) {
      dp.update(h, A + 1);
      res[i] = A + 1;
    }
  }
  return res;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<long long> cnt(m + 1);
  for (int i = (int)(0); i < (int)(n); i++) {
    int l, r;
    cin >> l >> r;
    l--;
    cnt[l]++;
    cnt[r]--;
  }
  for (int i = (int)(0); i < (int)(m); i++) cnt[i + 1] += cnt[i];
  assert(cnt.back() == 0);
  cnt.pop_back();
  auto res1 = LIS(cnt);
  reverse(cnt.begin(), cnt.end());
  auto res2 = LIS(cnt);
  reverse(res2.begin(), res2.end());
  reverse(cnt.begin(), cnt.end());
  int ans = 0;
  for (int i = (int)(0); i < (int)(m); i++) chmax(ans, res1[i] + res2[i] - 1);
  cout << ans << '\n';
  return 0;
}
