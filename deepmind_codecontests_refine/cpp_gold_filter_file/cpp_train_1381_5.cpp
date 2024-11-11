#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
ostream& operator<<(ostream& out, const pair<T1, T2> p) {
  out << '(' << p.first << ',' << p.second << ')';
  return out;
}
template <class T1, class T2>
istream& operator>>(istream& in, pair<T1, T2>& p) {
  in >> p.first >> p.second;
  return in;
}
template <class T>
istream& operator>>(istream& in, vector<T>& v) {
  for (T& x : v) in >> x;
  return in;
}
template <class T>
ostream& operator<<(ostream& out, const vector<vector<T>>& v) {
  for (const vector<T>& x : v) out << x << '\n';
  return out;
}
template <class T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  for (const T& x : v) out << x << ' ';
  return out;
}
long long gcd(long long a, long long b) {
  if (b > a) swap(a, b);
  return (b ? gcd(b, a % b) : a);
}
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using tiii = pair<pair<int, int>, int>;
using vi = vector<int>;
using vl = vector<long long>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;
const int h = 1000000007;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cerr.setstate(ios::failbit);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vi v(n), v2(n), cnt(n);
    cin >> v >> v2;
    for (int x : v) cnt[x - 1]++;
    for (int x : v2) cnt[x - 1]++;
    bool y = 1;
    for (int x : cnt)
      if (x != 2) y = 0;
    if (!y) {
      cout << "-1\n";
      continue;
    }
    vi vis(n);
    vvi ind(n);
    for (int i = (0); i < (n); i++) ind[v[i] - 1].push_back(i);
    for (int i = (0); i < (n); i++) ind[v2[i] - 1].push_back(i);
    int ans = 0;
    vi final_inds;
    for (int i = (0); i < (n); i++) {
      int x = i;
      if (vis[x]) continue;
      int val = v[x] - 1;
      set<int> all_inds, swapped_inds;
      while (!vis[x]) {
        all_inds.insert(x + 1);
        vis[x] = 1;
        x = ind[val][ind[val][0] == x];
        if (v[x] != val + 1) {
          swapped_inds.insert(x + 1);
          swap(v[x], v2[x]);
        }
        val = v2[x] - 1;
      }
      if (swapped_inds.size() < all_inds.size() - swapped_inds.size()) {
        for (int x : swapped_inds) final_inds.push_back(x);
        ans += swapped_inds.size();
      } else {
        for (int x : all_inds)
          if (!swapped_inds.count(x)) final_inds.push_back(x);
        ans += all_inds.size() - swapped_inds.size();
      }
    }
    cout << ans << '\n' << final_inds << '\n';
  }
}
