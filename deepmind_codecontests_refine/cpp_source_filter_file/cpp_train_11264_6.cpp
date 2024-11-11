#include <bits/stdc++.h>
using namespace std;
long long n, k, l = 0;
string s;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  cin >> n >> k;
  cin >> s;
  if (n == 1)
    cout << "0"
         << "\n";
  else {
    if (s[l] != '1' && k > 0) {
      s.replace(0, 1, "1");
      --k;
    }
    ++l;
    while (l < n && k > 0) {
      if (s[l] != '0') {
        s.replace(l, 1, "0");
        --k;
      }
      ++l;
    }
    cout << s << "\n";
  }
  return 0;
}
