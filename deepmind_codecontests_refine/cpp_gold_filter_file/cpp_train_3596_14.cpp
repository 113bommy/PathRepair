#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x, d, sum = 0, ans = 0;
  cin >> n >> x;
  string s[n];
  sum = x;
  cin.ignore();
  for (int i = 0; i < n; i++) {
    cin >> s[i] >> d;
    cin.ignore();
    if (s[i][0] == '+')
      sum += d;
    else {
      if (sum - d >= 0) {
        sum -= d;
      } else
        ans++;
    }
  }
  cout << sum << " " << ans;
}
