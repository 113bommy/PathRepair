#include <bits/stdc++.h>
using namespace std;
const int N = 200000;
int qu[N];
int main() {
  int n;
  cin >> n;
  int ans = 0;
  int a = 0, b = 0;
  int cnt = 0;
  while (n--) {
    int t;
    cin >> t;
    if (t == 1) {
      int s;
      cin >> s;
      a = s;
      while (cnt > 0 && s > qu[cnt - 1]) {
        ans++;
        cnt--;
      }
    } else if (t == 2)
      ans += b--;
    else if (t == 3) {
      int s;
      cin >> s;
      if (a > s)
        ans++;
      else
        qu[cnt++] = s;
    } else if (t == 4)
      b = 0;
    else if (t == 5)
      cnt = 0;
    else
      b++;
  }
  cout << ans << '\n';
  return 0;
}
