#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, sum, res, i;
  cin >> n;
  sum = 0;
  for (i = 0; i < n; i++) {
    cin >> x;
    sum += x;
  }
  res = 0;
  for (i = 1; i <= 5; i++) {
    if (((sum + i) % (n + 1)) == 0) {
      res++;
    }
  }
  cout << res << endl;
}
