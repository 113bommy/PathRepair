#include <bits/stdc++.h>
using namespace std;
int getDirByXY(const int& x, const int& y, const int& sx, const int& sy) {
  if (x - sx < 0) {
    if (y - sy < 0) {
      return 0;
    } else if (y - sy > 0) {
      return 5;
    } else {
      return 3;
    }
  } else if (x - sx > 0) {
    if (y - sy < 0) {
      return 2;
    } else if (y - sy > 0) {
      return 7;
    } else {
      return 4;
    }
  } else {
    if (y - sy < 0) {
      return 1;
    } else {
      return 6;
    }
  }
  return 0;
}
int main() {
  long long num_students, sx, sy;
  cin >> num_students >> sx >> sy;
  long long dir[8];
  for (int i = 0; i < 8; i++) {
    dir[i] = 0;
  }
  long long next_x, next_y;
  for (int i = 0; i < num_students; i++) {
    cin >> next_x >> next_y;
    dir[getDirByXY(next_x, next_y, sx, sy)]++;
  }
  dir[1] += dir[0] + dir[2];
  dir[3] += dir[0] + dir[5];
  dir[4] += dir[2] + dir[7];
  dir[6] += dir[5] + dir[7];
  long long max_dir = 0;
  for (int i = 0; i < 8; i++) {
    if (dir[i] > dir[max_dir]) {
      max_dir = i;
    }
  }
  long long ans_x, ans_y;
  switch (max_dir) {
    case 0:
      ans_x = sx - 1;
      ans_y = sy - 1;
      break;
    case 1:
      ans_x = sx;
      ans_y = sy - 1;
      break;
    case 2:
      ans_x = sx + 1;
      ans_y = sy - 1;
      break;
    case 3:
      ans_x = sx - 1;
      ans_y = sy;
      break;
    case 4:
      ans_x = sx + 1;
      ans_y = sy;
      break;
    case 5:
      ans_x = sx - 1;
      ans_y = sy + 1;
      break;
    case 6:
      ans_x = sx;
      ans_y = sy + 1;
      break;
    case 7:
      ans_x = sx + 1;
      ans_y = sy + 1;
      break;
  }
  cout << dir[max_dir] << endl;
  cout << ans_x << " " << ans_y << endl;
  return 0;
}
