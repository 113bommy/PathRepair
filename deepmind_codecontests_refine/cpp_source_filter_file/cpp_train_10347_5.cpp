#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2;
  long long int n, c11 = 0, c00 = 0, c10 = 0, c01 = 0, p1 = 0, p2 = 0;
  cin >> n >> s1 >> s2;
  n *= 2;
  for (int i = 0; i < n; i++) {
    if (s1[i] == s2[i]) {
      if (s1[i] == '1')
        c11++;
      else
        c00++;
    } else {
      if (s1[i] == '1')
        c10++;
      else
        c01++;
    }
  }
  if (c11 % 2) {
    p1 = c11 / 2 + 1;
    p2 = c11 / 2;
    if (c01 <= c10) {
      p2 += c01;
      p1 += c01 + (c10 - c01) / 2;
    } else {
      p2 += c10 + (c01 - c10) / 2 + (c01 - c10) % 2;
      p1 += c10;
    }
  } else {
    p1 = c11 / 2;
    p2 = c11 / 2;
    if (c01 <= c10) {
      p2 += c01;
      p1 += c01 + (c10 - c01) / 2 + (c10 - c01) % 2;
    } else {
      p1 += c10 + (c01 - c10) / 2;
      p2 += c10;
    }
  }
  if (p1 > p2)
    cout << "First" << endl;
  else if (p1 == p2)
    cout << "Draw" << endl;
  else
    cout << "Second" << endl;
  return 0;
}
