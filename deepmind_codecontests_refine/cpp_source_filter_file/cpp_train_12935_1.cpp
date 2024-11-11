#include <bits/stdc++.h>
using namespace std;
int n;
int a[200005];
int cnt[30];
int main() {
  iostream::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    for (int j = 0; j < 20; j++) {
      cnt[j] += ((a[i] >> j & 1));
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int mjk = 0;
    for (int j = 0; j < 20; j++) {
      if (cnt[j] > 0) mjk += (1 << j), cnt[j]--;
    }
    ans += mjk * mjk;
  }
  cout << ans;
}
