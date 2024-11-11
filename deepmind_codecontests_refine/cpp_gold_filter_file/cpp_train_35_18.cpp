#include <bits/stdc++.h>
using namespace std;
bool isd(char first) { return '0' <= first && first <= '9'; }
int main(int argc, char **argv) {
  string s;
  cin >> s;
  int N = s.length();
  bool f = 0;
  int dd, mm, yy;
  int dom[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  map<string, int> freq;
  for (int i = (0); i < (N - 9); ++i) {
    string t = s.substr(i, 10);
    int m, d, second;
    string sm, sd, sy;
    sd = t.substr(0, 2);
    sm = t.substr(3, 2);
    sy = t.substr(6, 4);
    bool ok = 1;
    for (int j = (0); j < (sd.size()) && (ok); ++j) ok = isd(sd[j]);
    for (int j = (0); j < (sm.size()) && (ok); ++j) ok = isd(sm[j]);
    for (int j = (0); j < (sy.size()) && (ok); ++j) ok = isd(sy[j]);
    ok &= t[2] == '-' && t[5] == '-';
    if (!ok) continue;
    sscanf(sd.c_str(), "%d", &d);
    sscanf(sm.c_str(), "%d", &m);
    sscanf(sy.c_str(), "%d", &second);
    if (2012 < second && second < 2016 && 0 < m < 13) {
      if (0 < d && d <= dom[m]) {
        freq[t]++;
      }
    }
  }
  int res = -1;
  string sres;
  for (typeof(freq.begin()) t = freq.begin(); t != freq.end(); t++)
    if (res < t->second) {
      res = t->second;
      sres = t->first;
    } else if (res == t->second) {
      int yy, mm, dd;
      int second, m, d;
      sscanf(t->first.c_str(), "%d-%d-%d", &d, &m, &second);
      sscanf(sres.c_str(), "%d-%d-%d", &dd, &mm, &yy);
      bool rpl = 0;
      if (second > yy)
        rpl = 1;
      else if (second == yy && m > mm)
        rpl = 1;
      else if (second == yy && m == mm)
        rpl = d > dd;
      if (rpl) sres = t->first;
    }
  cout << sres;
  return 0;
}
