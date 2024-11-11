#include <bits/stdc++.h>
using namespace std;
int main(void) {
  string str;
  int arr[3];
  for (int i = 0; i < 3; i++) {
    cin >> str;
    if (str == "C")
      arr[i] = 1;
    else if (str == "C#")
      arr[i] = 2;
    else if (str == "D")
      arr[i] = 3;
    else if (str == "D#")
      arr[i] = 4;
    else if (str == "E")
      arr[i] = 5;
    else if (str == "F")
      arr[i] = 6;
    else if (str == "F#")
      arr[i] = 7;
    else if (str == "G")
      arr[i] = 8;
    else if (str == "G#")
      arr[i] = 9;
    else if (str == "A")
      arr[i] = 10;
    else if (str == "B")
      arr[i] = 11;
    else if (str == "H")
      arr[i] = 12;
  }
  for (int i = 0; i < 6; i++) {
    if (i == 1) swap(arr[1], arr[2]);
    if (i == 2) swap(arr[0], arr[2]);
    if (i == 3) swap(arr[1], arr[2]);
    if (i == 4) swap(arr[0], arr[2]);
    if (i == 5) swap(arr[1], arr[2]);
    if ((((arr[0] + 4) % 12) == arr[1]) && (((arr[1] + 3) % 12) == arr[2])) {
      cout << "major";
      exit(0);
    } else if ((((arr[0] + 3) % 12) == arr[1]) &&
               (((arr[1] + 4) % 12) == arr[2])) {
      cout << "minor";
      exit(0);
    }
  }
  cout << "strange";
}
