#include <bits/stdc++.h>
using namespace std;
const int N = 5555;
char s[N];
int main() {
  ios::sync_with_stdio(0);
  while (cin >> s) {
    int l = strlen(s), ans = 0, last = -1;
    for (int i = 3; i < l; i++) {
      if (s[i - 3] == 'b' && s[i - 2] == 'e' && s[i - 1] == 'a' && s[i] == 'r')
        last = i - 2;
      ans += last;
    }
    cout << ans << endl;
  }
  return 0;
}
