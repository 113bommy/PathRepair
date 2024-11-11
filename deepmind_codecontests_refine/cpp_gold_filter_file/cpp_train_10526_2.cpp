#include <bits/stdc++.h>
using namespace std;
const int XY_MAX = 1e9;
int N;
int rotation_status;
void rotate(int &x, int &y) {
  if (rotation_status == 1) {
    x = XY_MAX - x;
    y = XY_MAX - y;
  }
  if (rotation_status == 2) {
    swap(x, y);
  }
}
int query(int x, int y) {
  rotate(x, y);
  cout << x << ' ' << y << endl;
  string result;
  cin >> result;
  return result == "black" ? 1 : 0;
}
void answer(int x1, int y1, int x2, int y2) {
  rotate(x1, y1);
  rotate(x2, y2);
  cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
  exit(0);
}
void solve1(int start) {
  int low = 0, high = XY_MAX / 2;
  for (int iter = 3; iter < N; iter++) {
    int mid = (low + high) / 2;
    if (query(mid, mid) == start)
      high = mid;
    else
      low = mid;
  }
  int mid = (low + high) / 2;
  answer(2 * mid, 0, 0, 2 * mid);
}
void solve2(int start) {
  int low = 0, high = XY_MAX;
  for (int iter = 3; iter < N; iter++) {
    int mid = (low + high) / 2;
    if (query(XY_MAX, mid) == start)
      high = mid;
    else
      low = mid;
  }
  int mid = (low + high) / 2;
  answer(0, mid, XY_MAX, mid);
}
int main() {
  cin >> N;
  rotation_status = 0;
  int top_left = query(0, XY_MAX);
  if (N == 1) {
    answer(XY_MAX, 0, XY_MAX, XY_MAX);
  }
  int top_right = query(XY_MAX, XY_MAX);
  if (N == 2) {
    if (top_left == top_right)
      answer(0, 0, XY_MAX, 0);
    else
      answer(XY_MAX / 2, 0, XY_MAX / 2, XY_MAX);
  }
  int bottom_right = query(XY_MAX, 0);
  if (top_left == top_right && top_right == bottom_right) {
    solve1(top_left);
  } else if (top_left == bottom_right) {
    rotation_status = 1;
    solve1(top_left);
  } else if (top_left == top_right) {
    solve2(top_right);
  } else if (top_right == bottom_right) {
    rotation_status = 2;
    solve2(top_right);
  }
  assert(false);
}
