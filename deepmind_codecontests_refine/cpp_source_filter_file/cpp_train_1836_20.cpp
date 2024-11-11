#include <bits/stdc++.h>
using namespace std;
int search(char* arr[12], char x[2]) {
  int i = 0;
  for (; i < 12; i++) {
    if (arr[i][0] == x[0])
      if (arr[i][1] == x[1]) return i;
  }
  return -1;
}
int main() {
  char* arr[] = {"A",  "B", "H", "C",  "C#", "D",
                 "D#", "E", "F", "F#", "G",  "G#"};
  char x[3], y[3], z[3];
  cin >> x;
  cin >> y;
  cin >> z;
  int sx = search(arr, x);
  int sy = search(arr, y);
  int sz = search(arr, z);
  int xy, xz, yz, yx, zx, zy;
  xy = (sy - sx) > 0 ? (sy - sx) : (sy + 12 - sx);
  yx = (sx - sy) > 0 ? (sx - sy) : (sx + 12 - sy);
  xz = (sz - sx) > 0 ? (sz - sx) : (sz + 12 - sx);
  zx = (sx - sz) > 0 ? (sx - sz) : (sx + 12 - sz);
  yz = (sz - sy) > 0 ? (sz - sy) : (sz + 12 - sy);
  zy = (sy - sz) > 0 ? (sy - sz) : (sy + 12 - sz);
  if (xy == 3) {
    if (zx == 4) {
      cout << "major";
      return 0;
    } else if (yz == 4) {
      cout << "minor";
      return 0;
    }
  }
  if (yx == 3) {
    if (zy == 4) {
      cout << "major";
      return 0;
    } else if (xz == 4) {
      cout << "minor";
      return 0;
    }
  }
  if (xz == 3) {
    if (xy == 4) {
      cout << "major";
      return 0;
    } else if (zy == 4) {
      cout << "minor";
      return 0;
    }
  }
  if (zx == 3) {
    if (yz == 4) {
      cout << "major";
      return 0;
    } else if (xy == 4) {
      cout << "minor";
      return 0;
    }
  }
  if (yz == 3) {
    if (xy == 4) {
      cout << "major";
      return 0;
    } else if (zx == 4) {
      cout << "minor";
      return 0;
    }
  }
  if (zy == 3) {
    if (xz == 4) {
      cout << "major";
      return 0;
    } else if (yz == 4) {
      cout << "minor";
      return 0;
    }
  }
  cout << "strange";
}
