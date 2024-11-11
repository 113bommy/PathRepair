#include <bits/stdc++.h>
using namespace std;
int cnt[20000009][2];
int main() {
  int n;
  cin >> n;
  int lst = 0;
  cnt[0][0]++;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    lst = lst ^ x;
    if (i % 2) {
      ans += cnt[lst][1];
      cnt[lst][1]++;
    } else {
      ans += cnt[lst][0];
      cnt[lst][0]++;
    }
  }
  cout << ans << endl;
  return 0;
}
