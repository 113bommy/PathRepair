#include <bits/stdc++.h>
using namespace std;
string getBack(string s, int k) {
  int p = s.size();
  for (int i = 0; i < k; i++) {
    int ap = s.substr(0, p).find_last_of("a");
    int ep = s.substr(0, p).find_last_of("e");
    int ip = s.substr(0, p).find_last_of("i");
    int op = s.substr(0, p).find_last_of("o");
    int up = s.substr(0, p).find_last_of("u");
    p = max(ap, max(ep, max(ip, max(op, up))));
    if (p == -1) {
      return "";
    }
  }
  return s.substr(p, s.size());
}
string s[10001];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < 4 * n; i++) {
    string ss;
    cin >> ss;
    s[i] = getBack(ss, k);
  }
  vector<int> code;
  for (int i = 0; i < n; i++) {
    int sp = 4 * i;
    bool ab[4] = {false};
    for (int j = 0; j < 4; j++) {
      ab[j] = (s[sp] == s[sp + j] && s[sp + j] != "" && s[sp] != "");
    }
    if (ab[0] == true && ab[1] == true && ab[2] == true && ab[3] == true) {
      code.push_back(0);
    } else {
      if (ab[0] == true && ab[1] == false && ab[2] == false && ab[3] == true ||
          (ab[0] == false && ab[1] == true && ab[2] == false &&
           ab[3] == true) &&
              s[sp + 1] == s[sp + 2]) {
        code.push_back(1);
      } else {
        if (ab[0] == true && ab[1] == true && ab[2] == false &&
                ab[3] == false ||
            (ab[0] == false && ab[1] == false && ab[2] == true &&
             ab[3] == true) &&
                s[sp + 2] == s[sp + 3]) {
          code.push_back(2);
        } else {
          if (ab[0] == true && ab[1] == false && ab[2] == true &&
                  ab[3] == false ||
              (ab[0] == false && ab[1] == true && ab[2] == false &&
               ab[3] == true) &&
                  s[sp + 1] == s[sp + 3]) {
            code.push_back(3);
          } else {
            code.push_back(-1);
          }
        }
      }
    }
  }
  sort(code.begin(), code.end());
  for (int i = 0; i < code.size() - 1; i++) {
    if (code[i] != 0 && code[i + 1] != code[i]) {
      cout << "NO";
      return 0;
    }
  }
  if (code[code.size() - 1] == 0) {
    cout << "aaaa";
  } else {
    if (code[code.size() - 1] == 1) {
      cout << "abba";
    } else {
      if (code[code.size() - 1] == 2) {
        cout << "aabb";
      } else {
        if (code[code.size() - 1] == 3) {
          cout << "abab";
        } else {
          cout << "NO";
        }
      }
    }
  }
  return 0;
}
