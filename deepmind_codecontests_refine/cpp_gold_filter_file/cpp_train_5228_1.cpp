#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cin >> x;
  int y, z;
  while (x--) {
    cin >> y >> z;
    int candies = (y / z) * z;
    candies = candies + min(z / 2, y - candies);
    cout << candies << '\n';
  }
}
