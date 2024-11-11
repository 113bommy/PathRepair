#include <bits/stdc++.h>
using namespace std;
int gcd(int u, int v) { return (v != 0) ? gcd(v, u % v) : u; }
int win(int hp1, int atk1, int def1, int hp2, int atk2, int def2) {
  double f = max(0, atk1 - def2);
  double s = max(0, atk2 - def1);
  double s2 = ceil(hp2 / f);
  double s1 = ceil(hp1 / s);
  if (s1 > s2) return 0;
  if (f == 0) return 1e9;
  double NewHp = s2 * s;
  return NewHp + 1 - hp1;
}
int main() {
  int hp1, atk1, def1, hp2, atk2, def2;
  long long a, b, c;
  cin >> hp1 >> atk1 >> def1 >> hp2 >> atk2 >> def2;
  cin >> a >> b >> c;
  long long Min = 1e18;
  for (int i = 0; i <= 110; i++) {
    for (int j = 0; j <= 110; j++) {
      int k = win(hp1, atk1 + i, def1 + j, hp2, atk2, def2);
      Min = min(Min, k * a + i * b + j * c);
    }
  }
  cout << Min << endl;
}
