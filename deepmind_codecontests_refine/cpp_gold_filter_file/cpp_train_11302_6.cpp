#include <bits/stdc++.h>
using namespace std;
char s[10];
int main() {
  long long n, x, y, nowx, nowy;
  cin >> n >> x >> y;
  long long north, south, east, west, en, es, wn, ws;
  north = south = east = west = en = es = wn = ws = 2e10 + 5;
  int northjudge, southjudge, eastjudge, westjudge, enjudge, esjudge, wnjudge,
      wsjudge;
  for (int i = 1; i <= n; i++) {
    scanf("%s %I64d %I64d", s, &nowx, &nowy);
    if (s[0] == 'B') {
      if (nowy < y && nowx == x) {
        if (y - nowy < west) {
          westjudge = 1;
          west = y - nowy;
        }
      }
      if (nowy > y && nowx == x) {
        if (-y + nowy < east) {
          eastjudge = 1;
          east = -y + nowy;
        }
      }
      if (nowx > x && nowy == y) {
        if (nowx - x < south) {
          south = nowx - x;
          southjudge = 1;
        }
      }
      if (nowx < x && nowy == y) {
        if (-nowx + x < north) {
          north = -nowx + x;
          northjudge = 1;
        }
      }
      if (nowx + nowy == x + y) {
        if (nowx > x) {
          if (nowx - x + y - nowy < ws) {
            ws = nowx - x + y - nowy;
            wsjudge = 1;
          }
        } else {
          if (-nowx + x - y + nowy < en) {
            en = -nowx + x - y + nowy;
            enjudge = 1;
          }
        }
      }
      if (nowx - x == nowy - y) {
        if (nowx > x) {
          if (nowx - x - y + nowy < es) {
            es = nowx - x - y + nowy;
            esjudge = 1;
          }
        } else {
          if (-nowx + x + y - nowy < wn) {
            wn = -nowx + x + y - nowy;
            wnjudge = 1;
          }
        }
      }
    }
    if (s[0] == 'R') {
      if (nowy < y && nowx == x) {
        if (y - nowy < west) {
          westjudge = 2;
          west = y - nowy;
        }
      }
      if (nowy > y && nowx == x) {
        if (-y + nowy < east) {
          eastjudge = 2;
          east = -y + nowy;
        }
      }
      if (nowx > x && nowy == y) {
        if (nowx - x < south) {
          south = nowx - x;
          southjudge = 2;
        }
      }
      if (nowx < x && nowy == y) {
        if (-nowx + x < north) {
          north = -nowx + x;
          northjudge = 2;
        }
      }
      if (nowx + nowy == x + y) {
        if (nowx > x) {
          if (nowx - x + y - nowy < ws) {
            ws = nowx - x + y - nowy;
            wsjudge = 2;
          }
        } else {
          if (-nowx + x - y + nowy < en) {
            en = -nowx + x - y + nowy;
            enjudge = 2;
          }
        }
      }
      if (nowx - x == nowy - y) {
        if (nowx > x) {
          if (nowx - x - y + nowy < es) {
            es = nowx - x - y + nowy;
            esjudge = 2;
          }
        } else {
          if (-nowx + x + y - nowy < wn) {
            wn = -nowx + x + y - nowy;
            wnjudge = 2;
          }
        }
      }
    }
    if (s[0] == 'Q') {
      if (nowy < y && nowx == x) {
        if (y - nowy < west) {
          westjudge = 3;
          west = y - nowy;
        }
      }
      if (nowy > y && nowx == x) {
        if (-y + nowy < east) {
          eastjudge = 3;
          east = -y + nowy;
        }
      }
      if (nowx > x && nowy == y) {
        if (nowx - x < south) {
          south = nowx - x;
          southjudge = 3;
        }
      }
      if (nowx < x && nowy == y) {
        if (-nowx + x < north) {
          north = -nowx + x;
          northjudge = 3;
        }
      }
      if (nowx + nowy == x + y) {
        if (nowx > x) {
          if (nowx - x + y - nowy < ws) {
            ws = nowx - x + y - nowy;
            wsjudge = 3;
          }
        } else {
          if (-nowx + x - y + nowy < en) {
            en = -nowx + x - y + nowy;
            enjudge = 3;
          }
        }
      }
      if (nowx - x == nowy - y) {
        if (nowx > x) {
          if (nowx - x - y + nowy < es) {
            es = nowx - x - y + nowy;
            esjudge = 3;
          }
        } else {
          if (-nowx + x + y - nowy < wn) {
            wn = -nowx + x + y - nowy;
            wnjudge = 3;
          }
        }
      }
    }
  }
  int flag = 0;
  if (eastjudge != 1 && east != 2e10 + 5) flag = 1;
  if (westjudge != 1 && west != 2e10 + 5) flag = 1;
  if (northjudge != 1 && north != 2e10 + 5) flag = 1;
  if (southjudge != 1 && south != 2e10 + 5) flag = 1;
  if (enjudge != 2 && en != 2e10 + 5) flag = 1;
  if (esjudge != 2 && es != 2e10 + 5) flag = 1;
  if (wnjudge != 2 && wn != 2e10 + 5) flag = 1;
  if (wsjudge != 2 && ws != 2e10 + 5) flag = 1;
  if (flag)
    puts("YES");
  else
    puts("NO");
  return 0;
}
