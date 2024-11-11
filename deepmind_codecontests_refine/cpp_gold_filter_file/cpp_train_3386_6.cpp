#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream& operator<<(ostream& cout, pair<A, B> const& p) {
  return cout << "(" << p.first << ", " << p.second << ")";
}
template <typename A>
ostream& operator<<(ostream& cout, vector<A> const& v) {
  cout << "[";
  for (int i = 0; i < v.size(); i++) {
    if (i) cout << ", ";
    cout << v[i];
  }
  return cout << "]";
}
void fast_io() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
}
void file_io(string taskname) {
  string fin = taskname + ".in";
  string fout = taskname + ".out";
  const char* FIN = fin.c_str();
  const char* FOUT = fout.c_str();
  freopen(FIN, "r", stdin);
  freopen(FOUT, "w", stdout);
  fast_io();
}
const int C = 200005;
struct Line {
  long long m, b;
  long long operator()(long long x) { return m * x + b; }
} lichao[C * 4];
void insert(Line seg, int l = 0, int r = C, int o = 0) {
  if (l + 1 == r) {
    if (seg(l) > lichao[o](l)) lichao[o] = seg;
    return;
  }
  int mid = (l + r) >> 1, lson = o * 2 + 1, rson = o * 2 + 2;
  if (lichao[o].m > seg.m) swap(lichao[o], seg);
  if (lichao[o](mid) < seg(mid)) {
    swap(lichao[o], seg);
    insert(seg, l, mid, lson);
  } else
    insert(seg, mid, r, rson);
}
long long query(int x, int l = 0, int r = C, int o = 0) {
  if (l + 1 == r) return lichao[o](x);
  int mid = (l + r) >> 1, lson = o * 2 + 1, rson = o * 2 + 2;
  if (x < mid)
    return max(lichao[o](x), query(x, l, mid, lson));
  else
    return max(lichao[o](x), query(x, mid, r, rson));
}
int main() {
  fast_io();
  int n;
  cin >> n;
  vector<long long> v(n), pref(n);
  long long tot = 0;
  for (int i = 0; i < (n); i++) {
    cin >> v[i];
    pref[i] = v[i] + (i > 0 ? pref[i - 1] : 0);
    tot += (i + 1) * v[i];
  }
  long long best = 0;
  for (int i = 0; i < (sizeof(lichao) / sizeof(lichao[0])); i++) {
    lichao[i] = {-900000000000LL, -900000000000LL};
  }
  for (int r = 0; r < (n); r++) {
    if (r > 0) best = max(best, query(r) - pref[r]);
    insert({v[r], pref[r] - r * v[r]});
  }
  vector<long long> suff(n);
  for (int i = n - 1; i >= 0; i--) {
    suff[i] = v[i] + (i < n - 1 ? suff[i + 1] : 0);
  }
  for (int i = 0; i < (sizeof(lichao) / sizeof(lichao[0])); i++) {
    lichao[i] = {-900000000000LL, -900000000000LL};
  }
  for (int l = n - 1; l >= 0; l--) {
    if (l < n - 1) best = max(best, query(l) + suff[l]);
    insert({v[l], -suff[l] - v[l] * l});
  }
  cout << tot + best << "\n";
}
