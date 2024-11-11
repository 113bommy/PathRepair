#include <bits/stdc++.h>
using namespace std;
class C_ {};
template <typename T>
C_& operator<<(C_& __m, const T& __s) {
  if (!1) cerr << "\E[91m" << __s << "\E[0m";
  return __m;
}
C_ merr;
struct __s {
  __s() {
    if (1) {
      ios_base::Init i;
      cin.sync_with_stdio(0);
      cin.tie(0);
    }
  }
  ~__s() {
    merr << "Execution time: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
  }
} __S;
int A[333];
int B[333];
int main() {
  int m, t, r;
  int cur = -1000000;
  int ans = 0;
  memset(B, 255, sizeof(B));
  cin >> m >> t >> r;
  for (int i = 0; i < m; i++) {
    cin >> A[i];
  }
  if (t < r) {
    cout << "-1" << '\n';
    return 0;
  }
  for (int i = 0; i < m; i++) {
    int rr = r;
    for (int j = 0; j < r; j++) {
      if (B[j] >= A[i]) rr--;
    }
    if (A[i] - rr < cur) {
      cout << "-1" << '\n';
      return 0;
    }
    int idx = 0;
    for (int j = 0; j < r; j++) {
      if (B[j] >= A[i]) continue;
      ans++;
      B[j] = A[i] - idx + t - 1;
      idx++;
    }
    cur = A[i];
  }
  cout << ans << '\n';
  return 0;
}
