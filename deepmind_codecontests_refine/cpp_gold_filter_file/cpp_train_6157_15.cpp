#include <bits/stdc++.h>
#pragma optimize(3)
using namespace std;
const long long LLMAX = 2e18;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;
template <class T>
inline void read(T &DataIn) {
  DataIn = 0;
  T Flag = 0;
  char c = getchar();
  while (!isdigit(c)) {
    Flag |= c == '-';
    c = getchar();
  }
  while (isdigit(c)) {
    DataIn = DataIn * 10 + c - '0';
    c = getchar();
  }
  DataIn = Flag ? -DataIn : DataIn;
}
template <class T>
inline void write(T DataOut, char EndChar = '\n') {
  T lenth = 0, number[30];
  if (DataOut == 0) {
    putchar(48);
    return;
  }
  while (DataOut > 0) {
    number[++lenth] = DataOut % 10;
    DataOut /= 10;
  }
  for (int i = lenth; i >= 1; i--) putchar(number[i] + 48);
  putchar(EndChar);
}
priority_queue<int, vector<int>, less<int> > qd;
priority_queue<int, vector<int>, greater<int> > qu;
int main(void) {
  FILE *fin = NULL, *fout = NULL;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long sx, sy, ex, ey, cntx = 0, cnty = 0;
  cin >> sx >> sy >> ex >> ey;
  long long n;
  string s;
  cin >> n >> s;
  long long l = 0, r = 0x3f3f3f3f, ans = LLMAX;
  for (int i = 0; i < n; i++)
    if (s[i] == 'U')
      cnty++;
    else if (s[i] == 'D')
      cnty--;
    else if (s[i] == 'L')
      cntx--;
    else if (s[i] == 'R')
      cntx++;
  while (l <= r) {
    long long mid = (l + r) >> 1, flag = 0;
    long long nx = sx + mid * cntx, ny = sy + mid * cnty;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'U')
        ny++;
      else if (s[i] == 'D')
        ny--;
      else if (s[i] == 'L')
        nx--;
      else if (s[i] == 'R')
        nx++;
      long long dis = abs(ex - nx) + abs(ey - ny);
      if (dis <= n * mid + i + 1) {
        flag = i + 1;
        break;
      }
    }
    if (flag)
      ans = mid * n + flag, r = mid - 1;
    else
      l = mid + 1;
  }
  if (ans == LLMAX) ans = -1;
  cout << ans << endl;
  return 0;
}
