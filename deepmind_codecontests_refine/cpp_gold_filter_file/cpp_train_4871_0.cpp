#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t H, W;
  cin >> H >> W;
  if ((H == 1) or (W == 1)) {
    cout << 1;
  } else {
    cout << (H * W + 1) / 2;
  }
}