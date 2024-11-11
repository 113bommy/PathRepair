#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans;
  ans = 0;
  string str;
  cin >> n;
  cin >> str;
  for (int i = 0; i < n; i++) {
    if (str[i] == '<')
      ans++;
    else
      break;
  }
  for (int i = n - 1; i >= 0; i--) {
    if (str[i] == '>')
      ans++;
    else
      break;
  }
  cout << ans << endl;
}
