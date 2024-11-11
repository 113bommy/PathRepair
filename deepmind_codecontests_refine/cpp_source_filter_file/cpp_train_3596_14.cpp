#include <bits/stdc++.h>
using namespace std;
int n, x, a, res = 0;
char t;
int main() {
  cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    cin >> t >> a;
    if (t == '+')
      x += a;
    else {
      if (x >= a)
        x -= a;
      else
        res++;
    }
  }
  cout << x << " " << res;
  return 0;
}
