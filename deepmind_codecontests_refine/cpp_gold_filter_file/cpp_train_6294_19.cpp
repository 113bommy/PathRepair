#include <bits/stdc++.h>
using namespace std;
int main() {
  string s[3];
  map<char, int> m;
  for (int i = 0; i < 3; i++) {
    cin >> s[i];
    if (s[i][1] == '>') {
      m[s[i][0]]++;
    } else {
      m[s[i][2]]++;
    }
  }
  if (m.size() != 2) {
    cout << "Impossible" << endl;
  } else {
    if (m['A'] == 0) {
      cout << "A";
    } else if (m['B'] == 0) {
      cout << "B";
    } else if (m['C'] == 0) {
      cout << "C";
    }
    if (m['A'] == 1) {
      cout << "A";
    } else if (m['B'] == 1) {
      cout << "B";
    } else if (m['C'] == 1) {
      cout << "C";
    }
    if (m['A'] == 2) {
      cout << "A";
    } else if (m['B'] == 2) {
      cout << "B";
    } else if (m['C'] == 2) {
      cout << "C";
    }
  }
  return 0;
}
