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
long double n, m;
vector<long double> takeoff, landing;
bool journey_possible(long double x) {
  for (int i = 0; i < n; ++i) {
    long double required = (m + x) / takeoff[i];
    if (required > x) return false;
    x -= required;
    required = (m + x) / landing[i];
    if (required > x) return false;
    if (i == n - 1 && abs(required - x) < EPS) return true;
    x -= required;
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  long double temp;
  for (int i = 0; i < n; ++i) {
    long double x;
    cin >> x;
    takeoff.push_back(x);
  }
  for (int i = 0; i < n; ++i) {
    long double x;
    cin >> x;
    if (i == 0)
      temp = x;
    else
      landing.push_back(x);
  }
  landing.push_back(temp);
  if (!journey_possible(1e10)) {
    cout << -1 << "\n";
    return 0;
  }
  long double l = 0, r = 1e10, m;
  while (r - l > EPS) {
    m = l + (r - l) / 2;
    if (journey_possible(m))
      r = m;
    else
      l = m;
  }
  cout << setprecision(10) << r << "\n";
}
