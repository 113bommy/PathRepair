#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, l;
  cin >> a >> b >> c >> l;
  long long answ = 0;
  for (int i = 0; i <= l; i++) {
    long long check = (a + b + c + i - 1) / 2;
    if (a <= check && b <= check && c <= check) {
      answ += (i + 1) * (i + 2) / 2;
      if (a + i > check) {
        answ -= (a + i - check + 1) * (a + i - check) / 2;
      }
      if (b + i > check) {
        answ -= (b + i - check + 1) * (b + i - check) / 2;
      }
      if (c + i > check) {
        answ -= (c + i - check + 1) * (c + i - check) / 2;
      }
    }
  }
  cout << answ;
  return 0;
}
