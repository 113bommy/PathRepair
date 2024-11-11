#include <bits/stdc++.h>
using namespace std;
void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
void solve(string s) {
  long long int n = s.length();
  long long int res = 0;
  bool exist = true;
  bool xDone = false;
  if (n > 1 && s[0] == '0')
    res = 0;
  else if (n == 1) {
    if (s[0] == '0' || s[0] == 'X' || s[0] == '_')
      res = 1;
    else
      res = 0;
  } else if (n == 2) {
    if (s == "__" || s == "_X" || s == "X_")
      res = 3;
    else if (s == "XX")
      res = 0;
    else if (s[0] == 'X' || s[0] == '_') {
      if (s[1] == '0')
        res = 1;
      else if (s[1] == '5')
        res = 2;
    } else if (s[1] == 'X' || s[1] == '_') {
      if (s[0] == '5')
        res = 1;
      else if (s[0] == '2' || s[0] == '7')
        res = 1;
    } else if ((stoi(s)) % 25 == 0)
      res = 1;
  } else if (s[n - 1] == 'X' && s[n - 2] == 'X') {
    if (s[0] == 'X') exist = false;
    xDone = true;
    if (s[0] == '_')
      res += 9;
    else
      res += 1;
  } else if (s[n - 1] == '_' && s[n - 2] == '_') {
    res = 4;
    if (s[0] == '_')
      res *= 9;
    else if (s[0] == 'X') {
      res *= 9;
      xDone = true;
    }
  } else if (s[n - 2] == '_' && s[n - 1] == 'X') {
    if (s[0] != 'X')
      res += 4;
    else
      res += 3;
    xDone = true;
    if (s[0] == '_') res *= 9;
  } else if (s[n - 2] == 'X' && s[n - 1] == '_') {
    if (s[0] == 'X')
      res += 3;
    else
      res += 4;
    xDone = true;
    if (s[0] == '_') res *= 9;
  } else if (s[n - 1] == 'X') {
    if (s[n - 2] == '2' || s[n - 2] == '7') {
      res = 1;
    } else if ((s[n - 2] == '0' || s[n - 2] == '5') && s[0] != 'X') {
      res = 1;
    } else
      exist = false;
    xDone = true;
    if (s[0] == '_') res *= 9;
  } else if (s[n - 2] == 'X') {
    if (s[n - 1] == '0') {
      if (s[0] == 'X')
        res = 1;
      else
        res = 2;
    } else if (s[n - 1] == '5')
      res = 2;
    else
      exist = false;
    xDone = true;
    if (s[0] == '_') res *= 9;
  } else if (s[n - 1] == '_') {
    if (s[n - 2] == '2' || s[n - 2] == '7') {
      res = 1;
    } else if ((s[n - 2] == '0' || s[n - 2] == '5')) {
      res = 1;
    } else
      exist = false;
    if (s[0] == '_')
      res *= 9;
    else if (s[0] == 'X') {
      res *= 9;
      xDone = true;
    }
  } else if (s[n - 2] == '_') {
    if (s[n - 1] == '0' || s[n - 1] == '5') {
      res = 2;
    } else
      exist = false;
    if (s[0] == '_')
      res *= 9;
    else if (s[0] == 'X') {
      res *= 9;
      xDone = true;
    }
  } else {
    if (n > 1 && s[n - 1] == '0' && (s[n - 2] == '0' || s[n - 2] == '5'))
      res = 1;
    else if (n > 1 && s[n - 1] == '5' && (s[n - 2] == '2' || s[n - 2] == '7'))
      res = 1;
    else
      exist = false;
    if (s[0] == '_')
      res *= 9;
    else if (s[0] == 'X') {
      res *= 9;
      xDone = true;
    }
  }
  if (!exist)
    res = -1;
  else {
    for (long long int i = 1; i < n - 2; i++) {
      if (s[i] == '_')
        res *= 10;
      else if (s[i] == 'X' && xDone == false) {
        res *= 10;
        xDone = true;
      }
    }
  }
  cout << res;
}
int main() {
  fastio();
  long long int t = 1;
  while (t--) {
    string s;
    cin >> s;
    solve(s);
    cout << "\n";
  }
  return 0;
}
