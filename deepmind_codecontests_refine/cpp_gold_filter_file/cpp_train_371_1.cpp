#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:667177216")
using namespace std;
const long long MOD = 1000000000 + 7;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int q;
  cin >> q;
  for (int(i) = 0; (i) < q; (i)++) {
    int ans = 0;
    int m;
    char c;
    cin >> m >> c;
    int l = 0, r = 0;
    int count = 0;
    while (r != n) {
      while (r != n && (s[r] == c || count < m)) {
        if (s[r] != c) count++;
        r++;
      }
      ans = max(ans, r - l);
      if (s[l] != c) count--;
      l++;
    }
    cout << ans << endl;
  }
  return 0;
}
