#include <bits/stdc++.h>
using namespace std;
int main() {
  int dis = 0;
  long x, d;
  int n;
  cin >> n >> x;
  char a;
  while (n--) {
    cin >> a >> d;
    if (a == '+')
      x = x + d;
    else {
      if (d > x)
        dis++;
      else
        x = x - d;
    }
  }
  cout << x << " " << dis;
  return 0;
}
