#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, c = 0;
  cin >> n >> k;
  string s = "0123456789", z;
  while (n--) {
    cin >> z;
    bool flag = 1;
    for (int i = 0; i <= k; ++i) {
      if (z.find(s[i]) == -1) {
        flag = 0;
        break;
      }
    }
    if (flag) c++;
  }
  cout << c;
  return 0;
}
