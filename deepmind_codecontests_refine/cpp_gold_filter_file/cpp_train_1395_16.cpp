#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int n;
  long long int ans = 0;
  cin >> s;
  n = s.size();
  for (int i = 0; i < n; i++) {
    ans *= 2;
    ans += s[i] - '0';
    ans %= 1000000007;
  }
  for (int i = 1; i < n; i++) {
    ans *= 2;
    ans %= 1000000007;
  }
  cout << ans;
}
