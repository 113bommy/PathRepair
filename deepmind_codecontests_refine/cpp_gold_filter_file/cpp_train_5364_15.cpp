#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, p, c = 0, ans = 0;
  cin >> n >> p;
  string s[n];
  string a = "half", b = "plus";
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == a && s[i] != a + b)
      c = c * 2;
    else
      c = c * 2 + 1;
    ans += c * p / 2;
  }
  cout << ans;
}
