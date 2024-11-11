#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string s;
  char ch;
  int a, b, c, d;
  int a1[n];
  int b1[n];
  int c1[n];
  int d1[n];
  string l[n];
  for (int i = 0; i < n; i++) {
    cin >> s >> a >> ch >> b >> ch >> c >> ch >> d;
    a1[i] = a;
    b1[i] = b;
    c1[i] = c;
    d1[i] = d;
    l[i] = s;
  }
  string p[m];
  int a2[m];
  int b2[m];
  int c2[m];
  int d2[m];
  a = 0;
  b = 0;
  c = 0;
  d = 0;
  for (int i = 0; i < m; i++) {
    cin >> s >> a >> ch >> b >> ch >> c >> ch >> d >> ch;
    a2[i] = a;
    b2[i] = b;
    c2[i] = c;
    d2[i] = d;
    p[i] = s;
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (a2[i] == a1[j] && b2[i] == b1[j] && c2[i] == c1[j] &&
          d2[i] == d1[j]) {
        cout << p[i] << ' ' << a1[j] << '.' << b1[j] << '.' << c1[j] << '.'
             << d1[j] << ';' << ' ' << '#' << l[j] << endl;
      }
    }
  }
}
