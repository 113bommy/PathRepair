#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
constexpr auto MOD = 1000000007LL;
constexpr auto LINF = (1LL << 60);
constexpr auto INF = 2147483647LL;
constexpr auto PI = 3.1415926535897932384626433;
constexpr auto EPS = 1E-9;
template <typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> p) {
  out << p.first << ' ' << p.second;
  return out;
}
template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &p) {
  in >> p.first >> p.second;
  return in;
}
template <typename T>
istream &operator>>(istream &in, vector<T> &v) {
  for (auto &x : v) in >> x;
  return in;
}
template <typename T>
ostream &operator<<(ostream &out, vector<T> v) {
  for (int i = 0; i < v.size(); i++)
    out << v[i] << (i + 1 == v.size() ? '\n' : ' ');
  out.flush();
  return out;
}
int n, m, res[300010], nxt[20], f[20][300010];
pii b[300010];
bitset<20> a[300010];
vi qs[300010];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  memset(nxt, -1, sizeof(nxt));
  for (int i = 0; i < 20; i++) {
    fill(f[i], f[i] + 300010, INF);
  }
  for (int i = 0, x; i < n; i++) {
    cin >> x;
    a[i] = bitset<20>(x);
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    --b[i].first;
    --b[i].second;
    qs[b[i].first].push_back(i);
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < 20; j++) {
      if (a[i][j])
        f[j][i] = i;
      else {
        for (int k = 0; k < 20; k++) {
          if (a[i][k] && nxt[k] != -1) {
            f[j][i] = min(f[j][i], f[k][nxt[k]]);
          }
        }
      }
    }
    for (int j = 0; j < 20; j++) {
      if (a[i][j]) {
        nxt[j] = i;
      }
    }
    for (auto x : qs[i]) {
      int y = b[x].second;
      for (int j = 0; j < 20; j++) {
        res[x] |= (a[y][j] && f[j][i] <= y);
      }
    }
  }
  for (int i = 0; i < m; i++) {
    cout << (res[i] ? "Shi" : "Fou") << endl;
  }
  return 0;
}
