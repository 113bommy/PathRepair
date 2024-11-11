#include <bits/stdc++.h>
using namespace std;
bool check(long long x, long long y, long long x1, long long y1) {
  if (x > 0 && y > 0 && x1 % x == 0 && y1 % y == 0 && x1 / x >= 0 &&
      y1 / y >= 0 && x1 / x == y1 / y)
    return 1;
  if (x == 0 && y == 0 && y1 == 0 && x1 == 0) return 1;
  if (x == 0 && y > 0 && x1 == 0 && y1 % y == 0 && y1 / y >= 0) return 1;
  if (x > 0 && y == 0 && y1 == 0 && x1 % x == 0 && x1 / x >= 0) return 1;
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long a, b;
  cin >> a >> b;
  string s;
  cin >> s;
  long long a1 = 0, b1 = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'U')
      b1++;
    else if (s[i] == 'D')
      b1--;
    else if (s[i] == 'R')
      a1++;
    else
      a1--;
  }
  for (int i = 0; i < s.size(); i++) {
    long long a2 = a, b2 = b;
    for (int j = i; j >= 0; j--) {
      if (s[j] == 'U')
        b2--;
      else if (s[j] == 'D')
        b2++;
      else if (s[j] == 'R')
        a2--;
      else
        a2++;
    }
    if (check(a1, b1, a2, b2)) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  if (a == 0 && b == 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
