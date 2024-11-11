#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    long long n, steps = 0, i;
    cin >> n;
    if (n == 1)
      steps = 1;
    else {
      for (i = 1; i <= n / 2; i++) steps += (i * i) * 8;
    }
    cout << steps << endl;
  }
  return 0;
}
