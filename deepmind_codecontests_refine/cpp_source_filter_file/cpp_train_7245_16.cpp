#include <bits/stdc++.h>
using namespace std;
vector<string> lines;
int getFreq(string s, char temp) {
  int freq = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == temp) {
      freq++;
    }
  }
  return freq;
}
int main() {
  int temp = 10;
  string x;
  while (temp--) {
    cin >> x;
    lines.push_back(x);
  }
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 5; j++) {
      x = lines[i].substr(j, 5);
      if (getFreq(x, 'X') == 4 && getFreq(x, '.') == 1) {
        cout << "YES";
        return 0;
      }
    }
  }
  x = "";
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j <= 5; j++) {
      x = "";
      for (int k = j; k < j + 5; k++) {
        x += lines[k][i];
      }
      if (getFreq(x, 'X') == 4 && getFreq(x, '.') == 1) {
        cout << "YES";
        return 0;
      }
    }
  }
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      x = "";
      temp = 0;
      while (temp < 5) {
        if (i + temp >= 0 && i + temp < 10 && j + temp >= 0 && j + temp < 10) {
          x += lines[i + temp][j + temp];
        }
        temp++;
      }
      if (getFreq(x, 'X') == 4 && getFreq(x, '.') == 1) {
        cout << "YES";
        return 0;
      }
      x = "";
      temp = 0;
      while (temp < 5) {
        if (i + temp >= 0 && i + temp < 10 && j - temp >= 0 && j - temp < 10) {
          x += lines[i + temp][j - temp];
        }
        temp++;
      }
      if (getFreq(x, 'X') == 4 && getFreq(x, '.') == 1) {
        cout << "YES";
        return 0;
      }
    }
  }
  cout << "NO";
}
