#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, nr = 0;
  cin >> n;
  char c;
  for (int i = 1; i <= n; ++i) {
    cin >> c;
    if (c == '+')
      nr++;
    else {
      if (nr != 0) nr--;
    }
  }
  cin >> nr;
}
