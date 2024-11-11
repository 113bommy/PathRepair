#include <bits/stdc++.h>
using namespace std;
void yes() { cout << "YES" << '\n'; }
void no() { cout << "NO" << '\n'; }
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void main_() {
  string s;
  cin >> s;
  int n;
  n = s.size();
  int a, b, c;
  a = b = c = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] <= 'z' && s[i] >= 'a')
      a++;
    else if (s[i] <= 'Z' && s[i] >= 'A')
      b++;
    else
      c++;
  }
  if (a > 0 && b > 0 && c > 0) {
    cout << s << '\n';
    return;
  }
  if (a * b || b * c || c * a) {
    if (a * b) {
      if (a > 1) {
        for (int i = 0; i < n; i++) {
          if (s[i] <= 'z' && s[i] >= 'a') {
            s[i] = '1';
            cout << s << '\n';
            return;
          }
        }
      } else {
        for (int i = 0; i < n; i++) {
          if (s[i] <= 'Z' && s[i] >= 'A') {
            s[i] = '1';
            cout << s << '\n';
            return;
          }
        }
      }
    } else if (b * c) {
      if (b > 1) {
        for (int i = 0; i < n; i++) {
          if (s[i] <= 'Z' && s[i] >= 'A') {
            s[i] = 'a';
            cout << s << '\n';
            return;
          }
        }
      } else {
        for (int i = 0; i < n; i++) {
          if (s[i] <= '9' && s[i] >= '0') {
            s[i] = 'a';
            cout << s << '\n';
            return;
          }
        }
      }
    } else {
      if (a > 1) {
        for (int i = 0; i < n; i++) {
          if (s[i] <= 'z' && s[i] >= 'a') {
            s[i] = 'A';
            cout << s << '\n';
            return;
          }
        }
      } else {
        for (int i = 0; i < n; i++) {
          if (s[i] <= '9' && s[i] >= '0') {
            s[i] = 'A';
            cout << s << '\n';
            return;
          }
        }
      }
    }
  } else {
    if (a) {
      s[0] = 'A';
      s[1] = '1';
      cout << s << '\n';
      return;
    }
    if (b) {
      s[0] = 'a';
      s[1] = '1';
      cout << s << '\n';
      return;
    } else {
      s[0] = 'a';
      s[1] = 'B';
      cout << s << '\n';
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int test = 1;
  cin >> test;
  while (test--) {
    main_();
  }
  return 0;
}
