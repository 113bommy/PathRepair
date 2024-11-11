#include <bits/stdc++.h>
using namespace std;
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    string s;
    cin >> a >> b >> s;
    s += "X";
    int t1 = 0, t2 = 0, t3 = 0, l = 0, m = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '.')
        l++;
      else if (l != 0) {
        if (l >= b and l < a) t1++;
        if (l >= a and l < 2 * b) t2++;
        if (l >= 2 * b) t3++;
        m = max(m, l);
        l = 0;
      }
    }
    if (m < a or t1 != 0 or t3 > 1) {
      cout << "No" << '\n';
      continue;
    }
    if (t3 == 0) {
      if (t2 % 2)
        cout << "Yes" << '\n';
      else
        cout << "No" << '\n';
      continue;
    }
    if (t3 == 1) {
      if (m >= 4 * b + a - 1) {
        cout << "No" << '\n';
        continue;
      }
      if (t2 % 2) {
        if (m >= 2 * a and m <= a + 3 * b - 2)
          cout << "Yes" << '\n';
        else
          cout << "No" << '\n';
        continue;
      } else {
        if (m >= 3 * a or m <= 2 * b - 2 + a)
          cout << "Yes" << '\n';
        else
          cout << "No" << '\n';
        continue;
      }
    }
  }
  return 0;
}
