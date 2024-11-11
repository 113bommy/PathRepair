#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int time;
  time = a * c;
  int l = 0, r = 1000;
  while (r > l + 1) {
    int x = (l + r) / 2;
    if (b * (x + c) >= time)
      r = x;
    else
      l = x;
  }
  cout << r;
}
