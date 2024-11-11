#include <bits/stdc++.h>
using namespace std;
struct _ {
  _() { ios_base::sync_with_stdio(0); }
} _;
template <class A, class B>
ostream &operator<<(ostream &o, pair<A, B> t) {
  o << "(" << t.first << ", " << t.second << ")";
  return o;
}
template <class T>
void PV(T a, T b) {
  while (a != b) cout << *a++, cout << (a != b ? " " : "\n");
}
template <class T>
inline bool chmin(T &a, T b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
inline bool chmax(T &a, T b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
string tostring(T first, int len = 0) {
  stringstream ss;
  ss << first;
  string r = ss.str();
  if (r.length() < len) r = string(len - r.length(), '0') + r;
  return r;
}
template <class T>
void convert(string first, T &r) {
  stringstream ss(first);
  ss >> r;
}
const int inf = 0x3f3f3f3f;
const long long linf = (~0UL >> 2);
const int mod = int(1e9) + 7;
const int N = 55;
const int M = 111;
int n, m, K;
long long a[N];
long long b[N];
int c[N];
int d[N];
long long dp[N][N][M];
pair<int, int> p[N][N][M];
int main() {
  cin >> n >> m >> K;
  vector<pair<pair<int, int>, pair<long long, long long>>> v;
  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b[i] >> c[i];
    v.push_back(make_pair(make_pair(c[i], i), make_pair(a[i], b[i])));
  }
  sort((v).begin(), (v).end());
  for (int i = 0; i < m; i++) {
    a[i + 1] = v[i].second.first;
    b[i + 1] = v[i].second.second;
    c[i + 1] = v[i].first.first;
  }
  fill(&dp[0][0][0], &dp[N][0][0], -linf);
  for (int i = 1; i <= m; i++)
    for (int j = 0; j <= b[i] - a[i]; j++) {
      dp[i][1][j] = a[i] + j;
      p[i][1][j] = make_pair(0, 0);
    }
  for (int i = 2; i <= m; i++)
    for (int cur = 0; cur <= b[i] - a[i]; cur++) {
      for (int j = 1; j < i; j++) {
        if (c[i] == c[j]) continue;
        for (int k = 1; k <= j && k <= n; k++)
          for (int first = 0; first <= b[j] - a[j]; first++) {
            long long A = cur + a[i];
            long long B = first + a[j];
            if (A == B + K || A == B * K) {
              if (chmax(dp[i][k + 1][cur], dp[j][k][first] + A)) {
                p[i][k + 1][cur] = make_pair(j, first);
              }
            }
          }
      }
    }
  long long res = 0;
  pair<int, int> r;
  for (int i = 1; i <= m; i++)
    for (int k = 0; k <= b[i] - a[i]; k++)
      if (chmax(res, dp[i][n][k])) r = make_pair(i, k);
  if (res == 0)
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    vector<pair<int, long long>> ans;
    for (int i = n; i >= 1; i--) {
      ans.push_back(
          make_pair(v[r.first - 1].first.second, r.second + a[r.first]));
      r = p[r.first][i][r.second];
    }
    reverse((ans).begin(), (ans).end());
    for (int i = 0; i < ans.size(); i++)
      cout << ans[i].first << " " << ans[i].second << endl;
  }
  return 0;
}
