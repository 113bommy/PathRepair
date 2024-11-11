#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<LL>;
using VVL = vector<VL>;
using VD = vector<double>;
using VVD = vector<VD>;
using PII = pair<int, int>;
using PDD = pair<double, double>;
using PLL = pair<LL, LL>;
using VPII = vector<PII>;
template <typename T>
using VT = vector<T>;
template <typename T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;
const int MAX = 111;
int n, s;
int h[MAX], m[MAX];
int get(int i, int j) { return (h[j] * 60 + m[j]) - (h[i] * 60 + m[i]); }
int main(void) {
  cin >> n >> s;
  for (int(i) = 0; (i) < (n); (i)++) cin >> h[i] >> m[i];
  if (h[0] * 60 + m[0] >= s + 1) {
    cout << 0 << " " << 0 << endl;
    return 0;
  }
  for (int(i) = 0; (i) < (n - 1); (i)++) {
    if (get(i, i + 1) >= s * 2 + 2) {
      cout << h[i] + (m[i] + s + 1) / 60 << " " << (m[i] + s + 1) % 60 << endl;
      return 0;
    }
  }
  cout << h[n - 1] + (m[n - 1] + s + 1) / 60 << " " << (m[n - 1] + s + 1) % 60
       << endl;
}
