#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, A, B, C, T, ans = 0, i;
  cin >> n >> A >> B >> C >> T;
  long long t[n + 1];
  for (i = 1; i <= n; i++) {
    cin >> t[i];
  }
  if (B >= C) {
    cout << A * n;
  } else {
    for (i = 1; i <= n; i++) {
      ans += (T - t[i]) * (C - B) + A;
    }
    cout << ans;
  }
  return 0;
}
