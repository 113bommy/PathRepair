#include <bits/stdc++.h>
using namespace std;
template <typename T>
T GCD(T a, T b) {
  long long t;
  while (a) {
    t = a;
    a = b % a;
    b = t;
  }
  return b;
}
template <typename T>
string toString(T a) {
  return to_string(a);
}
template <typename T>
void toInt(string s, T &x) {
  stringstream str(s);
  str >> x;
}
inline int add(long long a, long long b) {
  a += b;
  if (a < 0) a += 1000000007;
  return a;
}
inline int sub(long long a, long long b) {
  a -= b;
  if (a < 0) a += 1000000007;
  return a;
}
inline int mul(long long a, long long b) { return (a * 1ll * b) % 1000000007; }
inline int pwr(long long x, long long y) {
  int ans = 1 % 1000000007;
  while (y) {
    if (y & 1) ans = mul(ans, x);
    x = mul(x, x);
    y >>= 1;
  }
  return ans;
}
inline int inv(int a) { return pwr(a, 1000000007 - 2); }
vector<int> aa;
int n, m;
vector<vector<int> > vec(501, vector<int>(501));
int dp[501][200];
int fun(int ind, int cur) {
  if (ind == n) {
    if (cur > 0) {
      cout << "TAK" << '\n';
      for (auto it : aa) {
        cout << it << " ";
      }
      cout << '\n';
      exit(0);
    } else {
      return 0;
    }
  }
  if (dp[ind][cur] != -1) {
    return dp[ind][cur];
  }
  int ans = 0;
  for (int i = 0; i < m; i++) {
    aa.push_back(i + 1);
    ans = fun(ind + 1, (cur ^ vec[ind][i]));
    aa.pop_back();
  }
  dp[ind][cur] = ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  int x = 0, v;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> v;
      vec[i][j] = v;
    }
  }
  memset(dp, -1, sizeof(dp));
  fun(0, 0);
  cout << "NIE" << '\n';
  return 0;
}
