#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p, i, j, ans = 0;
  string s;
  cin >> n >> p;
  cin >> s;
  if (p > (n - 1) / 2) {
    string temp = "";
    for (i = n - 1; i >= 0; i--) temp += s[i];
    s = temp;
    p = n - p + 1;
  }
  p--;
  int lower = p + 1, upper = p;
  for (i = 0; i <= p; i++) {
    if (s[i] != s[n - 1 - i]) {
      lower = i;
      break;
    }
  }
  for (i = p + 1; i < n / 2; i++) {
    if (s[i] != s[n - 1 - i]) upper = i;
  }
  for (i = p; i >= lower; i--) {
    ans++;
    if (s[i] != s[n - i - 1])
      ans += min(abs(s[i] - s[n - i - 1]), 26 - abs(s[i] - s[n - i - 1]));
  }
  for (i = p + 1; i <= upper; i++) {
    ans++;
    if (s[i] != s[n - i - 1])
      ans += min(abs(s[i] - s[n - i - 1]), 26 - abs(s[i] - s[n - i - 1]));
  }
  if (lower == p + 1 and upper == p)
    cout << "0\n";
  else if (lower == p + 1)
    cout << ans - 1 << endl;
  else if (upper == p)
    cout << ans - 1 << endl;
  else {
    if (upper - p + 1 <= p - lower + 1)
      cout << ans - 2 + upper - p + 1 << endl;
    else
      cout << ans - 2 + p - lower + 1 << endl;
  }
  return 0;
}
