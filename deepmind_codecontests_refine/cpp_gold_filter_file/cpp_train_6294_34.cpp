#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int a = 0, b = 0, c = 0;
  for (int i = 0; i < 3; i++) {
    char q, s, w;
    cin >> q >> s >> w;
    if (s == '>') {
      if (w == 'A')
        a++;
      else if (w == 'B')
        b++;
      else
        c++;
    } else {
      if (q == 'A')
        a++;
      else if (q == 'B')
        b++;
      else
        c++;
    }
  }
  if (a > b && a > c) {
    cout << "A";
    if (b > c)
      cout << "BC";
    else
      cout << "CB";
  } else if (b > a && b > c) {
    cout << "B";
    if (a > c)
      cout << "AC";
    else
      cout << "CA";
  } else if (c > a && c > b) {
    cout << "C";
    if (a > b)
      cout << "AB";
    else
      cout << "BA";
  } else
    cout << "Impossible";
  return 0;
}
