#include <bits/stdc++.h>
using namespace std;
const int INF = 2 * int(1e9);
const long long INFll = 1ll * int(1e9) * int(1e9);
const int MOD = 1000000007;
template <typename T, typename Q>
ostream& operator<<(ostream& out, pair<T, Q>& a) {
  out << a.first << " " << a.second;
  return out;
}
template <typename T, typename Q>
istream& operator>>(istream& in, pair<T, Q>& a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T>
istream& operator>>(istream& in, vector<T>& a) {
  for (int i = 0; i < a.size(); ++i) in >> a[i];
  return in;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T> a) {
  for (int i = 0; i < a.size(); ++i)
    if (i == a.size() - 1)
      out << a[i];
    else
      out << a[i] << " ";
  return out;
}
struct segtree {
  vector<long long> t;
  int n;
  segtree(int n) : n(n) { t.assign(n << 1, 0); }
  long long query(int l, int r) {
    long long ans = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) ans += t[l++];
      if (r & 1) ans += t[--r];
    }
    return ans;
  }
  void modify(int v, int y) {
    for (t[v += n] += y; v > 1; v >>= 1) t[v >> 1] = t[v] + t[v ^ 1];
  }
};
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  k = min(k, n - k);
  segtree t = n;
  int cur = 0;
  long long ans = 1;
  for (int i = 0; i < n; ++i) {
    if (cur + k >= n) {
      ans += t.query(cur + 1, n);
      ans += t.query(0, (cur + k) - n);
    } else {
      ans += t.query(cur + 1, cur + k);
    }
    t.modify(cur, 1);
    cur = (cur + k) % n;
    t.modify(cur, 1);
    ans++;
    cout << ans << " ";
  }
  if (0)
    cerr << fixed << setprecision(0)
         << "TIME = " << clock() / (long double)CLOCKS_PER_SEC * 1000 << "\n";
  return 0;
}
