#include <bits/stdc++.h>
using namespace std;
int f(string c) {
  string arr[12] = {"C",  "C#", "D",  "D#", "E", "F",
                    "F#", "G",  "G#", "A",  "B", "H"};
  for (int i = 0; i < 12; i++) {
    if (arr[i] == c) return i;
  }
}
int main() {
  string c1, c2, c3;
  cin >> c1 >> c2 >> c3;
  int pos1, pos2, pos3;
  int dif12, dif23;
  pos1 = f(c1);
  pos2 = f(c2);
  pos3 = f(c3);
  string arr[3];
  if (pos1 < pos2 and pos1 < pos3) {
    arr[0] = c1;
    if (pos2 < pos3) {
      arr[1] = c2;
      arr[2] = c3;
    } else {
      arr[1] = c3;
      arr[2] = c2;
    }
  }
  if (pos2 < pos1 and pos2 < pos3) {
    arr[0] = c2;
    if (pos1 < pos3) {
      arr[1] = c1;
      arr[2] = c3;
    } else {
      arr[1] = c3;
      arr[2] = c1;
    }
  }
  if (pos3 < pos2 and pos3 < pos1) {
    arr[0] = c3;
    if (pos1 < pos2) {
      arr[1] = c1;
      arr[2] = c2;
    } else {
      arr[1] = c2;
      arr[2] = c1;
    }
  }
  if ((f(arr[1]) - f(arr[0]) == 4) and (f(arr[2]) - f(arr[1]) == 3)) {
    cout << "major" << endl;
    return 0;
  }
  if (12 - f(arr[2]) + f(arr[0]) == 4 and (f(arr[1]) - f(arr[0]) == 3)) {
    cout << "major" << endl;
    return 0;
  }
  if ((f(arr[2]) - f(arr[1]) == 4) and 12 - f(arr[2]) + f(arr[0]) == 3) {
    cout << "major" << endl;
    return 0;
  }
  if ((f(arr[1]) - f(arr[0]) == 3) and (f(arr[2]) - f(arr[1]) == 4)) {
    cout << "minor" << endl;
    return 0;
  }
  if (12 - f(arr[2]) + f(arr[0]) == 3 and (f(arr[1]) - f(arr[0]) == 4)) {
    cout << "minor" << endl;
    return 0;
  }
  if ((f(arr[2]) - f(arr[1]) == 3) and 12 - f(arr[2]) + f(arr[0]) == 4) {
    cout << "minor" << endl;
    return 0;
  }
  cout << "strange" << endl;
  return 0;
}
