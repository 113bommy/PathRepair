#include <bits/stdc++.h>
using namespace std;
bool isuc(char c) { return c >= 'A' && c <= 'Z'; }
bool islc(char c) { return c >= 'a' && c <= 'z'; }
bool isd(char c) { return c >= '0' && c <= '9'; }
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    string str;
    cin >> str;
    bool uc = 0, lc = 0, dg = 0;
    int cntuc = 0, cntlc = 0, cntdg = 0;
    for (int i = 0; i < str.length(); i++) {
      if (str[i] >= 'A' && str[i] <= 'Z') {
        uc = true;
        cntuc++;
      }
      if (str[i] >= 'a' && str[i] <= 'z') {
        cntlc++;
        lc = true;
      }
      if (str[i] >= '0' && str[i] <= '9') {
        cntdg++;
        dg = true;
      }
    }
    int val = uc + lc + dg;
    if (val == 3)
      cout << str << endl;
    else if (val == 2) {
      for (int i = 0; i < str.length(); i++) {
        if (!uc) {
          if (islc(str[i]) && cntlc > 1) {
            str[i] = 'A';
            break;
          } else if (isd(str[i]) && cntdg > 1) {
            str[i] = 'A';
            break;
          }
        }
        if (!lc) {
          if (isuc(str[i]) && cntuc > 1) {
            str[i] = 'a';
            break;
          } else if (isd(str[i]) && cntdg > 1) {
            str[i] = 'a';
            break;
          }
        }
        if (!dg) {
          if (islc(str[i]) && cntlc > 1) {
            str[i] = '1';
            break;
          } else if (isuc(str[i]) && cntuc > 1) {
            str[i] = 'A';
            break;
          }
        }
      }
      cout << str << endl;
    } else {
      if (uc) {
        str[0] = 'a';
        str[1] = '1';
      } else if (lc) {
        str[0] = 'A';
        str[1] = '1';
      } else {
        str[0] = 'A';
        str[1] = 'a';
      }
      cout << str << endl;
    }
  }
  return 0;
}
