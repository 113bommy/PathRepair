#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long n, r, s;
  int x;
  cin >> x;
  while (x--) {
    s = 0L;
    cin >> n >> r;
    if (n < r)
      s = (n * (n - 1) / 2) + 1;
    else
      s = (r * (r - 1) / 2) + 1;
    cout << s << endl;
  }
}
