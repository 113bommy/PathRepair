#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7, N = 4e5 + 10;
void solve() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a - b == 1) {
    if (c == 0 && d == 0) {
      cout << "YES\n";
      cout << "0\n";
      for (long long i = 0; i < b; i++) {
        cout << "10";
      }
      cout << "\n";
    } else {
      cout << "No\n";
    }
    return;
  }
  if (d - c == 1) {
    if (a == 0 && b == 0) {
      cout << "YES\n";
      cout << "3";
      for (long long i = 0; i < c; i++) {
        cout << "23";
      }
      cout << "\n";
    } else {
      cout << "NO\n";
    }
    return;
  }
  if (b < a || c < d) {
    cout << "NO\n";
    return;
  }
  string s1 = "", s2 = "";
  for (long long i = 0; i < a; i++) {
    s1 += '0';
    s1 += ' ';
    s1 += '1';
    s1 += ' ';
  }
  b = b - a;
  a = 0;
  for (long long i = 0; i < d; i++) {
    s2 += '2';
    s2 += ' ';
    s2 += '3';
    s2 += ' ';
  }
  c = c - d;
  d = 0;
  if (b == c) {
    for (long long i = 0; i < b; i++) {
      s1 += '2';
      s1 += ' ';
      s1 += '1';
      s1 += ' ';
    }
    cout << "YES\n";
    cout << s1 << s2 << "\n";
  } else if (b - c == 1) {
    for (long long i = 0; i < b; i++) {
      s1 += '2';
      s1 += ' ';
      s1 += '1';
      s1 += ' ';
    }
    cout << "YES\n";
    cout << "1 " << s1 << s2 << "\n";
  } else if (c - b == 1) {
    for (long long i = 0; i < b; i++) {
      s1 += '2';
      s1 += ' ';
      s1 += '1';
      s1 += ' ';
    }
    cout << "YES\n";
    cout << s1 << s2 << "2 "
         << "\n";
  } else {
    cout << "NO\n";
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long test = 1;
  while (test--) {
    solve();
  }
}
