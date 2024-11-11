#include <bits/stdc++.h>
using namespace std;
int main() {
  string compares[3];
  for (int i = 0; i < 3; i++) {
    cin >> compares[i];
  }
  string parts[3];
  for (int i = 0; i < 3; i++) {
    string cur = compares[i];
    char l = cur[0];
    char mid = cur[1];
    char r = cur[2];
    string part = "";
    if (mid == '<') {
      part += r;
      part += l;
    } else {
      part += l;
      part += r;
    }
    parts[i] = part;
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i != j) {
        int third = 3 - i - j;
        string fst = parts[i];
        string snd = parts[j];
        string thd = parts[third];
        if (fst[1] == snd[0]) {
          if (fst[0] == thd[0] && snd[1] == thd[1]) {
            cout << thd[1] << "" << fst[1] << "" << thd[0];
            return 0;
          }
        }
      }
    }
  }
  cout << "Impossible";
}
