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
long long ans, x, y;
string s, t;
int main(void) {
  FILE *fin = NULL, *fout = NULL;
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, k;
  cin >> n >> k >> s >> t;
  for (long long i = 0, flag = 0; i < n; i++) {
    if (s[i] == t[i] && !flag)
      ans++;
    else {
      flag = 1;
      if (t[i] == 'a' && s[i] == 'a') x = 2 * x - 1, y = 2 * y;
      if (t[i] == 'a' && s[i] == 'b') x = 2 * x - 1, y = 2 * y - 1;
      if (t[i] == 'b' && s[i] == 'a') x = 2 * x, y = 2 * y;
      if (t[i] == 'b' && s[i] == 'b') x = 2 * x, y = 2 * y - 1;
      if (x == 0 && y == 0) x = 1, y = 1;
      x = max(k, x), y = max(k, y);
      ans += min(k, x + y);
    }
  }
  cout << ans << endl;
  return 0;
}
