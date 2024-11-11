#include <bits/stdc++.h>
using namespace std;
bool used[1100000];
int main() {
  long long n, d, l, m;
  cin >> n >> d >> m >> l;
  long long last = (n - 1) * m + l;
  long long coord = 0;
  used[0] = true;
  for (;;) {
    coord += d;
    int coordm = coord % m;
    if (used[coordm] || coord > last) break;
    used[coordm] = true;
    if (coordm > l) {
      cout << coord << endl;
      return 0;
    }
  }
  long long fall = last - (last % d) + d;
  for (; fall <= last; fall += d)
    ;
  for (; fall - d > last; fall -= d)
    ;
  cout << fall << endl;
  return 0;
}
