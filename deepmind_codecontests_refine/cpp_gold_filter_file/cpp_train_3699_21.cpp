#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int n;
  cin >> n;
  cin >> s;
  if (n == 1) {
    cout << s << endl;
    return 0;
  }
  string ret = "";
  int color[3] = {0, 0, 0};
  for (int i = 0; i < n; i++) {
    if (s[i] == 'R')
      color[0]++;
    else if (s[i] == 'G')
      color[1]++;
    else if (s[i] == 'B')
      color[2]++;
  }
  if (color[0] > 0 && color[1] > 0 && color[2] > 0 ||
      (color[0] > 1 && color[1] > 1) || (color[0] > 1 && color[2] > 1) ||
      (color[1] > 1 && color[2] > 1)) {
    cout << "BGR" << endl;
  } else if ((color[0] > 1 && color[1] == 1)) {
    cout << "BG" << endl;
  } else if (color[0] > 1 && color[2] == 1) {
    cout << "BG" << endl;
  } else if (color[1] > 1 && color[0] == 1) {
    cout << "BR" << endl;
  } else if (color[1] > 1 && color[2] == 1) {
    cout << "BR" << endl;
  } else if (color[2] > 1 && color[0] == 1) {
    cout << "GR" << endl;
  } else if (color[2] > 1 && color[1] == 1) {
    cout << "GR" << endl;
  } else if ((color[0] == 1 && color[1] == 1) ||
             (color[2] > 1 && color[1] == 0 && color[0] == 0)) {
    cout << "B" << endl;
  } else if ((color[0] == 1 && color[2] == 1) ||
             (color[1] > 1 && color[2] == 0 && color[0] == 0)) {
    cout << "G" << endl;
  } else if ((color[1] == 1 && color[2] == 1) ||
             (color[0] > 1 && color[1] == 0 && color[2] == 0)) {
    cout << "R" << endl;
  }
}
