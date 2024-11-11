#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  long long n, i, r = 0, b = 0, g = 0;
  cin >> n >> s;
  for (i = 0; i < n; i++) {
    if (s[i] == 'B') b++;
    if (s[i] == 'G') g++;
    if (s[i] == 'R') r++;
  }
  if (b > 0 && g > 0 && r > 0) {
    cout << "BGR";
    return 0;
  }
  if (b > 0 && g == 0 && r == 0) {
    cout << "B";
    return 0;
  }
  if (b == 0 && g > 0 && r == 0) {
    cout << "G";
    return 0;
  }
  if (b == 0 && g == 0 && r > 0) {
    cout << "R";
    return 0;
  }
  if ((b >= 2 && g >= 2) || (b >= 2 && r >= 2) || (r >= 2 && g >= 2)) {
    cout << "BGR";
    return 0;
  }
  if ((b < 2 && g >= 2) || (r < 2 && g >= 2)) {
    cout << "BR";
    return 0;
  }
  if ((b < 2 && r >= 2) || (g < 2 && r >= 2)) {
    cout << "BG";
    return 0;
  }
  if ((g < 2 && b >= 2) || (r < 2 && b >= 2)) {
    cout << "GR";
    return 0;
  }
  if (b == 1 && r == 1) {
    cout << "G";
    return 0;
  }
  if (b == 1 && g == 1) {
    cout << "R";
    return 0;
  }
  if (g == 1 && r == 1) {
    cout << "B";
    return 0;
  }
  return 0;
}
