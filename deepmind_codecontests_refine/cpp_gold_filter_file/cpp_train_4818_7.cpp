#include <bits/stdc++.h>
using namespace std;
template <class T>
using vc = vector<T>;
template <class T>
using vvc = vc<vc<T>>;
template <class T>
void mkuni(vector<T>& v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}
long long rand_int(long long l, long long r) {
  static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
  return uniform_int_distribution<long long>(l, r)(gen);
}
template <class T>
void print(T x, int suc = 1) {
  cout << x;
  if (suc == 1)
    cout << '\n';
  else
    cout << ' ';
}
template <class T>
void print(const vector<T>& v, int suc = 1) {
  for (int i = 0; i < v.size(); i++)
    print(v[i], i == (int)(v.size()) - 1 ? suc : 2);
}
int dp[82][82][3400];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  memset(dp, -0x3f, sizeof(dp));
  vector<int> all;
  vector<int> pos;
  {
    int pre = 0;
    for (int i = 0; i < n; i++) {
      if (a[i]) {
        all.push_back(i - pre);
        pos.push_back(i);
        pre = i + 1;
      }
    }
    all.push_back(n - pre);
    pos.push_back(n);
  }
  int sz = all.size();
  int zcnt = n - sz + 1;
  dp[0][0][0] = 0;
  for (int i = 1; i <= sz; i++) {
    for (int j = 0; j <= zcnt; j++) {
      for (int k = 0; k <= n * (n - 1) / 2; k++) {
        if (dp[i - 1][j][k] < 0) continue;
        for (int cc = 0; cc + j <= zcnt; cc++) {
          int pre = i - 1 + j + cc;
          int d = abs(pre - pos[i - 1]);
          int cur = cc * j;
          dp[i][j + cc][k + d] =
              max(dp[i - 1][j][k] + cur, dp[i][j + cc][k + d]);
        }
      }
    }
  }
  vector<int> ans(n * (n - 1) / 2 + 1);
  for (int i = 0; i < ans.size(); i++) ans[i] = dp[sz][zcnt][i];
  for (int i = 1; i < ans.size(); i++) ans[i] = max(ans[i - 1], ans[i]);
  print(ans);
}
