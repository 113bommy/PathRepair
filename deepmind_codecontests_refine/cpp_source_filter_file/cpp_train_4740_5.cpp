#include <bits/stdc++.h>
using namespace std;
map<string, pair<int, int> > mapping;
bool match(string res, string guess) {
  int bull = 0, cow = 0, pos = 0;
  for (int i = 0; i < (int)(guess).size(); i++) {
    pos = res.find(guess[i]);
    if (pos != -1) {
      if (pos == i)
        bull++;
      else
        cow++;
    }
  }
  return (bull == mapping[guess].first) && (cow == mapping[guess].second);
}
int main() {
  int n;
  cin >> n;
  vector<string> guess(n);
  int bull, cow;
  for (int i = 0; i < n; i++) {
    cin >> guess[i] >> bull >> cow;
    mapping[guess[i]] = make_pair(bull, cow);
  }
  string res(4, '0'), sol;
  bool once = false;
  for (int a = 0; a < 9; a++) {
    for (int b = 0; b < 9; b++) {
      if (b == a) continue;
      for (int c = 0; c < 9; c++) {
        if (c == a || c == b) continue;
        for (int d = 0; d < 9; d++) {
          if (d == a || d == b || d == c) continue;
          res[0] = '0' + a;
          res[1] = '0' + b;
          res[2] = '0' + c;
          res[3] = '0' + d;
          for (int i = 0; i < (int)(guess).size(); i++) {
            if (!match(res, guess[i])) break;
            if (i == (int)(guess).size() - 1) {
              sol = res;
              if (!once)
                once = true;
              else {
                cout << "Need more data\n";
                return 0;
              }
            }
          }
        }
      }
    }
  }
  if (once)
    cout << sol << endl;
  else
    cout << "Incorrect data\n";
  return 0;
}
