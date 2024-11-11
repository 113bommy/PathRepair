#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<string> v;
int dp[26][26][26][26];
int valid(int x, int y, int x1, int y1) {
  bool vc = 0;
  int c = 0;
  for (int i = min(x, x1); i <= max(x1, x); i++) {
    for (int j = min(y, y1); j <= max(y1, y); j++) {
      if (v[i][j] == '1') {
        vc = 1;
        break;
      }
      c++;
    }
  }
  if (vc) return 0;
  int dil = ((abs(x - x1) + 1) + (abs(y - y1) + 1)) * 2;
  return dil;
}
int mxperimeter(int x, int y, int x1, int y1) {
  if (x < 0 || y < 0 || x >= n || y >= m || x1 < 0 || y1 < 0 || x1 >= n ||
      y1 >= m)
    return 0;
  int &mx = dp[x][y][x1][y1];
  if (mx != -1) {
    return mx;
  }
  mx = valid(x, y, x1, y1);
  int ch1 = 0, ch2 = 0, ch3 = 0, ch4 = 0, ch5 = 0, ch6 = 0, ch7 = 0, ch8 = 0;
  ch1 = mxperimeter(x + 1, y, x1, y1);
  ch2 = mxperimeter(x - 1, y, x1, y1);
  ch3 = mxperimeter(x, y + 1, x1, y1);
  ch4 = mxperimeter(x, y - 1, x1, y1);
  ch5 = mxperimeter(x, y, x1 + 1, y1);
  ch6 = mxperimeter(x, y, x1 - 1, y1);
  ch7 = mxperimeter(x, y, x1, y1 + 1);
  ch8 = mxperimeter(x, y, x1, y1 - 1);
  int mx1 = max(max(ch1, ch2), max(ch3, ch4));
  int mx2 = max(max(ch5, ch6), max(ch7, ch8));
  int mx3 = max(mx1, mx2);
  mx = max(mx, mx3);
  return mx;
}
bool valid(string s) {
  int f = 0;
  string s1 = "", s2 = "";
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '@') {
      f++;
      continue;
    }
    if (f == 0) {
      s1 += s[i];
    } else {
      s2 += s[i];
    }
  }
  if (f == 1 && s1.size() > 0 && s2.size() > 0) return 1;
  return 0;
}
int main() {
  string s;
  cin >> s;
  string ret = "";
  vector<string> v;
  for (int i = int(0); i < int(s.size()); i++) {
    ret += s[i];
    if (valid(ret)) {
      v.push_back(ret);
      ret = "";
    } else {
      if (i == s.size() - 1) {
        for (int j = 0; j < ret.size(); j++) {
          if (ret[j] == '@') {
            cout << "No solution";
            exit(0);
          }
        }
        if (v.size() == 0) {
          cout << "No solution";
          exit(0);
        }
      }
    }
  }
  for (int i = int(0); i < int(v.size()); i++) {
    if (i == v.size() - 1) {
      cout << v[i] << ret;
      break;
    }
    cout << v[i] << ",";
  }
  return 0;
}
