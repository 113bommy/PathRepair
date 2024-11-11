#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000006];
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> s;
    int l = s.length();
    int cnt = 0;
    for (int i = 0; i < l; i++) {
      if (s[i] == '+') cnt++;
      if (s[i] == '-') cnt--;
      a[i + 1] = cnt;
    }
    long long ans = 0, cur = 0;
    for (int i = 1; i <= l; i++) {
      while (cur + a[i] < 0) {
        cur++;
        ans += i;
      }
    }
    cout << ans + l << endl;
  }
  return 0;
}
