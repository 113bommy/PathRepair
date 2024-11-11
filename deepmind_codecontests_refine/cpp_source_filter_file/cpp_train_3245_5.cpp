#include <bits/stdc++.h>
using namespace std;
int n, k, h;
int num[1050];
int ans;
int main() {
  cin >> n >> k;
  int x;
  h = (n + 1) / 2;
  for (int i = 0; i < n; i++) {
    cin >> x;
    num[x]++;
  }
  int cnt = 0;
  for (int i = 0; i <= k; i++) {
    cnt += num[i] / 2;
    num[i] = num[i] % 2;
  }
  if (cnt >= h)
    ans = cnt;
  else {
    h -= cnt;
    ans += cnt * 2;
    for (int i = 0; i <= k; i++) {
      if (num[i] == 1 && h > 0) {
        h--;
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
