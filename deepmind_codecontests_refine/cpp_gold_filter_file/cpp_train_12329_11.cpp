#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, ans = 0;
  string s;
  cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'B') {
      ans += 1LL << i;
    }
  }
  cout << ans << "\n";
}
