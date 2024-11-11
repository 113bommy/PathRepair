#include <bits/stdc++.h>
using namespace std;
const double oo = 1e14;
const double eps = 1e-10;
const double PI = acos(-1.0);
int n, k;
string s;
int main() {
  cin >> n >> k >> s;
  int m = s.length(), c = 0;
  for (int i = 0; i < (int)(m); i++) {
    if (c == m) break;
    if (s[i] == '4') {
      if (i != m - 1 && s[i + 1] == '7') {
        if (i != 0 && s[i - 1] == '4') {
          if (i % 2)
            s[i] = ((m - c) % 2 ? '7' : '4'), c = m;
          else
            s[i + 1] = '4', c++;
        } else {
          if (i % 2)
            s[i] = '7', c++;
          else
            s[i + 1] = '4', c++;
        }
      }
    }
  }
  cout << s;
}
