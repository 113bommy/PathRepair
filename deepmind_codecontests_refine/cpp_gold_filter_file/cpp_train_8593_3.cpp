#include <bits/stdc++.h>
using namespace std;
map<string, int> h;
string tr(long long x) {
  string rez = "";
  int ind = 0;
  while (true) {
    ++ind;
    rez += (char)('0' + (x % 2));
    x = x / 10;
    if (ind >= 18) break;
  }
  return rez;
}
long long T, x;
string s, a;
int main() {
  cin >> T;
  while (T--) {
    cin >> s;
    if (s == "+") {
      cin >> x;
      h[tr(x)]++;
    }
    if (s == "-") {
      cin >> x;
      h[tr(x)]--;
    }
    if (s == "?") {
      cin >> a;
      reverse(a.begin(), a.end());
      while (a.size() < 18) {
        a += "0";
      }
      cout << h[a] << "\n";
    }
  }
}
