#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int k;
  cin >> s >> k;
  for (int i = 0; i < k; i++) {
    s += "*";
  }
  int n = s.size();
  int ans = INT_MIN;
  for (int i = 0; i < n; i++) {
    for (int l = 1; l + i < n; l++) {
      int j = i;
      int temp = 0;
      while (j < l + i && j + l < n &&
             (s[j] == s[l + j] || s[j] == '*' || s[j + l] == '*')) {
        j++;
        temp++;
      }
      if (j == l + i - 1) ans = max(ans, temp);
    }
  }
  cout << 2 * ans << endl;
}
