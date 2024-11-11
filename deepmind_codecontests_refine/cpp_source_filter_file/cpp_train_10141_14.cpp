#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int maxval = 0;
  int loc = 1;
  vector<bool> taken(s.size(), false);
  taken[0] = true;
  int ind = 0;
  if (s[0] == '1') {
    int i = 0;
    while (s[i] == '1' && i + 1 < s.size()) {
      taken[i + 1] = true;
      i++;
    }
  } else {
    int i = 0;
    while (s[i] == '0' && i + 1 < s.size()) {
      taken[i + 1] = true;
      i++;
    }
  }
  if (s[s.size() - 1] == '0') {
    int i = s.size() - 1;
    while (s[i] == '0' && i >= 0) {
      taken[i] = true;
      i--;
    }
  } else {
    int i = s.size() - 1;
    taken[s.size() - 1] = true;
    while (s[i] == '1' && i >= 0) {
      taken[i] = true;
      i--;
    }
  }
  while (ind < s.size()) {
    if (!taken[ind]) {
      loc++;
      if (s[ind] == '1') {
        taken[ind] = true;
        while (s[ind] == '1' && ind + 1 < s.size()) {
          taken[ind + 1] = true;
          ind++;
        }
      } else {
        taken[ind] = true;
        while (s[ind] == '0' && ind + 1 < s.size()) {
          taken[ind + 1] = true;
          ind++;
        }
      }
    }
    ind++;
  }
  maxval = max(loc, maxval);
  loc = 1;
  for (int i = 0; i < taken.size(); i++) taken[i] = false;
  taken[1] = true;
  ind = 1;
  if (s[1] == '1') {
    int i = 1;
    while (s[i] == '1' && i + 1 < s.size()) {
      taken[i + 1] = true;
      i++;
    }
  } else {
    int i = 1;
    while (s[i] == '0' && i + 1 < s.size()) {
      taken[i + 1] = true;
      i++;
    }
  }
  if (s[s.size() - 1] == '0' && s[0] == '0') {
    int i = s.size() - 1;
    while (s[i] == '0' && i >= 0) {
      taken[i] = true;
      i--;
    }
  } else if (s[s.size() - 1] == '1' && s[0] == '0') {
    int i = s.size() - 1;
    taken[s.size() - 1] = true;
    while (s[i] == '1' && i - 1 >= 0) {
      taken[i - 1] = true;
      i--;
    }
  } else
    taken[0] = true;
  while (ind < s.size()) {
    if (!taken[ind]) {
      loc++;
      if (s[ind] == '1') {
        taken[ind] = true;
        while (s[ind] == '1' && ind + 1 < s.size()) {
          taken[ind + 1] = true;
          ind++;
        }
      } else {
        taken[ind] = true;
        while (s[ind] == '0' && ind + 1 < s.size()) {
          taken[ind + 1] = true;
          ind++;
        }
      }
    }
    ind++;
  }
  maxval = max(loc, maxval);
  cout << maxval << endl;
}
