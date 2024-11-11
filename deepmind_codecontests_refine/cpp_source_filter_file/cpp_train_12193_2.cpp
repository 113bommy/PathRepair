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
int n, k, a[2][300010];
int tail[2], nxttail[2];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[0][i];
  for (int i = 0; i < n; i++) cin >> a[1][i];
  if (k == 1) {
    int tail = 3;
    for (int i = 0; i < n; i++) {
      if (abs(a[0][i] - a[1][i]) > 1) {
        cout << "NO" << endl;
        return 0;
      }
      if (a[0][i] > a[1][i]) {
        if ((tail & 2) == 0) {
          cout << "NO" << endl;
          return 0;
        }
        tail = 1;
      } else if (a[1][i] > a[0][i]) {
        if ((tail & 1) == 0) {
          cout << "NO" << endl;
          return 0;
        }
        tail = 2;
      } else
        ;
    }
    cout << "YES" << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    nxttail[0] = nxttail[1] = INF;
    for (int t = 0; t < 2; t++) {
      if (tail[t] > k) continue;
      if (a[t][i] >= a[t ^ 1][i]) {
        int groups = 1 + (a[t][i] - (k - tail[t]) + k - 1) / k;
        if (a[t ^ 1][i] < groups - 1)
          continue;
        else if (a[t ^ 1][i] == groups - 1) {
          nxttail[t] = min(nxttail[t], (a[t][i] - (k - tail[t]) - 1) % k + 1);
        } else if (a[t ^ 1][i] > groups - 1) {
          nxttail[t ^ 1] = nxttail[t] = 1;
        }
      } else {
        int groups = (a[t ^ 1][i] + k - 1) / k;
        if (a[t][i] < groups - 1)
          continue;
        else if (a[t][i] == groups - 1) {
          nxttail[t ^ 1] = min(nxttail[t ^ 1], (a[t ^ 1][i] - 1) % k + 1);
        } else if (a[t][i] > groups - 1) {
          nxttail[t] = nxttail[t ^ 1] = 1;
        }
      }
    }
    tail[0] = nxttail[0];
    tail[1] = nxttail[1];
  }
  cout << (min(tail[0], tail[1]) < k ? "YES" : "NO") << endl;
  return 0;
}
