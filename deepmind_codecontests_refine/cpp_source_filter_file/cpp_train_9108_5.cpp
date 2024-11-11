#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  set<int> x, y;
  for (int i = 0; i < N; ++i) {
    int x_, y_;
    cin >> x_ >> y_;
    x.insert(x_);
    y.insert(y_);
  }
  double area = -1;
  auto itX = x.begin();
  auto itY = y.begin();
  if (x.size() > 1 && y.size() > 1) {
    int x1 = *itX++;
    int x2 = *itX;
    int y1 = *itY++;
    int y2 = *itY;
    area = (x2 - x1) * (y2 - y1);
  }
  cout << area;
  return 0;
}
