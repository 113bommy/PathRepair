#include <bits/stdc++.h>
using namespace std;
char memo[2][2];
int n;
string str1, str2;
int main() {
  std::ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t-- > 0) {
    cin >> n;
    cin >> str1;
    cin >> str2;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (str1[i] != str2[i]) {
        if (cnt >= 2) {
          cnt = -1;
          break;
        }
        memo[cnt][0] = str1[i];
        memo[cnt][1] = str2[i];
        cnt++;
      }
    }
    if (cnt == 0)
      cout << "Yes" << endl;
    else if (cnt == 2) {
      if ((memo[0][0] == memo[1][0]) && (memo[0][1] == memo[1][1]))
        cout << "YES" << endl;
      else
        cout << "No" << endl;
    } else
      cout << "No" << endl;
  }
  return 0;
}
