#include <bits/stdc++.h>
using namespace std;
int main(void) {
  long long H, W;
  cin >> H >> W;
  cout << (H == 1 || W == 1 ? 0 : (H * W + 1) / 2) << endl;
  return 0;
}
