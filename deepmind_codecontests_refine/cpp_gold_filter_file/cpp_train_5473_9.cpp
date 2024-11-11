#include <bits/stdc++.h>
using namespace std;
bool can[210][60];
int n;
int cdir;
int main() {
  int n;
  int a, b;
  cin >> n >> a >> b;
  --a;
  --b;
  can[0][a] = true;
  string s;
  cin >> s;
  cin >> s;
  if (s == "head")
    cdir = -1;
  else if (s == "tail")
    cdir = 1;
  else
    exit(123);
  int cpos = b;
  cin >> s;
  for (int i = 0; i < ((int)s.length()); ++i) {
    bool moving = s[i] == '0';
    bool any = false;
    int ncpos;
    if (cpos + cdir >= n || cpos + cdir < 0) cdir *= -1;
    ncpos = cpos + cdir;
    for (int j = 0; j < (n); ++j) {
      if (!can[i][j]) continue;
      any = true;
      if (moving) {
        for (int t = j - 1; t <= j + 1; ++t) {
          if (t < 0 || t >= n || t == cpos || t == ncpos) continue;
          can[i + 1][t] = true;
        }
      } else {
        for (int t = 0; t < (n); ++t) {
          if (t == ncpos) continue;
          can[i + 1][t] = true;
        }
      }
    }
    if (!any) {
      if (!i) exit(321);
      cout << "Controller " << i;
      return 0;
    }
    cpos = ncpos;
  }
  cout << "Stowaway";
  return 0;
}
