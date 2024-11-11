#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int x;
  scanf("%d", &x);
  return x;
}
template <typename T>
inline istream& operator>>(istream& i, vector<T>& v) {
  for (int j = 0; j < ((int)(v).size()); ++j) i >> v[j];
  return i;
}
template <typename T>
string join(const vector<T>& v) {
  stringstream s;
  for (int i = 0; i < ((int)(v).size()); ++i) s << ' ' << v[i];
  return s.str().substr(1);
}
template <typename T>
inline ostream& operator<<(ostream& o, const vector<T>& v) {
  if ((int)(v).size()) o << join(v);
  return o;
}
template <typename T1, typename T2>
inline istream& operator>>(istream& i, pair<T1, T2>& v) {
  return i >> v.first >> v.second;
}
template <typename T1, typename T2>
inline ostream& operator<<(ostream& o, const pair<T1, T2>& v) {
  return o << v.first << "," << v.second;
}
template <typename T>
inline long long int suma(const vector<T>& a) {
  long long int res(0);
  for (auto&& x : a) res += x;
  return res;
}
const double eps = 1e-10;
const long long int LINF = 1e18;
const int INF = 1001001001;
const int MX = 10005;
int dp[MX];
int main() {
  int n, l, r;
  scanf("%d%d%d", &n, &l, &r);
  vector<int> ab(n);
  cin >> ab;
  int s = suma(ab);
  l = s - l;
  r = s - r;
  swap(l, r);
  if (r < 0) {
    puts("0");
    return 0;
  };
  (r = max(r, 0));
  vector<int> a, b;
  for (int i = 0; i < (n); ++i) {
    int f;
    cin >> f;
    if (f)
      a.push_back(ab[i]);
    else
      b.push_back(ab[i]);
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  for (int i = 0; i < (r + 1); ++i) dp[i] = -INF;
  dp[0] = 0;
  for (int i = 0; i < ((int)(b).size()); ++i)
    for (int j = (r - b[i] + 1) - 1; j >= 0; --j)
      (dp[j + b[i]] = max(dp[j + b[i]], dp[j]));
  for (int i = 0; i < ((int)(a).size()); ++i) {
    for (int j = (r - a[i] + 1) - 1; j >= 0; --j) {
      int nj = j + a[i];
      int x = (l <= nj && nj <= r);
      (dp[nj] = max(dp[nj], dp[j] + x));
    }
  }
  int ans = 0;
  for (int i = 0; i < (r + 1); ++i) (ans = max(ans, dp[i]));
  cout << ans << endl;
  return 0;
}
