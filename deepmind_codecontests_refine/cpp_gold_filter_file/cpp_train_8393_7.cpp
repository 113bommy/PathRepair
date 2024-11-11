#include <bits/stdc++.h>
using namespace std;
const long long INF = 2e17;
int al[30];
int main() {
  int n;
  cin >> n;
  int ans = 0;
  bool k = 0;
  for (int i = 0; i < n - 1; i++) {
    char a;
    string b;
    cin >> a >> b;
    if (a == '.') {
      for (char j : b) al[j - 'a'] = -1;
    } else
      ans += k;
    if (a == '?') al[b[0] - 'a'] = -1;
    if (a == '!') {
      for (int j = 0; j < 26; j++) {
        if (b.find(char('a' + j)) == std::string::npos) {
          al[j] = -1;
        }
      }
    }
    int s = 0;
    for (int j = 0; j < 26; j++)
      if (al[j] == 0) s++;
    if (s == 1) k = true;
  }
  cout << ans;
}
