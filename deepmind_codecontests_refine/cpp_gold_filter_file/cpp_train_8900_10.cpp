#include <bits/stdc++.h>
using namespace std;
int ar[100010];
int mn[100010];
int main() {
  int n;
  cin >> n;
  for (int i = (1); i < (n + 1); ++i) cin >> ar[i];
  mn[n + 1] = 1000000003ll;
  for (int i = n; i >= 1; i--) {
    mn[i] = min(ar[i], mn[i + 1]);
  }
  int mx = 0, cnt = 0;
  for (int i = 1; i <= n; i++) {
    mx = max(mx, ar[i]);
    if (mx <= mn[i + 1]) {
      mx = 0;
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
