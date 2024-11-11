#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n = s.length();
  int a = s[n - 1] - 48;
  int index = 0;
  for (int i = 0; s[i]; i++) {
    if (s[i] % 2 == 0) {
      if (s[i] < s[n - 1]) {
        swap(s[i], s[n - 1]);
        cout << s << endl;
        return 0;
      }
      index = i;
    }
  }
  if (index == n - 1) {
    cout << -1 << endl;
    return 0;
  }
  swap(s[n - 1], s[index]);
  cout << s << endl;
}
