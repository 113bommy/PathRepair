#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x, d, sad = 0;
  char c;
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> c >> d;
    if (c == '+')
      x += d;
    else {
      if (d > x)
        sad++;
      else
        x -= d;
    }
  }
  cout << x << ' ' << sad << endl;
  return 0;
}
