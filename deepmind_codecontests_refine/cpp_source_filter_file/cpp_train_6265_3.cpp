#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, i, j, cnt = 0, flag = 1, temp = 0;
  string s;
  cin >> n >> s;
  for (i = 0; i < n; i++) {
    if (s[i] == '(')
      cnt++;
    else
      cnt--;
  }
  if (cnt != 0) {
    cout << "NO"
         << "\n";
    return 0;
  }
  cnt = 0, flag = 0;
  for (i = 0; i < n; i++) {
    if (s[i] == ')') {
      if (cnt == 0)
        flag++;
      else
        cnt--;
    } else
      cnt--;
  }
  if (flag <= 1)
    cout << "YES"
         << "\n";
  else
    cout << "NO"
         << "\n";
  return 0;
}
