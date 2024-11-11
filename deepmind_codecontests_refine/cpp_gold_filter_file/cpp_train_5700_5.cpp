#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> a(6, 0);
bool gr(int p, int q) { return p > q; }
int main() {
  cin >> s;
  for (int i = 0; i < 6; i++) {
    if (s[i] == 'R') a[0]++;
    if (s[i] == 'O') a[1]++;
    if (s[i] == 'Y') a[2]++;
    if (s[i] == 'G') a[3]++;
    if (s[i] == 'B') a[4]++;
    if (s[i] == 'V') a[5]++;
  }
  sort(a.begin(), a.end(), gr);
  if (a[0] == 6)
    cout << 1;
  else if (a[0] == 5)
    cout << 1;
  else if (a[0] == 4) {
    if (a[1] == 2)
      cout << 2;
    else
      cout << 2;
  } else if (a[0] == 3) {
    if (a[1] == 3)
      cout << 2;
    else if (a[1] == 2)
      cout << 3;
    else
      cout << 5;
  } else if (a[0] == 2) {
    if (a[1] == 2) {
      if (a[2] == 1)
        cout << 8;
      else
        cout << 6;
    } else
      cout << 15;
  } else
    cout << 30;
  return 0;
}
