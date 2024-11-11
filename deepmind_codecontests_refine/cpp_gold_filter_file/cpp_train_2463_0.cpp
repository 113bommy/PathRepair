#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
bool umax(T1 &a, const T2 &b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T1, typename T2>
bool umin(T1 &a, const T2 &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
T sqr(T a) {
  return a * a;
}
mt19937 rng(20010709);
const int mod = 1000000007;
const int INF = 1000000001;
int pr[51][101], nxt[51][101];
int n, a[20005], p, k;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k >> p;
  if (n < k) {
    cout << 0;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] %= p;
  }
  for (int j = 0; j < k; j++) {
    for (int s = 0; s < p; s++) nxt[j][s] = -INF;
  }
  nxt[0][a[0]] = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < k; j++) {
      for (int s = 0; s < p; s++) {
        pr[j][s] = nxt[j][s];
        nxt[j][s] = -INF;
      }
    }
    for (int s = 0; s < p; s++) {
      int newValue = a[i] + s;
      if (newValue >= p) newValue -= p;
      for (int j = 0; j < k; j++) {
        umax(nxt[j + 1][a[i]], pr[j][s] + s);
        umax(nxt[j][newValue], pr[j][s]);
      }
    }
  }
  int result = 0;
  for (int i = 0; i < p; i++) umax(result, nxt[k - 1][i] + i);
  cout << result << "\n";
  return 0;
}
