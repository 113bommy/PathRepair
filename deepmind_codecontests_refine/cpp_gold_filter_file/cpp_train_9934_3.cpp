#include <bits/stdc++.h>
using namespace std;
int main() {
  char v;
  int a, b, a1, b1, t, t1, s;
  cin >> a >> v >> b;
  cin >> a1 >> v >> b1;
  t = a * 60 + b;
  t1 = a1 * 60 + b1;
  s = t - t1;
  if (s < 0) s += 24 * 60;
  cout << setfill('0');
  cout << setw(2) << s / 60 << ":" << setw(2) << s % 60 << endl;
  return 0;
}
