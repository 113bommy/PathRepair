#include <bits/stdc++.h>
using namespace std;
int N, K;
string s;
int howmany(int m) {
  int cur = 0, ans = 0, used = 2;
  while (cur + m < N - 1) {
    int newp;
    for (newp = cur + m; newp > cur; newp--) {
      if (s[newp] == '0') break;
    }
    if (newp == cur) return -1;
    ans = max(ans, newp - cur - 1);
    used++;
    cur = newp;
  }
  ans = max(ans, N - 2 - cur);
  if (used > K) return -1;
  return ans;
}
int main() {
  cin >> N >> K >> s;
  howmany(1);
  int l = 1, r = 200000;
  while (l < r - 1) {
    int m = (l + r) / 2;
    if (howmany(m) >= 0)
      r = m;
    else
      l = m;
  }
  if (howmany(l) >= 0)
    cout << howmany(l);
  else
    cout << howmany(r);
  return 0;
}
