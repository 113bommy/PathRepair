#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  string s;
  cin >> a >> s;
  long long cnt[40000];
  memset(cnt, 0, sizeof(cnt));
  int len = s.length();
  for (int i = 0; i < len; ++i) {
    int sum = 0;
    for (int j = i; j < len; ++j) {
      sum += s[j] - '0';
      if (sum <= a)
        cnt[sum]++;
      else
        break;
    }
  }
  long long ans = 0;
  if (a == 0) {
    ans = cnt[0] * 1ll * len * (len + 1) - cnt[0] * cnt[0];
    cout << ans << endl;
    return 0;
  }
  for (int i = 1; i < 40000; ++i) {
    if (a % i == 0 && a / i < 40000) ans += cnt[i] * cnt[a / i];
  }
  cout << ans << endl;
  return 0;
}
