#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e12;
const int MAXN = 1e5 + 1, MODM = 1e9 + 7, P = 1e6 + 3, MULT1 = 30, MULT2 = 239,
          LUCKY = 13, ELEVEN = 11, MAXM = 101, k = 200;
int main() {
  ios_base::sync_with_stdio(0);
  vector<char> a(4), b(4);
  string s;
  cin >> s;
  a[0] = s[0], a[1] = s[1];
  cin >> s;
  a[3] = s[0], a[2] = s[1];
  cin >> s;
  b[0] = s[0], b[1] = s[1];
  cin >> s;
  b[3] = s[0], b[2] = s[1];
  bool fl = 0;
  for (int i = 0; i < 4; i++)
    if (a[i] == 'X') {
      a.erase(a.begin() + i);
      break;
    }
  for (int i = 0; i < 4; i++)
    if (b[i] == 'X') {
      b.erase(b.begin() + i);
      break;
    }
  for (int i = 0; i < 4; i++) {
    for (int l = 0; l < 100; l++) {
      char p = b[0];
      for (int i = 0; i < 2; i++) b[i] = b[i + 1];
      b[2] = p;
      fl |= (a == b);
    }
  }
  for (int i = 0; i < 4; i++) {
    if (b[i] == 'X') {
      swap(b[i], b[(i + 3) % 4]);
      break;
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int l = 0; l < 100; l++) {
      char p = b[0];
      for (int i = 0; i < 3; i++) b[i] = b[i + 1];
      b[3] = p;
      fl |= (a == b);
    }
  }
  if (fl)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
