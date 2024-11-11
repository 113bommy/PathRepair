#include <bits/stdc++.h>
using namespace std;
double pi = 3.141592653589793238462;
string numkey = "0123456789";
string uni = "abcdefghijklmnopqrstuvwxyz";
bool mask(int a, string b) {
  string s = "";
  while (a > 0) {
    int d = a % 10;
    if (d == 7 || d == 4) {
      char ch = d + '0';
      s += ch;
    }
    a /= 10;
  }
  reverse(s.begin(), s.end());
  if (s == b) return true;
  return false;
}
int main() {
  int a;
  cin >> a;
  string b;
  cin >> b;
  a++;
  while (mask(a, b) != true) {
    a++;
  }
  cout << a;
}
