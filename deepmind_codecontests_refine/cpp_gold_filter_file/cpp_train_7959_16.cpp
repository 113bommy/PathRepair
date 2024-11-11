#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
int N, M, C, H;
int main(void) {
  cin.sync_with_stdio(0);
  cout.sync_with_stdio(0);
  cin >> N >> M >> C;
  int minX = INF, minY = INF, maxX = -INF, maxY = -INF;
  int minDist = INF, idx = -1;
  for (int i = 0; i < C; i++) {
    int X, Y;
    cin >> X >> Y;
    int __X = X + Y, __Y = X - Y;
    minX = min(__X, minX);
    maxX = max(__X, maxX);
    minY = min(__Y, minY);
    maxY = max(__Y, maxY);
  }
  cin >> H;
  for (int i = 0; i < H; i++) {
    int X, Y;
    cin >> X >> Y;
    int __X = X + Y, __Y = X - Y;
    int maxDist = max(max(abs(minX - __X), abs(maxX - __X)),
                      max(abs(minY - __Y), abs(maxY - __Y)));
    if (maxDist < minDist) {
      minDist = maxDist;
      idx = i;
    }
  }
  cout << minDist << endl << idx + 1 << endl;
  return 0;
}
