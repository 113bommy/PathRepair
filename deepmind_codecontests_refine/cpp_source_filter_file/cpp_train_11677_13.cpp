#include <bits/stdc++.h>
using namespace std;
long long min(long long a, long long b) { return (a < b) ? a : b; }
int main() {
  long long n, m;
  cin >> n >> m;
  long long xj = 1;
  long long yj = m - 1;
  long long rem = n * m;
  while (rem > 0) {
    long long k = m - 1;
    long long l = n - 1;
    long long curx = xj++;
    long long cury = 1;
    bool flag = true;
    cout << curx << " "
         << "1" << endl;
    for (long long i = 1; i < min(2 * m, rem); i++) {
      if (flag) {
        curx = curx + l;
        cury = cury + k;
        k--;
        printf("%d %d\n", curx, cury);
        flag = false;
      } else {
        curx = curx - l;
        cury = cury - k;
        k--;
        printf("%d %d\n", curx, cury);
        flag = true;
      }
    }
    n = n - 2;
    rem = rem - min(2 * m, rem);
  }
  return 0;
}
