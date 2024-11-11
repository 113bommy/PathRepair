#include <bits/stdc++.h>
using namespace std;
long long mul(long long int a, long long int b) {
  long long res;
  res = (a + 1) * (b * (b + 1) + (1 + b) * (2 * a + b)) / 4;
  return res;
}
int main() {
  int m, b;
  long long mox;
  while (cin >> m >> b) {
    mox = 0;
    for (long long int i = 0; i <= b; i++)
      mox = max(mox, mul(i, m * b - m * i));
    cout << mox << endl;
  }
}
