#include <bits/stdc++.h>
using namespace std;
long long n, posl = -1, posr, ans;
string s;
int main() {
  cin >> n;
  cin >> s;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == 'L') {
      for (int j = i; j >= 0; --j) {
        s[j] = 'x';
      }
    }
    if (s[i] == 'R') {
      for (int j = i; j < s.size(); ++j) {
        if (s[j] == 'L') {
          posl = j;
          break;
        }
      }
      if (posl == -1)
        for (int j = i; j < s.size(); ++j) s[j] = 'x';
      else
        for (int j = i; j <= posl; ++j) s[j] = 'x';
      if (posl != -1 and (posl - i - 1) % 2) ++ans;
      posl = -1;
    }
  }
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '.') ++ans;
  }
  cout << ans << "\n";
}
