#include <bits/stdc++.h>
using namespace std;
int MAX(int a, int b) { return a < b ? b : a; }
int MIN(int a, int b) { return a > b ? b : a; }
int gcd(int a, int b) { return a ? gcd(b % a, a) : b; }
bool is_letter_s(char a) {
  if ((a >= 'a') && (a <= 'z'))
    return true;
  else
    return false;
}
bool is_letter_b(char a) {
  if ((a >= 'A') && (a <= 'Z'))
    return true;
  else
    return false;
}
bool is_number(char a) {
  if ((a >= '0') && (a <= '9'))
    return true;
  else
    return false;
}
int main() {
  int n, s;
  int max = -1;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if ((x <= s) && (y == 0) && (max == -1)) max = 0;
    if ((x < s) && (y != 0)) max = MAX(max, 100 - y);
  }
  cout << max;
  return 0;
}
