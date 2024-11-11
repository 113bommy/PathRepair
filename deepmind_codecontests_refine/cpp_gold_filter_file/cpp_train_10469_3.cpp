#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, a;
  string b = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
              'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  cin >> s;
  for (int i = 0; i < 200; i++) a += b;
  int ans = 0;
  int crnt = 2600;
  for (int x = 0; x < s.length(); x++) {
    char tar = s[x];
    int temp;
    for (int i = crnt; i < crnt + 26; i++) {
      if (a[i] == tar) temp = i - crnt;
    }
    for (int i = crnt; i > crnt - 26; i--) {
      if (a[i] == tar) {
        if (temp > crnt - i) {
          temp = crnt - i;
          crnt = i;
        } else
          crnt += temp;
      }
    }
    ans += temp;
  }
  cout << ans << '\n';
  return 0;
}
