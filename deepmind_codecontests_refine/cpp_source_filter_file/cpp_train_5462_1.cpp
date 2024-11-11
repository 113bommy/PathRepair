#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a1, b1, a2, b2, p1, p2, tp1, tp2;
  cin >> a1 >> b1 >> a2 >> b2;
  p1 = a1 * b1;
  p2 = a2 * b2;
  int p31 = 0, p32 = 0, ans = 0;
  tp1 = p1;
  while (tp1 % 3 == 0) p31 += 1, tp1 /= 3;
  tp2 = p2;
  while (tp2 % 3 == 0) p32 += 1, tp2 /= 3;
  ans += abs(p31 - p32);
  if (p31 > p32)
    while (p31 != p32) {
      p31 -= 1;
      p1 /= 3;
      p1 *= 2;
      if (a1 % 3 == 0)
        a1 /= 3, a1 *= 2;
      else
        b1 /= 3, b1 *= 2;
    }
  else
    while (p31 != p32) {
      p32 -= 1;
      p2 /= 3;
      p2 *= 2;
      if (a2 % 3 == 0)
        a2 /= 3, a2 *= 2;
      else
        b2 /= 3, b2 *= 2;
    }
  tp1 = p1;
  p31 = 0;
  while (tp1 % 2 == 0) p31 += 1, tp1 /= 2;
  tp2 = p2;
  p32 = 0;
  while (tp2 % 2 == 0) p32 += 1, tp2 /= 2;
  if (tp1 != tp2) {
    cout << -1 << endl;
    return 0;
  }
  ans += abs(p31 - p32);
  if (p31 > p32)
    while (p31 != p32) {
      p31 -= 1;
      p1 /= 2;
      if (a1 % 2 == 0)
        a1 /= 2;
      else
        b1 /= 3;
    }
  else
    while (p31 != p32) {
      p32 -= 1;
      p2 /= 2;
      if (a2 % 2 == 0)
        a2 /= 2;
      else
        b2 /= 2;
    }
  cout << ans << endl << a1 << " " << b1 << endl << a2 << " " << b2 << endl;
}
