#include <bits/stdc++.h>
using namespace std;
int n, ans, ans2, z, x;
string s;
int main() {
  ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
  cin >> n >> s;
  if (n % 2) {
    cout << ":(\n";
    return 0;
  } else {
    for (int i = 1; i < n - 1; i++) {
      if (s[i] == '(')
        ans++;
      else if (s[i] == ')')
        ans--;
      if (ans < 0) {
        for (int j = i; j >= 1; j--) {
          if (s[j] == '?') {
            s[j] = '(';
            ans++;
          }
          if (!ans) break;
        }
        if (ans < 0) {
          cout << ":(";
          return 0;
        }
      }
    }
    if (ans > 0) {
      for (int i = n - 2; i >= 1; i--) {
        if (s[i] == '?') s[i] = ')', ans--;
        if (!ans) break;
      }
    }
    for (int i = 1; i < n - 1; i++) {
      if (z % 2 == 0 && s[i] == '?') {
        s[i] = '(';
        z++;
      } else if (z % 2 == 1 && s[i] == '?') {
        s[i] = ')';
        z++;
      }
    }
  }
  if (s[0] == ')' || s[n - 1] == '(') {
    cout << ":(\n";
    return 0;
  }
  s[0] = '(';
  s[n - 1] = ')';
  for (int i = 1; i < n - 1; i++) {
    if (s[i] == '(') {
      x++;
    } else {
      x--;
    }
    if (x < 0) {
      cout << ":(\n";
      return 0;
    }
  }
  if (x != 0) {
    cout << ":(\n";
    return 0;
  } else {
    cout << s << endl;
  }
}
