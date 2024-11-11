#include <bits/stdc++.h>
using namespace std;
bool sortFunction(int first, int second) { return first < second; }
int main() {
  string nodes[12] = {"C",  "C#", "D",  "D#", "E", "F",
                      "F#", "G",  "G#", "A",  "B", "H"};
  string a, b, c;
  int i, j = 0, arr[3];
  cin >> a >> b >> c;
  for (i = 0; i < 12; i++) {
    if (nodes[i] == a || nodes[i] == b || nodes[i] == c) {
      arr[j] = i;
      j++;
    }
  }
  sort(arr, arr + 3);
  if ((arr[0] + 4) % 12 == arr[1] && (arr[1] + 3) % 12 == arr[2]) {
    cout << "major";
  } else if ((arr[1] + 4) % 12 == arr[2] && (arr[2] + 3) % 12 == arr[3]) {
    cout << "major";
  } else if ((arr[2] + 4) % 12 == arr[0] && (arr[0] + 3) % 12 == arr[1]) {
    cout << "major";
  } else if ((arr[0] + 3) % 12 == arr[1] && (arr[1] + 4) % 12 == arr[2]) {
    cout << "minor";
  } else if ((arr[1] + 3) % 12 == arr[2] && (arr[2] + 4) % 12 == arr[3]) {
    cout << "minor";
  } else if ((arr[2] + 3) % 12 == arr[0] && (arr[0] + 4) % 12 == arr[1]) {
    cout << "minor";
  } else {
    cout << "strange";
  }
  return 0;
}
