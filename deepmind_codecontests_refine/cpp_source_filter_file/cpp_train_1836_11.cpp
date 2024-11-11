#include <bits/stdc++.h>
using namespace std;
int i, j, p[24];
string k,
    n[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H"};
int main() {
  for (; i++ < 3;) {
    cin >> k;
    for (j = 0; j < 12; j++) {
      if (k == n[j]) {
        p[j]++;
        p[j + 12]++;
      }
    }
  }
  for (i = 0; i < 12; i++) {
    if (p[i] & p[i + 4] & p[i + 7]) {
      cout << "major";
      return 0;
    }
    if (p[1] & p[i + 3] & p[i + 7]) {
      cout << "minor";
      return 0;
    }
  }
  cout << "strange";
}
