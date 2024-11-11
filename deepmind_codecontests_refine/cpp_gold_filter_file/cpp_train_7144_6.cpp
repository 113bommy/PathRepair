#include <bits/stdc++.h>
using namespace std;
int main() {
  int grundy[100050], moves[100050], val;
  set<int> s;
  cin >> val;
  grundy[0] = 0;
  grundy[1] = 0;
  grundy[2] = 0;
  for (int i = 3; i <= val; ++i) {
    int m = 999999999;
    s.clear();
    for (int k = 1; (k + 1) * k / 2 < i; k += 1) {
      if ((i - (k + 1) * k / 2) % (k + 1) == 0) {
        int a = (i - (k + 1) * k / 2) / (k + 1);
        s.insert(grundy[a + k] ^ grundy[a - 1]);
        if ((grundy[a + k] ^ grundy[a - 1]) == 0) m = min(m, k + 1);
      }
    }
    int g = 0;
    while (s.count(g)) g++;
    grundy[i] = grundy[i - 1] ^ g;
    moves[i] = m;
  }
  if ((grundy[val] ^ grundy[val - 1]) > 0)
    cout << moves[val] << "\n";
  else
    cout << -1 << "\n";
  return 0;
}
