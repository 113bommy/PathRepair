#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W, A, B, C;
  cin >> H >> W;
  A = (H % 3 && W % 3) ? min(H, W) : 0;
  int w = W / 3, h = H / 3;
  B = min((H - H / 2) * (W - w) - w * H, (w + 1) * H - H / 2 * (W - w - 1));
  C = min((W - W / 2) * (H - h) - h * W, (h + 1) * W - W / 2 * (H - h - 1));
  cout << min({A, B, C}) << endl;
}