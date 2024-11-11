#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k = 0;
  cin >> n;
  while (n--) {
    int x, y;
    cin >> x >> y;
    if ((x + 2) <= y)
      k++;
    else
      k = k;
  }
  cout << k;
}
