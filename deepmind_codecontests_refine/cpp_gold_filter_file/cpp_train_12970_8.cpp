#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int twos = 0;
  int ones = 0;
  int sum = 0;
  int zeros = 0;
  for (int i = 0; i < s.size(); i++) {
    int cur = s[i] - '0';
    if (cur % 3 == 2) twos++;
    if (cur % 3 == 1) ones++;
    if (cur == 0) zeros++;
    sum += cur;
  }
  if (sum % 3 == 0) {
    cout << s << endl;
    return 0;
  }
  if (sum % 3 == 2) {
    string pos1 = "";
    string pos2 = "";
    if (twos > 0) {
      for (int i = s.size() - 1; i >= 0; i--) {
        int cur = s[i] - '0';
        if (cur % 3 == 2) {
          pos1 = s.substr(0, i) + (s.substr(i + 1));
          break;
        }
      }
      int x = 0;
      while (x < pos1.size() && pos1[x] == '0' && pos1 != "0") {
        x++;
      }
      if (x == pos1.size()) {
        pos1 = "";
      } else {
        pos1 = pos1.substr(x);
      }
    }
    if (ones < 2) {
      pos2 = "";
    } else {
      int ind1 = -1;
      int ind2 = -1;
      for (int i = s.size() - 1; i >= 0; i--) {
        int cur = s[i] - '0';
        if (cur % 3 == 1) {
          if (ind2 == -1)
            ind2 = i;
          else {
            if (ind1 == -1) {
              ind1 = i;
              break;
            }
          }
        }
      }
      for (int i = 0; i < s.size(); i++) {
        if (i != ind1 && i != ind2) pos2 += s[i];
      }
      int x = 0;
      while (x < pos2.size() && pos2[x] == '0' && pos2 != "0") {
        x++;
      }
      if (x == pos2.size()) {
        pos2 = "";
      } else {
        pos2 = pos2.substr(x);
      }
    }
    if (pos2.size() >= pos1.size() && pos2 != "" && pos2 != "") {
      cout << pos2 << endl;
      return 0;
    }
    if (pos1.size() >= pos2.size() && pos1 != "" && pos1 != "") {
      cout << pos1 << endl;
      return 0;
    }
    if (zeros > 0) {
      cout << 0 << endl;
      return 0;
    }
    cout << -1;
    return 0;
  }
  if (sum % 3 == 1) {
    string pos1 = "";
    string pos2 = "";
    if (ones > 0) {
      for (int i = s.size() - 1; i >= 0; i--) {
        int cur = s[i] - '0';
        if (cur % 3 == 1) {
          pos1 = s.substr(0, i) + (s.substr(i + 1));
          break;
        }
      }
      int x = 0;
      while (x < pos1.size() && pos1[x] == '0' && pos1 != "0") {
        x++;
      }
      if (x == pos1.size()) {
        pos1 = "";
      } else {
        pos1 = pos1.substr(x);
      }
    }
    if (twos < 2) {
      pos2 = "";
    } else {
      int ind1 = -1;
      int ind2 = -1;
      for (int i = s.size() - 1; i >= 0; i--) {
        int cur = s[i] - '0';
        if (cur % 3 == 2) {
          if (ind2 == -1)
            ind2 = i;
          else {
            if (ind1 == -1) {
              ind1 = i;
              break;
            }
          }
        }
      }
      for (int i = 0; i < s.size(); i++) {
        if (i != ind1 && i != ind2) pos2 += s[i];
      }
      int x = 0;
      while (x < pos2.size() && pos2[x] == '0' && pos2 != "0") {
        x++;
      }
      if (x == pos2.size()) {
        pos2 = "";
      } else {
        pos2 = pos2.substr(x);
      }
    }
    if (pos1.size() >= pos2.size() && pos1 != "" && pos1 != "") {
      cout << pos1 << endl;
      return 0;
    }
    if (pos2.size() >= pos1.size() && pos2 != "" && pos2 != "") {
      cout << pos2 << endl;
      return 0;
    }
    if (zeros > 0) {
      cout << 0 << endl;
      return 0;
    }
    cout << -1;
    return 0;
  }
}
