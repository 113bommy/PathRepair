#include <bits/stdc++.h>
using namespace std;
int main() {
  string arr[3];
  int val[3], diff[3];
  cin >> arr[0] >> arr[1] >> arr[2];
  for (int r = 0; r < 3; r++) {
    if (arr[r] == "C") {
      val[r] = 1;
    } else if (arr[r] == "C#") {
      val[r] = 2;
    } else if (arr[r] == "D") {
      val[r] = 3;
    } else if (arr[r] == "D#") {
      val[r] = 4;
    } else if (arr[r] == "E") {
      val[r] = 5;
    } else if (arr[r] == "F") {
      val[r] = 6;
    } else if (arr[r] == "F#") {
      val[r] = 7;
    } else if (arr[r] == "G") {
      val[r] = 8;
    } else if (arr[r] == "G#") {
      val[r] = 9;
    } else if (arr[r] == "A") {
      val[r] = 10;
    } else if (arr[r] == "B") {
      val[r] = 11;
    } else if (arr[r] == "H") {
      val[r] = 12;
    }
  }
  for (int r = 0; r < 3; r++) {
    if (val[1] >= val[0]) {
      diff[0] = val[1] - val[0];
    } else {
      diff[0] = 12 - abs(val[1] - val[0]);
    }
    if (val[2] >= val[1]) {
      diff[1] = val[2] - val[1];
    } else {
      diff[1] = 12 - abs(val[2] - val[1]);
    }
    if (val[2] >= val[0]) {
      diff[2] = val[2] - val[0];
    } else {
      diff[2] = 12 - abs(val[2] - val[0]);
    }
    if ((diff[0] == 4) && (diff[1] == 3) && (diff[2] == 7)) {
      cout << "major";
      return 0;
    } else if ((diff[1] == 4) && (diff[0] == 3) && (diff[2] == 7)) {
      cout << "minor";
      return 0;
    }
    if (r < 2) {
      swap(val[r], val[r + 1]);
    }
  }
  for (int r = 0; r < 3; r++) {
    if (val[1] >= val[0]) {
      diff[0] = val[1] - val[0];
    } else {
      diff[0] = 12 - abs(val[1] - val[0]);
    }
    if (val[2] >= val[1]) {
      diff[1] = val[2] - val[1];
    } else {
      diff[1] = 12 - abs(val[2] - val[1]);
    }
    if (val[2] >= val[0]) {
      diff[2] = val[2] - val[0];
    } else {
      diff[2] = 12 - abs(val[2] - val[0]);
    }
    if ((diff[0] == 4) && (diff[1] == 3) && (diff[2] == 7)) {
      cout << "major";
      return 0;
    } else if ((diff[1] == 4) && (diff[0] == 3) && (diff[2] == 7)) {
      cout << "minor";
      return 0;
    }
    if (r < 2) {
      swap(val[r], val[r + 1]);
    }
  }
  swap(arr[0], arr[1]);
  if (val[1] >= val[0]) {
    diff[0] = val[1] - val[0];
  } else {
    diff[0] = 12 - abs(val[1] - val[0]);
  }
  if (val[2] >= val[1]) {
    diff[1] = val[2] - val[1];
  } else {
    diff[1] = 12 - abs(val[2] - val[1]);
  }
  if (val[2] >= val[0]) {
    diff[2] = val[2] - val[0];
  } else {
    diff[2] = 12 - abs(val[2] - val[0]);
  }
  if ((diff[0] == 4) && (diff[1] == 3) && (diff[2] == 7)) {
    cout << "major";
    return 0;
  } else if ((diff[1] == 4) && (diff[0] == 3) && (diff[2] == 7)) {
    cout << "minor";
    return 0;
  }
  cout << "strange";
  return 0;
}
