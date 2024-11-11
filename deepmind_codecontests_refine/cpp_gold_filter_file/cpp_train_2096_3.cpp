#include <bits/stdc++.h>
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
    putchar(EndChar);
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
  int t;
  cin >> t;
  while (t--) {
    int ang, n = -1;
    cin >> ang;
    if (ang <= 90) {
      ang *= 2;
      for (int i = 1; i <= ang; i++)
        if (ang % i == 0 && 360 % (ang / i) == 0 && 360 * i / ang >= 3) {
          n = 360 * i / ang;
          break;
        }
    } else {
      ang = 2 * (180 - ang);
      for (int i = 2; i <= ang; i++)
        if (ang % i == 0 && 360 % (ang / i) == 0 && 360 * i / ang >= 3) {
          n = 360 * i / ang;
          break;
        }
    }
    cout << n << endl;
  }
  return 0;
}
