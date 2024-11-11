#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, count;
  cin >> n >> count;
  string s;
  cin >> s;
  while (count--) {
    for (int i = 1; i < s.length(); i++) {
      if (s[i] == 'B' && s[i + 1] == 'G') {
        swap(s[i], s[i + 1]);
        i++;
      }
    }
  }
  cout << s << "\n";
  return 0;
}
