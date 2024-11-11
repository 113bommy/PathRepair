#include <bits/stdc++.h>
using namespace std;
const int c = 12;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int h, w, mid1, mid2;
    cin >> h >> w;
    int pic[h][w];
    mid1 = h >> 1;
    mid2 = mid1 + 1;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> pic[i][j];
      }
    }
    double cnt = 0;
    for (int j = 0; j < w; ++j) {
      cnt += sqrt(abs(pic[mid1][j] - pic[mid2][j]));
    }
    if (cnt >= w * 4) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << endl;
  }
}
