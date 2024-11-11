#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
int n, imax, jmax;
string s;
int mxL;
char A[110][110];
int t;
void draw(int di, int dj, int hight, int width) {
  A[di][dj] = '+';
  A[di][dj + 1] = '-';
  A[di][dj + width - 1] = '+';
  A[di][dj + width - 2] = '-';
  A[di + hight - 1][dj] = '+';
  A[di + hight - 1][dj + 1] = '-';
  A[di + hight - 1][dj + width - 1] = '+';
  A[di + hight - 1][dj + width - 2] = '-';
  for (int i = di + 1; i < di + hight - 1; ++i) {
    A[i][dj] = '|';
    A[i][dj + width - 1] = '|';
  }
  if (di + hight - 1 > imax) imax = di + hight - 1;
  if (dj + width - 1 > jmax) jmax = dj + width - 1;
}
int mxLevel(int i) {
  int level = 0;
  int open = 0;
  for (; i < n; ++i) {
    if (s[i] == ']') {
      open--;
    }
    if (s[i] == '[') {
      open++;
      level = max(level, open);
    }
  }
  return level;
}
pair<int, int> fun(int di, int dj, int level) {
  int hight = 0;
  int width = 0;
  int inLev = level;
  for (; t < n; ++t) {
    if (s[t] == '[') {
      t++;
      pair<int, int> f;
      if (width == 0) {
        f = fun(di + 1, dj + 1, ++inLev);
        hight += f.second;
      } else {
        f = fun(di + 1, dj + width + 1, inLev);
        hight = f.second;
      }
      width += f.first;
      continue;
    }
    if (s[t] == ']') break;
  }
  if (width != 0 && hight != 0) {
    width += 2;
    hight += 2;
  } else {
    width = 5;
    if (level < mxL) {
      hight = 3 + (mxL - level) * 2;
    } else
      hight = 3;
  }
  if (di != -1 && dj != -1) draw(di, dj, hight, width);
  return make_pair(width, hight);
}
inline void out() {
  for (int i = 0; i <= imax; ++i) {
    for (int j = 0; j <= jmax; ++j) {
      if (A[i][j] == '\0')
        cout << " ";
      else
        cout << A[i][j];
    }
    cout << endl;
  }
}
int main() {
  cin >> n >> s;
  mxL = mxLevel(0);
  fun(-1, -1, 0);
  out();
  return 0;
}
