#include <bits/stdc++.h>
using namespace std;
inline int abs(int t) { return (t >= 0) ? t : -t; }
int main() {
  int a, b;
  cin >> a >> b;
  int fw = 0, d = 0, sw = 0;
  for (int i = 1; i <= 6; i++) {
    if (abs(i - a) < abs(i - b))
      fw++;
    else if (abs(i - a) == abs(i - b))
      d++;
    else
      sw++;
  }
  cout << fw << " " << d << " " << sw << endl;
  return 0;
}
