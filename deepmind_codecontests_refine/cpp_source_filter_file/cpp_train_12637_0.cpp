#include <bits/stdc++.h>
using namespace std;
template <class T>
class ConvexHullTrick {
 public:
  vector<T> M, B;
  int pointer;
  bool bad(int l1, int l2, int l3) {
    return 1.0 * (B[l3] - B[l1]) * (M[l1] - M[l2]) <
           1.0 * (B[l2] - B[l1]) * (M[l1] - M[l3]);
  }
  void add(T m, T b) {
    M.push_back(m);
    B.push_back(b);
    while (M.size() >= 3 && bad(M.size() - 3, M.size() - 2, M.size() - 1)) {
      M.erase(M.end() - 2);
      B.erase(B.end() - 2);
    }
  }
  T query(T x) {
    if (pointer >= M.size()) pointer = M.size() - 1;
    while (pointer < M.size() - 1 &&
           M[pointer + 1] * x + B[pointer + 1] < M[pointer] * x + B[pointer])
      pointer++;
    return M[pointer] * x + B[pointer];
  }
  void init() {
    M.clear();
    B.clear();
    pointer = 0;
  }
};
const int mxn = 111111;
int n, m, p, idx;
long long d[mxn], val, t[mxn], s[mxn];
long long dp[111][mxn];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ConvexHullTrick<long long> ch[2];
  idx = 0;
  cin >> n >> m >> p;
  d[0] = d[1] = 1;
  for (int i = 2; i <= n; i++) {
    cin >> d[i];
    d[i] += d[i - 1];
  }
  for (int i = 1; i <= m; i++) {
    cin >> val;
    t[i] = -d[val];
    cin >> val;
    t[i] += val;
  }
  sort(t + 1, t + m + 1);
  s[0] = 0;
  for (int i = 1; i <= m; i++) s[i] = s[i - 1] + t[i];
  ch[idx].init();
  for (int i = 1; i <= m; i++) {
    ch[idx].add(-i, s[i] + (t[i] * i - s[i]));
    dp[1][i] = t[i] * i - s[i];
  }
  for (int i = 2; i <= p; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j] = (t[j] * j - s[j]) + ch[idx].query(t[j]);
    }
    idx = 1 - idx;
    ch[idx].init();
    for (int j = 1; j <= m; j++) {
      ch[idx].add(-i, dp[i - 1][j] + s[j]);
    }
  }
  cout << dp[p][m] << "\n";
  return 0;
}
