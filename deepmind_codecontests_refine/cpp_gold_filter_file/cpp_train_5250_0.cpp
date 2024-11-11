#include <bits/stdc++.h>
using namespace std;
const long long md = 1e9 + 7;
const int xn = 1e5 + 10;
const int xm = 3e5 + 10;
const int SQ = 1000;
const long long inf = 1e9 + 10;
string a, abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int n, ans;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> a;
  n = a.size();
  for (int i = 0; i < 26; i++) {
    int last = -1, t = 1;
    for (int j = 0; j < n; j++) {
      if (a[j] != abc[i]) continue;
      if (last == -1)
        last = j;
      else if ((j - last) % 2)
        t++, last = j;
    }
    ans = max(ans, t);
  }
  cout << ans << '\n';
  return 0;
}
