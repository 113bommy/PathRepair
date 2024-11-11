#include <bits/stdc++.h>
using namespace std;
template <class T>
using vec = vector<T>;
template <typename Iter>
ostream &_IterOutput_(ostream &o, Iter b, Iter e, const string ss = "",
                      const string se = "") {
  o << ss;
  for (auto it = b; it != e; it++) o << (it == b ? "" : ", ") << *it;
  return o << se;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &o, pair<T1, T2> &pair) {
  return o << "(" << pair.first << ", " << pair.second << ")";
}
template <typename T>
ostream &operator<<(ostream &o, const vector<T> &vec) {
  return _IterOutput_(o, begin(vec), end(vec), "[", "]");
}
template <typename T>
ostream &operator<<(ostream &o, const set<T> &st) {
  return _IterOutput_(o, begin(st), end(st), "{", "}");
}
template <typename T, size_t N>
ostream &operator<<(ostream &o, const array<T, N> &arr) {
  return _IterOutput_(o, begin(arr), end(arr), "|", "|");
}
template <typename T1, typename T2>
ostream &operator<<(ostream &o, const map<T1, T2> &mp) {
  o << "{";
  for (auto it = mp.begin(); it != mp.end(); it++) {
    o << (it == mp.begin() ? "" : ", ") << it->first << ":" << it->second;
  }
  o << "}";
  return o;
}
const int MX = 1333;
int N;
int ip[MX][MX];
double L[MX][MX];
int nz[8][MX][MX];
double lg[8][MX][MX];
int32_t main() {
  do {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  } while (0);
  cin >> N;
  for (int(i) = (1); (i) != (N + 1); (i) += ((N + 1) > (1) ? 1 : -1)) {
    string s;
    cin >> s;
    for (int(j) = (1); (j) != (N + 1); (j) += ((N + 1) > (1) ? 1 : -1)) {
      int t = s[j - 1] - '0';
      ip[i][j] = t;
      L[i][j] = (t ? log(t) : 0);
      for (int(k) = (0); (k) != (8); (k) += ((8) > (0) ? 1 : -1))
        lg[k][i][j] = L[i][j];
    }
  }
  for (int(i) = (N); (i) != (0); (i) += ((0) > (N) ? 1 : -1))
    for (int(j) = (N); (j) != (0); (j) += ((0) > (N) ? 1 : -1)) {
      nz[0][i][j] = (ip[i][j] == 0 ? 0 : nz[0][i + 1][j] + 1);
      nz[1][i][j] = (ip[i][j] == 0 ? 0 : nz[1][i][j + 1] + 1);
      nz[4][i][j] = (ip[i][j] == 0 ? 0 : nz[4][i + 1][j + 1] + 1);
      lg[0][i][j] += lg[0][i + 1][j];
      lg[1][i][j] += lg[1][i][j + 1];
      lg[4][i][j] += lg[4][i + 1][j + 1];
    }
  for (int(i) = (1); (i) != (N + 1); (i) += ((N + 1) > (1) ? 1 : -1))
    for (int(j) = (1); (j) != (N + 1); (j) += ((N + 1) > (1) ? 1 : -1)) {
      nz[2][i][j] = (ip[i][j] == 0 ? 0 : nz[2][i - 1][j] + 1);
      nz[3][i][j] = (ip[i][j] == 0 ? 0 : nz[3][i][j - 1] + 1);
      nz[6][i][j] = (ip[i][j] == 0 ? 0 : nz[6][i - 1][j - 1] + 1);
      lg[2][i][j] += lg[2][i - 1][j];
      lg[3][i][j] += lg[3][i][j - 1];
      lg[6][i][j] += lg[6][i - 1][j - 1];
    }
  for (int(i) = (1); (i) != (N + 1); (i) += ((N + 1) > (1) ? 1 : -1))
    for (int(j) = (N); (j) != (0); (j) += ((0) > (N) ? 1 : -1)) {
      nz[5][i][j] = (!ip[i][j] ? 0 : nz[5][i - 1][j + 1] + 1);
      lg[5][i][j] += lg[5][i - 1][j + 1];
    }
  for (int(i) = (N); (i) != (0); (i) += ((0) > (N) ? 1 : -1))
    for (int(j) = (1); (j) != (N + 1); (j) += ((N + 1) > (1) ? 1 : -1)) {
      nz[7][i][j] = (!ip[i][j] ? 0 : nz[7][i + 1][j - 1] + 1);
      lg[7][i][j] += lg[7][i + 1][j - 1];
    }
  double ba = -100;
  int bi, bj, bd, bt;
  const int INF = 10293847;
  for (int(i) = (1); (i) != (N + 1); (i) += ((N + 1) > (1) ? 1 : -1))
    for (int(j) = (1); (j) != (N + 1); (j) += ((N + 1) > (1) ? 1 : -1)) {
      if (!ip[i][j]) continue;
      int d1 = INF, d2 = INF;
      for (int(k) = (0); (k) != (4); (k) += ((4) > (0) ? 1 : -1))
        d1 = min(d1, nz[k][i][j] - 1);
      for (int(k) = (4); (k) != (8); (k) += ((8) > (4) ? 1 : -1))
        d2 = min(d2, nz[k][i][j] - 1);
      double v1 = lg[0][i - d1][j] - lg[0][i + d1 + 1][j] + lg[1][i][j - d1] -
                  lg[1][i][j + d1 + 1] - log(ip[i][j]);
      double v2 = lg[4][i - d2][j - d2] - lg[4][i + d2 + 1][j + d2 + 1] +
                  lg[5][i + d2][j - d2] - lg[1][i - d2 - 1][j + d2 + 1] -
                  log(ip[i][j]);
      if (v1 > ba) {
        ba = v1;
        bi = i;
        bj = j;
        bd = d1;
        bt = 1;
      }
      if (v2 > ba) {
        ba = v2;
        bi = i;
        bj = j;
        bd = d2;
        bt = 2;
      }
    }
  if (ba < 0) {
    cout << 0 << endl;
    return 0;
  }
  using i64 = long long;
  const i64 MD = 1000000007;
  i64 ans = 1;
  using pii = pair<int, int>;
  vector<pii> dir;
  if (bt == 1) {
    dir.push_back({1, 0});
    dir.push_back({-1, 0});
    dir.push_back({0, 1});
    dir.push_back({0, -1});
  } else {
    dir.push_back({1, 1});
    dir.push_back({-1, 1});
    dir.push_back({1, -1});
    dir.push_back({-1, -1});
  }
  for (auto d : dir) {
    int s = bd, x = bi, y = bj;
    while (s--) {
      x += d.first;
      y += d.second;
      ans = ans * ip[x][y] % MD;
    }
  }
  ans = ans * ip[bi][bj] % MD;
  cout << ans << endl;
  return 0;
}
