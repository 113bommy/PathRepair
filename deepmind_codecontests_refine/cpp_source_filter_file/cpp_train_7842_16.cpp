#include <bits/stdc++.h>
using namespace std;
int main() {
  long long k, b, n, t;
  cin >> k >> b >> n >> t;
  if (t == 1) {
    cout << "0\n";
    return 0;
  }
  long long now = 1, sec = 0;
  while (true) {
    if (now > t) {
      sec--;
      break;
    } else if (now == t)
      break;
    now = now * k + b;
    sec++;
  }
  if (sec > n)
    cout << "0\n";
  else
    cout << n - sec << "\n";
}
