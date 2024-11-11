#include <bits/stdc++.h>
using namespace std;
int main() {
  long int n, t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l = 0;
    int r = n - 1;
    int flag = 0;
    while (l <= r) {
      if (abs(s[r] - s[l]) != 2 && s[r] - s[l] != 0) {
        flag = 1;
        break;
      }
      l++;
      r--;
    }
    if (flag == 1)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
