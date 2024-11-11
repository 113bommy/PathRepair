#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  int flag = 1;
  while (t--) {
    string str;
    cin >> str;
    int n = str.length();
    if (n < 5)
      break;
    else {
      for (int i = 0; i < n; i++)
        if (str[i] >= 'a' && str[i] <= 'z') {
          flag++;
          break;
        }
      if (flag != 2) break;
      for (int i = 0; i < n; i++)
        if (str[i] >= 'A' && str[i] <= 'Z') {
          flag++;
          break;
        }
      if (flag != 3) break;
      for (int i = 0; i < n; i++)
        if (str[i] >= '0' && str[i] <= '9') {
          flag++;
          break;
        }
    }
  }
  (flag == 4) ? cout << "Correct" : cout << "Too weak";
}
