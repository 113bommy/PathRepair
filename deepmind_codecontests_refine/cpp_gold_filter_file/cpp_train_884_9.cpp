#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, b, c, cnt = 0;
  cin >> n >> a >> b >> c;
  if (b - c < a && n >= b) {
    cnt = (n - b) / (b - c) + 1;
    n -= (b - c) * cnt;
  }
  cnt = cnt + n / a;
  cout << cnt << endl;
  return 0;
}
