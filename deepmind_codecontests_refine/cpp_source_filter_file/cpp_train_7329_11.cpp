#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using VI = vector<int>;
using VC = vector<char>;
using VS = vector<string>;
using VL = vector<long long>;
using VVI = vector<VI>;
using VVL = vector<VL>;
using MII = map<int, int>;
using MIVI = map<int, VI>;
using MSS = map<string, string>;
using MLL = map<LL, LL>;
int READ_INT() {
  int temp;
  cin >> temp;
  return temp;
}
LL READ_LONG() {
  LL temp;
  cin >> temp;
  return temp;
}
void mcs(VI &series, int &max_sum) {
  int s = 0;
  for (auto x : series) {
    s += x;
    max_sum = max(max_sum, s);
    if (s < 0) s = 0;
  }
}
template <typename T>
T MAX(T t) {
  return t;
}
template <typename T, typename... Args>
T MAX(T t, Args... args) {
  return max(t, MAX(args...));
}
const int MOD = int(1e9) + 7;
const int INF = 1e9 + 5;
const double PI = acos(-1.0);
const double EPS = 1e-9;
int main() {
  ios::sync_with_stdio(false);
  int n = READ_INT();
  VI arr, prefix_sum = {0};
  int p = 0;
  for (int i = 0; i < n; ++i) {
    int temp = READ_INT();
    arr.push_back(temp);
    p += temp;
    prefix_sum.push_back(p);
  }
  string s;
  cin >> s;
  int ans = 0;
  int r_sum = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == '0') continue;
    int t = prefix_sum[i];
    ans = max(ans, t);
    r_sum += arr[i];
  }
  ans = max(ans, r_sum);
  cout << ans << "\n";
  return 0;
}
