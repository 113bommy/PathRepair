#include <bits/stdc++.h>
using namespace std;
long long n, j, cnt1, cnt2, mxi, mni;
int main() {
  long long n, h[100001], m[100001], t[100001], mx = -1;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> h[i] >> m[i];
    t[i] = h[i] * 60 + m[i];
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (t[i] == t[i + 1]) {
      ans++;
    } else {
      mx = max(mx, ans);
      ans = 0;
    }
  }
  mx = max(mx, ans);
  cout << mx + 1;
  return 0;
}
