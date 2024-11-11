#include <bits/stdc++.h>
using namespace std;
long long hell = 1e9 + 7;
long long n, m;
int toint(string s) {
  int v = 0;
  for (int i = 0; i < s.length(); i++) {
    v = v * 10 + s[i] - 48;
  }
  return v;
}
int main() {
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    string useful = s.substr(4, s.length() - 4);
    int t = 0;
    int p = 10;
    for (int i = 1; i < useful.length(); i++) {
      t += p;
      p *= 10;
    }
    int y = toint(useful);
    while (y < 1989 + t) y += p;
    cout << y << endl;
  }
  return 0;
}
