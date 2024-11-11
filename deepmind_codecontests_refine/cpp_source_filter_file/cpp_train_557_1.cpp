#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  cin >> n;
  long long a, b;
  long long a_val = 0;
  long long g_val = 0;
  string ans;
  while (n--) {
    cin >> a >> b;
    if (a_val == g_val) {
      if (a == min(a, b)) {
        ans.push_back('A');
        a_val += a;
      } else {
        ans.push_back('G');
        g_val += b;
      }
    } else if (abs(a + a_val - g_val) < abs(b + g_val - a_val)) {
      ans.push_back('A');
      a_val += a;
    } else {
      ans.push_back('G');
      g_val += b;
    }
  }
  if (abs(a_val - g_val) < 500) {
    cout << ans << endl;
  } else
    cout << "-1" << endl;
  return 0;
}
