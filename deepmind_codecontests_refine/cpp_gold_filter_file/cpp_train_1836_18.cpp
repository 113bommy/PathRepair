#include <bits/stdc++.h>
using namespace std;
string tone[12] = {"C",  "C#", "D",  "D#", "E", "F",
                   "F#", "G",  "G#", "A",  "B", "H"};
int main() {
  string in1, in2, in3;
  cin >> in1 >> in2 >> in3;
  int pos1, pos2, pos3;
  for (int i = 0; i < 12; i++) {
    if (tone[i] == in1)
      pos1 = i;
    else if (tone[i] == in2)
      pos2 = i;
    else if (tone[i] == in3)
      pos3 = i;
  }
  if ((pos2 - pos1 == 4) || (12 - pos1 + pos2 == 4)) {
    if ((pos3 - pos2 == 3) || (12 - pos2 + pos3 == 3)) {
      cout << "major";
      return 0;
    }
  }
  if ((pos3 - pos1 == 4) || (12 - pos1 + pos3 == 4)) {
    if ((pos2 - pos3 == 3) || (12 - pos3 + pos2 == 3)) {
      cout << "major";
      return 0;
    }
  }
  if ((pos3 - pos2 == 4) || (12 - pos2 + pos3 == 4)) {
    if ((pos1 - pos3 == 3) || (12 - pos3 + pos1 == 3)) {
      cout << "major";
      return 0;
    }
  }
  if ((pos1 - pos2 == 4) || (12 - pos2 + pos1 == 4)) {
    if ((pos3 - pos1 == 3) || (12 - pos1 + pos3 == 3)) {
      cout << "major";
      return 0;
    }
  }
  if ((pos1 - pos3 == 4) || (12 - pos3 + pos1 == 4)) {
    if ((pos2 - pos1 == 3) || (12 - pos1 + pos2 == 3)) {
      cout << "major";
      return 0;
    }
  }
  if ((pos2 - pos3 == 4) || (12 - pos3 + pos2 == 4)) {
    if ((pos1 - pos2 == 3) || (12 - pos2 + pos1 == 3)) {
      cout << "major";
      return 0;
    }
  }
  if ((pos2 - pos1 == 3) || (12 - pos1 + pos2 == 3)) {
    if ((pos3 - pos2 == 4) || (12 - pos2 + pos3 == 4)) {
      cout << "minor";
      return 0;
    }
  }
  if ((pos3 - pos1 == 3) || (12 - pos1 + pos3 == 3)) {
    if ((pos2 - pos3 == 4) || (12 - pos3 + pos1 == 4)) {
      cout << "minor";
      return 0;
    }
  }
  if ((pos3 - pos2 == 3) || (12 - pos2 + pos3 == 3)) {
    if ((pos1 - pos3 == 4) || (12 - pos3 + pos1 == 4)) {
      cout << "minor";
      return 0;
    }
  }
  if ((pos1 - pos2 == 3) || ((12 - pos2 + pos1) == 3)) {
    if ((pos3 - pos1 == 4) || (12 - pos1 + pos3 == 4)) {
      cout << "minor";
      return 0;
    }
  }
  if ((pos1 - pos3 == 3) || (12 - pos3 + pos1 == 3)) {
    if ((pos2 - pos1 == 4) || (12 - pos1 + pos2 == 4)) {
      cout << "minor";
      return 0;
    }
  }
  if ((pos2 - pos3 == 3) || (12 - pos3 + pos2 == 3)) {
    if ((pos1 - pos2 == 4) || (12 - pos2 + pos1 == 4)) {
      cout << "minor";
      return 0;
    }
  }
  cout << "strange";
  return 0;
}
