#include <bits/stdc++.h>
using namespace std;
string s1[40], s2[40];
map<string, int> msi;
map<string, string> mss;
bool cnt(string s) {
  if (s.size() == 1 && s[0] == 'a') return 1;
  if (s.size() == 1) return 0;
  string nn = "";
  nn += s[0];
  nn += s[1];
  if (msi.count(nn)) {
    nn = mss[nn];
    for (int i = 2; i < s.size(); ++i) nn += s[i];
    return cnt(nn);
  }
  return 0;
}
int main() {
  int n, q;
  while (cin >> n >> q) {
    for (int i = 0; i < q; ++i) {
      cin >> s1[i] >> s2[i];
      msi[s1[i]]++;
      mss[s1[i]] = s2[i];
    }
    int f = 0;
    if (n == 2) {
      string tem = "";
      for (int i = 0; i < 6; ++i) {
        tem += 'a' + i;
        for (int j = 0; j < 6; ++j) {
          tem += 'a' + j;
          if (msi.count(tem) && mss[tem] == "a") f++;
          tem.erase(tem.end() - 1);
        }
        tem.erase(tem.end() - 1);
      }
    }
    if (n == 3) {
      string tem = "";
      for (int i = 0; i < 6; ++i) {
        tem += 'a' + i;
        for (int j = 0; j < 6; ++j) {
          tem += 'a' + j;
          for (int k = 0; k < 6; ++k) {
            tem += 'a' + k;
            if (cnt(tem)) f++;
            tem.erase(tem.end() - 1);
          }
          tem.erase(tem.end() - 1);
        }
        tem.erase(tem.end() - 1);
      }
    }
    if (n == 4) {
      string tem = "";
      for (int i = 0; i < 6; ++i) {
        tem += 'a' + i;
        for (int j = 0; j < 6; ++j) {
          tem += 'a' + j;
          for (int k = 0; k < 6; ++k) {
            tem += 'a' + k;
            for (int a = 0; a < 6; ++a) {
              tem += 'a' + a;
              if (cnt(tem)) f++;
              tem.erase(tem.end() - 1);
            }
            tem.erase(tem.end() - 1);
          }
          tem.erase(tem.end() - 1);
        }
        tem.erase(tem.end() - 1);
      }
    }
    if (n == 5) {
      string tem = "";
      for (int i = 0; i < 6; ++i) {
        tem += 'a' + i;
        for (int j = 0; j < 6; ++j) {
          tem += 'a' + j;
          for (int k = 0; k < 6; ++k) {
            tem += 'a' + k;
            for (int a = 0; a < 6; ++a) {
              tem += 'a' + a;
              for (int b = 0; b < 6; ++b) {
                tem += 'a' + b;
                if (cnt(tem)) f++;
                tem.erase(tem.end() - 1);
              }
              tem.erase(tem.end() - 1);
            }
            tem.erase(tem.end() - 1);
          }
          tem.erase(tem.end() - 1);
        }
        tem.erase(tem.end() - 1);
      }
    }
    if (n == 6) {
      string tem = "";
      for (int i = 0; i < 6; ++i) {
        tem += 'a' + i;
        for (int j = 0; j < 6; ++j) {
          tem += 'a' + j;
          for (int k = 0; k < 6; ++k) {
            tem += 'a' + k;
            for (int a = 0; a < 6; ++a) {
              tem += 'a' + a;
              for (int b = 0; b < 6; ++b) {
                tem += 'a' + b;
                for (int c = 0; c < 6; ++c) {
                  tem += 'a' + c;
                  if (cnt(tem)) f++;
                  tem.erase(tem.end() - 1);
                }
                tem.erase(tem.end() - 1);
              }
              tem.erase(tem.end() - 1);
            }
            tem.erase(tem.end() - 1);
          }
          tem.erase(tem.end() - 1);
        }
        tem.erase(tem.end() - 1);
      }
    }
    cout << f << endl;
  }
}
