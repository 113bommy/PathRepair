#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n;
  cin >> m >> n;
  if (m <= n && m <= 16 && n <= 16) {
    int sq = (m * n) / 2;
    cout << sq;
  }
}
