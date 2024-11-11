#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  int cnt = 0;
  cin >> s;
  for (int i = 0; i < n; i++) {
    int a1 = 0;
    int a2 = 0;
    for (int j = i; j < n; j++) {
      if (s[j] == 'L') {
        a1--;
      }
      if (s[j] == 'R') {
        a1++;
      }
      if (s[j] == 'U') {
        a2++;
      }
      if (s[j] == 'D') {
        a1--;
      }
      if (!a1 && !a2) cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
