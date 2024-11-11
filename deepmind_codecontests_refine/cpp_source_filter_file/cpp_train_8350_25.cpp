#include <bits/stdc++.h>
using namespace std;
int main() {
  int h, m, M, H, K, f;
  cin >> f;
  while (f--) {
    cin >> h >> m;
    M = 60 - m;
    H = 24 - (h + 1);
    K = H * 60;
    cout << M + K;
  }
}
