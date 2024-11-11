#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int Hy, Ay, Dy, Hm, Am, Dm, first, second, z, ans = 1e9;
  cin >> Hy >> Ay >> Dy >> Hm >> Am >> Dm >> first >> second >> z;
  for (int a = 0; a <= 1000; a++) {
    for (int b = 0; b <= 200; b++) {
      for (int c = 0; c <= 200; c++) {
        int tmp = Ay + c - Dm;
        if (tmp <= 0) continue;
        int k = (Hm + tmp - 1) / tmp;
        if ((Hy + a) - k * (Am - (Dy + b)) > 0 &&
            Hm - k * ((Ay + c) - Dm) <= 0) {
          ans = min(ans, a * first + b * z + c * second);
        }
      }
    }
  }
  cout << ans << endl;
}
