#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, ans, pre = 1, cnt = 0;
  string s;
  cin >> n >> s;
  ans = n * (n + 1) / 2 - n;
  for (int i = 1; i < n; i++) {
    if (s[i] != s[i - 1]) {
      cnt += pre;
      pre = 1;
    } else
      pre++;
  }
  pre = 1;
  for (int i = n - 1; i >= 1; i--) {
    if (s[i] != s[i - 1]) {
      cnt += (pre - 1);
      pre = 1;
    } else
      pre++;
  }
  cout << ans - cnt;
}
