#include <bits/stdc++.h>
using namespace std;
const long long LINF = (long long)1e18;
const int INF = (int)1e9 + 7;
const int N = (int)1e6 + 7;
const double EPS = (double)1e-9;
const double PI = (double)3.14159265359;
const int MODULO[6] = {INF,        1000019677, 1000019393,
                       1000007521, 1000024073, 1000009667};
const int PF[5] = {77, 31, 98, 45, 67};
const int nx[4] = {0, 0, 1, -1};
const int ny[4] = {1, -1, 0, 0};
inline bool eq(const long double &a, const long double &b) {
  return fabs(a - b) < EPS;
}
int n, k;
string a[N];
int b[N];
long long second[N];
inline int to_int(const string &x) {
  int ret = 0;
  for (int i = (x[0] == '-' ? 1 : 0); i < x.size(); i++)
    ret = ret * 10 + (x[i] - 48);
  if (x[0] == '-') ret *= -1;
  return ret;
}
inline string str(int x) {
  bool neg = (x < 0);
  x = abs(x);
  string st = "";
  while (x) {
    st += (x % 10) + '0';
    ;
    x /= 10;
  }
  if (neg) st += "-";
  reverse(st.begin(), st.end());
  return st;
}
inline bool impossible() {
  for (int i = 1; i <= n; i++) second[i] = second[i - 1] + b[i];
  vector<long long> all;
  for (int i = 1; i + k - 1 <= n; i++)
    all.push_back(second[i + k - 1] - second[i - 1]);
  for (int i = 0; i + 1 < all.size(); i++)
    if (all[i] >= all[i + 1]) return true;
  return false;
}
inline void update(int l, int r) {
  int mn = (l > k ? b[l - k] + 1 : -2 * INF),
      mx = (r + k <= n ? b[r + k] - 1 : 2 * INF);
  int sz = (r - l) / k + 1;
  if (mn <= -(sz / 2) && sz / 2 <= mx) {
    sz = -(sz / 2);
    for (int i = l; i <= r; i += k) b[i] = sz++;
  } else {
    long long fi = 0ll, se = 0ll;
    for (int i = r; i >= l; i -= k) fi += abs(mx - (i - r) / k);
    for (int i = l; i <= r; i += k) se += abs(mn + (i - l) / k);
    if (fi < se)
      for (int i = r; i >= l; i -= k) b[i] = mx - (i - r) / k;
    else
      for (int i = l; i <= r; i += k) b[i] = mn + (i - l) / k;
  }
}
int main() {
  srand(time(NULL));
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == "?") {
      if (i > k)
        b[i] = b[i - k] + 1;
      else
        b[i] = -INF;
    } else
      b[i] = to_int(a[i]);
  }
  for (int i = 1; i <= k; i++) {
    vector<int> id;
    for (int j = i; j <= n; j += k) id.push_back(j);
    int last = (a[i] == "?" ? i : INF);
    for (auto it : id) {
      if (a[it] != "?") {
        if (last <= it - k) update(last, it - k);
        last = it + k;
      }
    }
    if (a[id.back()] != "?") {
      if (last <= id.back()) update(last, id.back());
    }
  }
  if (impossible()) {
    cout << "Incorrect sequence";
    return 0;
  }
  for (int i = 1; i <= n; i++) cout << b[i] << ' ';
  return 0;
}
