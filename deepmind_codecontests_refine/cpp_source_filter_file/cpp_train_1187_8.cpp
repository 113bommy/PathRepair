#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  int n, one = 0, two = 0, three = 0, four = 0, ans = 0, rem, part, ex, st, ch;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> st;
    if (st == 1)
      one++;
    else if (st == 2)
      two++;
    else if (st == 3)
      three++;
    else if (st == 4)
      four++;
  }
  ch = min(two, one);
  ans += ch;
  one -= ch;
  two -= ch;
  three += ch;
  if (one > 0) {
    rem = one;
    part = rem / 3;
    ans += (2 * part);
    three += part;
    one -= (3 * part);
  }
  if (one == 2) {
    if (three >= 2) {
      ans += 2;
      one -= 2;
      four += 2;
      three -= 2;
    } else if (four > 0) {
      ans += 2;
      four--;
      three++;
      one -= 2;
    }
  } else if (one == 1) {
    if (three >= 1) {
      ans++;
      three--;
      four++;
      one--;
    } else if (four >= 2) {
      ans += 2;
      one--;
      three += 2;
      four -= 2;
    }
  }
  if (two > 0) {
    rem = two;
    part = rem / 3;
    ans += (2 * part);
    two -= (3 * part);
    three += (2 * rem);
  }
  if (two == 2) {
    ans += 2;
    two -= 2;
    four++;
  } else if (two == 1) {
    if (four > 0) {
      ans++;
      two--;
      four--;
      three++;
    } else if (three >= 2) {
      ans += 2;
      two -= 2;
      four += 2;
      three -= 2;
    }
  }
  if (one > 0 || two > 0)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}
