#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
int main() {
  string s;
  getline(cin, s);
  int val = 0;
  long long ans = 0;
  for (int idx = 0; idx < s.length(); ++idx) {
    char c = s[idx];
    int s_val = c - '0';
    val = ((val * 10) + s_val) % 100;
    if (val % 4 == 0) {
      ans += idx;
    }
    if ((s_val % 4) == 0) ans++;
  }
  cout << ans << endl;
  return 0;
}
