#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c;
  int res = 0;
  cin >> n >> a >> b >> c;
  for (int i = 0; i <= a; i += 2)
    for (int j = 0; j <= b; j += 1) {
      int x = n - 0.5 * i - 2 * j;
      if ((x >= 0) && (x <= c)) res++;
    }
  cout << res;
}
