#include <bits/stdc++.h>
using namespace std;
bitset<50> xoo, soo;
long long zero, jeden, x, s, ans;
bool jest = 0, byl;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> s >> x;
  xoo = x;
  soo = s;
  zero = 1;
  jeden = 0;
  for (int a = 0; a < 43; a++) {
    if (xoo[a] == 0 && soo[a] == 0) {
      jest = 1;
      jeden = zero;
    }
    if (xoo[a] == 1 && soo[a] == 1) {
      zero *= 2;
      jeden = 0;
    }
    if (xoo[a] == 1 && soo[a] == 0) {
      jest = 1;
      jeden *= 2;
      zero = 0;
    }
    if (xoo[a] == 0 && soo[a] == 1) {
      jest = 1;
      zero = jeden;
    }
    if (soo[a] || xoo[a]) ans = zero, byl = jest;
  }
  if (!byl) ans /= 2;
  cout << ans;
  return 0;
}
