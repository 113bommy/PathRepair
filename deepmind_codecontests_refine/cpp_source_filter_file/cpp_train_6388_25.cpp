#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, x;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> x;
    printf("%d", x < 3 ? 0 : x - 2);
  }
  return 0;
}
