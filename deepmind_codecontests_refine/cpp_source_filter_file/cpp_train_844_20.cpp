#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s = "abcd";
  string ans = "";
  int m = n / 4;
  for (int i = 0; i < m; i++) {
    ans += s;
  }
  int z = m % 4;
  for (int i = 0; i < z; i++) {
    ans += s[i];
  }
  cout << ans << endl;
}
