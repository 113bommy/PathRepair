#include <bits/stdc++.h>
using namespace std;
int main() {
  int a = 0, g = 0;
  string s[3];
  char max[3], mini[3], ma[3];
  for (int i = 0; i < 3; i++) getline(cin, s[i]);
  for (int i = 0; i < 3; i++) {
    if (s[i][1] == 62) {
      max[i] = s[i][0];
      mini[i] = s[i][2];
    }
    if (s[i][1] == 60) {
      max[i] = s[i][2];
      mini[i] = s[i][0];
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = i + 1; j < 3; j++) {
      if (mini[i] == mini[j]) {
        ma[0] = mini[i];
        ma[1] = mini[3 - i - j];
        g = 1;
      }
      if (max[i] == max[j]) {
        ma[2] = max[i];
        a = 1;
      }
    }
  }
  if (a == 1 && g == 1)
    for (int i = 0; i < 3; i++) cout << ma[i];
  else
    cout << "Impossible";
}
