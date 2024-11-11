#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n = 0, x = 0, y = 0;
  cin >> n >> x >> y;
  cout << (y * n) / 100 + ((y * n) % 100 != 0 ? x : 0) - x;
}
