#include <bits/stdc++.h>
using namespace std;
template <class T>
inline int maximize(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline int minimize(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
const int N = 333, INF = 0x3f3f3f3f;
int n, m, ans = -INF, a[N];
priority_queue<int> P;
priority_queue<int, vector<int>, greater<int> > Q;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      for (int k = 1; k < i; ++k) P.push(a[k]);
      for (int k = i; k <= j; ++k) Q.push(a[k]);
      for (int k = j + 1; k <= n; ++k) P.push(a[k]);
      int cnt = 0;
      while (!P.empty()) {
        if (cnt < m && Q.top() < P.top()) {
          Q.pop();
          Q.push(P.top());
          ++cnt;
        }
        P.pop();
      }
      int tmp = 0;
      while (!Q.empty()) {
        tmp += Q.top();
        Q.pop();
      }
      maximize(ans, tmp);
    }
  }
  cout << ans << endl;
  return 0;
}
