#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, covered = 0;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    covered += (abs(x - y) + 1);
  }
  covered %= k;
  cout << (covered == 0 ? 0 : abs(covered - k));
}
