#include <bits/stdc++.h>
using namespace std;
int cnt[123];
bool myfunc(int a, int b) { return a > b; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  int n;
  cin >> n;
  int arr[n];
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    cnt[arr[i]]++;
  }
  sort(cnt, cnt + n, myfunc);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] >= 2) {
      if (cnt[i] % 2 == 0)
        ans += cnt[i];
      else
        ans += (cnt[i] - 1);
    }
  }
  cout << ans / 4 << '\n';
  return 0;
}
