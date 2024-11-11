#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x;
  cin >> n >> x;
  int distressed = 0;
  while (n--) {
    char c;
    int i;
    cin >> c >> i;
    if (c == '-') {
      if (i > x)
        distressed++;
      else
        x -= i;
    } else
      x += i;
  }
  cout << x << " " << distressed;
  return 0;
}
