#include <bits/stdc++.h>
using namespace std;
const int M = 6e5;
int n, d, f[M];
int main() {
  cin >> n >> d;
  f[0] = 1;
  int now = 0, times = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    for (int j = M - 1; j >= 0; j--) f[j] |= f[j - x];
  }
  while (1) {
    int old = now;
    for (int i = 1; i <= d; i++)
      if (f[i + old]) now = old + i;
    if (now == old) break;
    times++;
  }
  cout << now << " " << times << endl;
  return 0;
}
