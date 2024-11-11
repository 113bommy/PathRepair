#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  cin >> n >> s;
  int ans = -1;
  for (int i = 0; i < n - 1; i++) {
    if (s[i + 1] > s[i]) {
      ans = 1;
      break;
    }
  }
  if (ans == -1)
    cout << "NO";
  else {
    cout << "YES" << endl;
    cout << ans + 1 << " " << ans + 2 << endl;
  }
  return 0;
}
