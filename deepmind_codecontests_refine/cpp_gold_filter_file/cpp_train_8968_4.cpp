#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  cin >> s;
  string p = "";
  int no = 0, nw = 0;
  for (int i = 0; i < int(s.size()) - 1; i++) {
    if (s[i] == 'v' && s[i + 1] == 'v') {
      p += "w";
      nw++;
    } else if (s[i] == 'o') {
      p += "o";
      no++;
    }
  }
  int n = p.size(), flag = 0;
  long long ans = 0, q = 0;
  for (int i = 0; i < n; i++) {
    if (p[i] == 'w') {
      q++;
      nw--;
    } else {
      ans += nw * q;
    }
  }
  cout << ans << "\n";
}
