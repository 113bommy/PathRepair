#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, n, w;
  cin >> k >> n >> w;
  int cost = -(n - k * (1 + w) * w / 2);
  if (cost < 0) {
    cout << abs(cost);
  } else {
    cout << 0;
  }
}
