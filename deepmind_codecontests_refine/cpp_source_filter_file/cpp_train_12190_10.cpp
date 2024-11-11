#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  long long ans = 0;
  while (m--) {
    long long x, d;
    cin >> x >> d;
    ans += x * n;
    if (d > 0)
      ans += d * (n - 1) * n / 2;
    else if (d < 0) {
      if (n % 2 == 0)
        ans += d * (n * n / 4);
      else
        ans += d * ((n * n - 1) / 4);
    }
  }
  cout << setiosflags(ios::fixed) << setprecision(15) << (double)ans / n
       << "\n";
}
