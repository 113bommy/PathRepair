#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  getline(cin, s);
  int n = s.size();
  int a = 0, b = 0, c = 0;
  for (int i = 0; i < n; i++)
    if (s[i] == '1')
      a++;
    else if (s[i] == '0')
      b++;
    else
      c++;
  bool zz, zo, oz, oo;
  zz = zo = oz = oo = false;
  if (a < b + c) zz = true;
  if (c + a > b + 1) oo = true;
  if (s[n - 1] != '0') {
    if (s[n - 1] == '?') {
      c--;
      a++;
    }
    int x = b - a + c + (a + b + c) % 2;
    if (x >= 0 && x <= 2 * c) zo = true;
    if (s[n - 1] == '?') {
      c++;
      a--;
    }
  }
  if (s[n - 1] != '1') {
    if (s[n - 1] == '?') {
      c--;
      b++;
    }
    int x = b + c - a + (n % 2);
    if (x >= 0 && x <= 2 * c) oz = true;
    if (s[n - 1] == '?') {
      c++;
      b--;
    }
  }
  if (zz) cout << "00\n";
  if (zo) cout << "01\n";
  if (oz) cout << "10\n";
  if (oo) cout << "11\n";
  return 0;
}
