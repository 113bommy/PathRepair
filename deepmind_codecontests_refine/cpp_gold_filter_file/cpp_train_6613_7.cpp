#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1000000")
using namespace std;
template <typename T>
inline T SQR(T a) {
  return a * a;
}
template <typename T>
struct point {
  T x, y;
  point(const T& _x, const T& _y) : x(_x), y(_y) {}
  point() : x(0), y(0) {}
  bool operator<(const T& r) { return x == r.x ? y < r.y : x < r.x; }
};
const int INF = numeric_limits<int>::max();
const double eps = 1e-6;
const double PI = 2 * asin(1.0);
const int maxn = 19;
int dp[1 << maxn];
int pr[15][6] = {{1, 4, 8},          {2, 5, 9, 13},      {3, 6, 10, 14, 17},
                 {7, 11, 15, 18},    {12, 16, 19},       {3, 7, 12},
                 {2, 6, 11, 16},     {1, 5, 10, 15, 19}, {4, 9, 14, 18},
                 {8, 13, 17},        {1, 2, 3},          {4, 5, 6, 7},
                 {8, 9, 10, 11, 12}, {13, 14, 15, 16},   {17, 18, 19}};
bool dfs(int mask) {
  if (dp[mask] != -1) {
    return dp[mask];
  }
  bool oneLose = false;
  int tmask;
  for (int i = 0; i < 16; ++i) {
    int* ar = pr[i];
    for (int j = 0; ar[j] != 0; ++j) {
      if ((mask & (1 << (ar[j] - 1))) == 0) continue;
      tmask = mask;
      for (int k = j; ar[k] != 0; ++k) {
        if ((mask & (1 << (ar[k] - 1))) == 0) break;
        tmask ^= (1 << (ar[k] - 1));
        if (!dfs(tmask)) {
          oneLose = true;
        }
      }
    }
  }
  dp[mask] = oneLose;
  return dp[mask];
}
int main() {
  ios::sync_with_stdio(false);
  for (int i = 0; i < (1 << maxn); ++i) {
    dp[i] = -1;
  }
  dp[0] = 0;
  dfs((1 << maxn) - 1);
  string str;
  int pmask = 0;
  for (int i = 0; i < 19; ++i) {
    cin >> str;
    if (str == ".") {
    } else if (str == "O") {
      pmask ^= (1 << i);
    } else {
      assert(0);
    }
  }
  if (dp[pmask] == 1) {
    cout << "Karlsson";
  } else if (dp[pmask] == 0) {
    cout << "Lillebror";
  } else {
    assert(false);
  }
  return 0;
}
