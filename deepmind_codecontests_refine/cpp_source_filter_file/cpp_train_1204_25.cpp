#include <bits/stdc++.h>
using namespace std;
int cnt[100500];
int a[100500];
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  int ans = 1;
  for (int i = 2; i <= n; i++) {
    int now = 0;
    for (int st = i; st <= 100100; st += i) {
      now += cnt[st];
    }
    ans = max(now, ans);
  }
  cout << ans << endl;
  return 0;
}
