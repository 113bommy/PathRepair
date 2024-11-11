#include <bits/stdc++.h>
using namespace std;
long long ask(long long a, long long b) {
  cout << "? " << a << ' ' << b << endl;
  long long ans;
  cin >> ans;
  return ans;
}
void solve() {
  string s;
  cin >> s;
  long long cur = 0, d = 0, k = 0, ans = 0, n = s.size() + 1;
  bool drob = false, isNum = false, dot = false;
  s += 'd';
  for (int i = 0; i < n; i++) {
    if (s[i] >= '0' && s[i] <= '9') {
      k++;
      isNum = true;
      cur *= 10;
      cur += (s[i] - '0');
    } else if (s[i] == '.') {
      k = 0;
      dot = true;
      continue;
    } else {
      if (!isNum) {
        continue;
      }
      if (k == 2 && dot || drob == true) {
        ans += cur;
      } else {
        ans += cur * 100;
      }
      isNum = false;
      drob = false;
      cur = 0;
      k = 0;
      dot = false;
    }
  }
  string res = "";
  if (ans % 100 == 0) {
    ans /= 100;
    int i = 0;
    while (ans > 0) {
      char c = ('0' + (ans % 10));
      ans /= 10;
      res = c + res;
      if ((i + 1) % 3 == 0 && ans > 0) {
        res = '.' + res;
      }
      i++;
    }
    cout << res;
  } else if (ans >= 100) {
    char c = ('0' + (ans % 10));
    ans /= 10;
    res = c;
    c = ('0' + (ans % 10));
    ans /= 10;
    res = c + res;
    res = '.' + res;
    int i = 0;
    while (ans > 0) {
      char c = ('0' + (ans % 10));
      ans /= 10;
      res = c + res;
      if ((i + 1) % 3 == 0 && ans > 0) {
        res = '.' + res;
      }
      i++;
    }
    cout << res;
  } else {
    cout << "0.";
    char c = ('0' + (ans % 10));
    ans /= 10;
    res = c;
    c = ('0' + (ans % 10));
    ans /= 10;
    res = c + res;
    cout << res;
  }
  return;
}
int main() {
  solve();
  return 0;
}
