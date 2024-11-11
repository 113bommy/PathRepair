#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, s;
  cin >> a >> s;
  char c[10] = {'0'};
  for (int i = 0; i < s.size(); i++) {
    c[s[i] - '0']++;
  }
  for (int i = 0; i < a.size(); i++) {
    for (int j = 9; j > a[i] - '0'; j--) {
      if (c[j]) {
        a[i] = j + '0';
        c[j]--;
        break;
      }
    }
  }
  cout << a << '\n';
  return 0;
}
