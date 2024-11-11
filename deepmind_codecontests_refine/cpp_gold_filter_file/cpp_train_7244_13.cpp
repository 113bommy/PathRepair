#include <bits/stdc++.h>
using namespace std;
const int N = 255;
int T, a[N];
int main() {
  ios::sync_with_stdio(false);
  cin >> T;
  int tmp;
  while (T--) {
    double mean = 0, var = 0;
    for (int i = 1; i <= 250; i++) cin >> a[i], mean += a[i];
    mean /= 250;
    for (int i = 1; i <= 250; i++) var += (a[i] - mean) * (a[i] - mean);
    var /= 250;
    double dev = sqrt(var);
    if (*max_element(a + 1, a + 251) / dev > 1.9)
      puts("poisson");
    else
      puts("uniform");
  }
  return 0;
}
