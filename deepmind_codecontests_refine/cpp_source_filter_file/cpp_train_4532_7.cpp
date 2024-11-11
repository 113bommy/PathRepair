#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  size_t r;
  size_t c;
  size_t n;
  size_t k;
  cin >> r >> c >> n >> k;
  static const size_t MapSize = 10;
  bool map[MapSize][MapSize]{};
  for (size_t violistIndex = 0; violistIndex < n; ++violistIndex) {
    size_t x;
    size_t y;
    cin >> x >> y;
    map[x - 1][y - 1] = true;
  }
  size_t numberOfRectangles{};
  for (size_t topLeftCornerX = 0; topLeftCornerX < r; ++topLeftCornerX) {
    for (size_t topLeftCornerY = 0; topLeftCornerY < c; ++topLeftCornerY) {
      for (size_t bottomRightCornerX = topLeftCornerX; bottomRightCornerX < r;
           ++bottomRightCornerX) {
        for (size_t bottomRightCornerY = topLeftCornerX; bottomRightCornerY < c;
             ++bottomRightCornerY) {
          size_t numberOfViolists{};
          for (size_t x = topLeftCornerX; x <= bottomRightCornerX; ++x) {
            for (size_t y = topLeftCornerY; y <= bottomRightCornerY; ++y) {
              if (map[x][y]) {
                ++numberOfViolists;
              }
            }
          }
          if (numberOfViolists >= k) {
            ++numberOfRectangles;
          }
        }
      }
    }
  }
  cout << numberOfRectangles << endl;
}
