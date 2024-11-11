#include <bits/stdc++.h>
using namespace std;
int main() {
  long n, ma, mb, mc;
  cin >> n >> ma >> mb >> mc;
  long k = 0;
  for (long a = 0; a <= ma; a++)
    for (long b = 0; b <= mb; b++) {
      long c = 2 * n - a - 2 * b;
      if (c % 4 || c < 0 || c > 4 * mc)
        ;
      else
        k++;
    }
  cout << k << endl;
  return 0;
}
